#include "ThreadManage.h"

TSharedPtr<FThreadManage> FThreadManage::ThreadManage = nullptr;

TSharedRef<FThreadManage> FThreadManage::Get()
{
	if (!ThreadManage.IsValid())
	{
		ThreadManage = MakeShareable(new FThreadManage);
	}
	return ThreadManage.ToSharedRef();
}

void FThreadManage::Destroy()
{
	if (ThreadManage.IsValid())
	{
		ThreadManage = nullptr;
	}
}

void FThreadManage::Tick(float DeltaTime)
{
	//任务队列Tick管理
	ThreadTaskManage.Tick(DeltaTime);
	//协程Tick管理
	CoroutinesManage.Tick(DeltaTime);
}

TStatId FThreadManage::GetStatId() const
{
	return TStatId();
}

FThreadTaskManage::~FThreadTaskManage()
{
	for (auto& Tmp : *this)
	{
		Tmp->WaitAndCompleted();
	}
	//析构会自动清除
	//((TQueue<FSimpleDelegate>*)this)->Empty();
	//((TArray<TSharedPtr<IThreadProxy>>*)this)->Empty();
}

FThreadTaskManage::FThreadTaskManage()
{
	Init(CPUThreadNumber);
}

void FThreadTaskManage::Init(int32 ThreadNum)
{
	for (int32 i = 0; i < ThreadNum; i++)
	{
		*this << MakeShareable(new FThreadRunnable);
	}
	FPlatformProcess::Sleep(0.1f);
}

void FThreadTaskManage::Tick(float DeltaTime)
{
	TSharedPtr<IThreadProxy> ThreadProxy = nullptr;
	{
		MUTEX_LOCK;
		for (auto& Tmp : *this)
		{
			if (Tmp->IsSuspend())
			{
				ThreadProxy = Tmp;
				break;
			}
		}
	}

	if (ThreadProxy.IsValid())
	{
		if (!((TEventQueue*)this)->IsEmpty())
		{
			FSimpleDelegate SimpleDelegate;
			if (*this <<= SimpleDelegate)
			{
				MUTEX_LOCK;
				ThreadProxy->GetThreadDelegate() = SimpleDelegate;
				ThreadProxy->WakeupThread();
			}
		}
	}
}

FThreadProxyManage::FThreadProxyManage()
{
	
}

FThreadProxyManage::~FThreadProxyManage()
{
	for (auto& Tmp : *this)
	{
		Tmp->WaitAndCompleted();
	}
	//析构会自动清除
	//this->empty();
}

bool FThreadProxyManage::Join(FThreadHandle Handle)
{
	TSharedPtr<IThreadProxy> ThreadProxy = *this >> Handle;
	if (ThreadProxy.IsValid())
	{
		ThreadProxy->BlockingAndCompletion();
		return true;
	}

	return false;
}

bool FThreadProxyManage::Detach(FThreadHandle Handle)
{
	TSharedPtr<IThreadProxy> ThreadProxy = *this >> Handle;
	if (ThreadProxy.IsValid())
	{
		ThreadProxy->WakeupThread();
		return true;
	}
	return false;
}

EThreadState FThreadProxyManage::Joinable(FThreadHandle Handle)
{
	TSharedPtr<IThreadProxy> ThreadProxy = *this >> Handle;

	if (ThreadProxy.IsValid())
	{
		if (ThreadProxy->IsSuspend())
		{
			return EThreadState::LEISURELY;
		}
		else
		{
			return EThreadState::WORKING;
		}
	}
	return EThreadState::ERROR;
}

FCoroutinesManage::FCoroutinesManage()
	:FThreadTemplateBase<ICoroutinesContainer, FCoroutinesHandle>()
{

}

void FCoroutinesManage::Tick(float DeltaTime)
{
	*this <<= DeltaTime;
}

void FThreadGraphManage::Wait(const FGraphEventRef& EventRef)
{
	FTaskGraphInterface::Get().WaitUntilTaskCompletes(EventRef);
}

void FThreadGraphManage::Wait(const FGraphEventArray& EventRef)
{
	FTaskGraphInterface::Get().WaitUntilTasksComplete(EventRef);
}

FResourceLoadingManage::FResourceLoadingManage()
	:Super()
	, StreamableManager(new FStreamableManager())
{

}

FResourceLoadingManage::~FResourceLoadingManage()
{
	delete StreamableManager;
}

void FResourceLoadingManage::SetObjectPath(const TArray<FSoftObjectPath>& InObjectPath)
{
	SoftObjectPath = InObjectPath;
}

TArray<FSoftObjectPath>& FResourceLoadingManage::GetObjectPath()
{
	return SoftObjectPath;
}

FStreamableManager* FResourceLoadingManage::GetStreamableManager()
{
	return StreamableManager;
}