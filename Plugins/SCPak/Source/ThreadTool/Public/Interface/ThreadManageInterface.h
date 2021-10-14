#pragma once

#include "CoreMinimal.h"
#include "Interface/ProxyInterface.h"
#include "Containers/Queue.h"
#include "Runnable/ThreadRunnableProxy.h"
#include "Core/ThreadMacro.h"
#include "Abandonable/Abandonable.h"
#include "Coroutines/Coroutines.h"
#include "Engine/StreamableManager.h"

class IThreadContainer
{
public:
	IThreadContainer()
	{}
	~IThreadContainer()
	{}

protected:
	FCriticalSection Mutex;
};

class IThreadProxyContainer :public TArray<TSharedPtr<IThreadProxy>>, public IThreadContainer
{
protected:
	typedef TArray<TSharedPtr<IThreadProxy>> TProxyArray;
public:
	IThreadProxyContainer &operator<<(const TSharedPtr<IThreadProxy>& ThreadProxy)
	{
		MUTEX_LOCK;
		//由线程池创建线程并管理
		ThreadProxy->CreateSafeThread();
		this->Add(ThreadProxy);

		return *this;
	}

	FThreadHandle operator>>(const FSimpleDelegate & ThreadProxy)
	{
		FThreadHandle ThreadHandle = nullptr;
		{
			MUTEX_LOCK;
			for (auto &Tmp:*this)
			{
				if (Tmp->IsSuspend() && !Tmp->GetThreadDelegate().IsBound())
				{
					Tmp->GetThreadDelegate() = ThreadProxy;
					ThreadHandle = Tmp->GetThreadHandle();
					Tmp->WakeupThread();
					break;
				}
			}
		}
		if (!ThreadHandle.IsValid())
		{
			TSharedPtr<IThreadProxy> Proxy = MakeShareable(new FThreadRunnable(true));
			Proxy->GetThreadDelegate() = ThreadProxy;
			*this << Proxy;

			ThreadHandle = Proxy->GetThreadHandle();
		}
		return ThreadHandle;
	}

	FThreadHandle operator<<(const FSimpleDelegate& ThreadProxy)
	{
		FThreadHandle ThreadHandle = nullptr;
		{
			MUTEX_LOCK;
			for (auto& Tmp : *this)
			{
				if (Tmp->IsSuspend() && !Tmp->GetThreadDelegate().IsBound())
				{
					Tmp->GetThreadDelegate() = ThreadProxy;
					ThreadHandle = Tmp->GetThreadHandle();
					break;
				}
			}
		}
		if (!ThreadHandle.IsValid())
		{
			ThreadHandle = *this << MakeShareable(new FThreadRunnable) << ThreadProxy;
		}
		return ThreadHandle;
	}

	TSharedPtr<IThreadProxy> operator>>(const FThreadHandle& Handle)
	{
		MUTEX_LOCK;
		for (auto& Tmp : *this)
		{
			if (Tmp->GetThreadHandle() == Handle)
			{
				return Tmp;
			}
		}

		return NULL;
	}
};

class IThreadTaskContainer :public TQueue<FSimpleDelegate>, public TArray<TSharedPtr<IThreadProxy>>, public IThreadContainer
{
protected:
	typedef TQueue<FSimpleDelegate> TProxyArray;
	typedef TArray<TSharedPtr<IThreadProxy>> TEventQueue;
public:
	void operator<<(const FSimpleDelegate& ThreadProxy)
	{
		MUTEX_LOCK;
		this->Enqueue(ThreadProxy);
	}
	
	bool operator<<=(FSimpleDelegate& ThreadProxy)
	{
		MUTEX_LOCK;
		return this->Dequeue(ThreadProxy);
	}

	IThreadTaskContainer& operator<<(const TSharedPtr<IThreadProxy>& ThreadProxy)
	{
		MUTEX_LOCK;
		this->Add(ThreadProxy);
		ThreadProxy->CreateSafeThread();
		return *this;
	}

	void operator>>(const FSimpleDelegate& ThreadProxy)
	{
		bool bSuccessful = false;
		{
			MUTEX_LOCK;
			for (auto& Tmp : *this)
			{
				if (Tmp->IsSuspend() && !Tmp->GetThreadDelegate().IsBound())
				{
					Tmp->GetThreadDelegate() = ThreadProxy;
					Tmp->WakeupThread();

					bSuccessful = true;
					break;
				}
			}
		}
		if (!bSuccessful)
		{
			*this << ThreadProxy;
		}
	}
};

class IAbandonableContainer :public IThreadContainer
{
protected:

	//<<代表同步
	void operator<<(const FSimpleDelegate& ThreadDelegate)
	{
		FAsyncTask<FAbandonable>* Abandonable = new FAsyncTask<FAbandonable>(ThreadDelegate);
		Abandonable->StartBackgroundTask();
		Abandonable->EnsureCompletion();
		delete Abandonable;
	}

	//>>代表异步
	void operator>>(const FSimpleDelegate& ThreadDelegate)
	{
		(new FAutoDeleteAsyncTask<FAbandonable>(ThreadDelegate))->StartBackgroundTask();
	}
};

//协程
class ICoroutinesContainer
{
public:
	ICoroutinesContainer() :TmpTotalTime(0.f) {}

	virtual ~ICoroutinesContainer() { ICoroutinesObject::Array.Empty(); }

	ICoroutinesContainer& operator<<(float TotalTime)
	{
		TmpTotalTime = TotalTime;
		return*this;
	}

	ICoroutinesContainer& operator<<(const FSimpleDelegate& ThreadDelegate)
	{
		ICoroutinesObject::Array.Add(MakeShareable(new FCoroutinesObject(TmpTotalTime, ThreadDelegate)));
		return*this;
	}
	
	FCoroutinesHandle operator>>(const FSimpleDelegate& ThreadDelegate)
	{
		ICoroutinesObject::Array.Add(MakeShareable(new FCoroutinesObject(ThreadDelegate)));
		return ICoroutinesObject::Array[ICoroutinesObject::Array.Num() - 1];
	}

	void operator<<=(float Time)
	{
		TArray<TSharedPtr<ICoroutinesObject>> RemoveObject;
		for (int32 i = 0; i < ICoroutinesObject::Array.Num(); i++)
		{
			FCoroutinesRequest Request(Time);
			ICoroutinesObject::Array[i]->Update(Request);
			if (Request.bCompleteRequest)
			{
				RemoveObject.Add(ICoroutinesObject::Array[i]);
			}
		}

		for (auto &RemoveInstance : RemoveObject)
		{
			ICoroutinesObject::Array.Remove(RemoveInstance);
		}
	}

private:
	float TmpTotalTime;
};

class IGraphContainer :public IThreadContainer
{
protected:
	//呼叫主线程
	FGraphEventRef operator<<(const FSimpleDelegate& ThreadDelegate)
	{
		MUTEX_LOCK;
		return FSimpleDelegateGraphTask::CreateAndDispatchWhenReady(
			ThreadDelegate,
			TStatId(),
			nullptr,
			ENamedThreads::GameThread
		);
	}
	//呼叫其他线程
	FGraphEventRef operator>>(const FSimpleDelegate& ThreadDelegate)
	{
		MUTEX_LOCK;
		return FSimpleDelegateGraphTask::CreateAndDispatchWhenReady(
			ThreadDelegate,
			TStatId(),
			nullptr,
			ENamedThreads::AnyThread
		);
	}
};

class IStreamableContainer
{
public:
	virtual ~IStreamableContainer() {}

	//储存路径
	IStreamableContainer& operator>>(const TArray<FSoftObjectPath>& InObjectPath)
	{
		SetObjectPath(InObjectPath);
		return *this;
	}

	//异步加载
	TSharedPtr<struct FStreamableHandle> operator>>(const FSimpleDelegate& ThreadDelegate)
	{
		return GetStreamableManager()->RequestAsyncLoad(GetObjectPath(), ThreadDelegate);
	}

	//同步加载
	TSharedPtr<struct FStreamableHandle> operator<<(const TArray<FSoftObjectPath>& InObjectPath)
	{
		return GetStreamableManager()->RequestSyncLoad(InObjectPath);
	}
protected:
	virtual void SetObjectPath(const TArray<FSoftObjectPath>& InObjectPath) = 0;
	virtual TArray<FSoftObjectPath>& GetObjectPath() = 0;
	virtual FStreamableManager* GetStreamableManager() = 0;
};