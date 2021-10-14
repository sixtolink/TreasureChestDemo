#pragma once

#include "CoreMinimal.h"
#include "Core/Manage/ThreadProxyManage.h"
#include "Core/Manage/ThreadTaskManage.h"
#include "Core/Manage/ThreadAbandonableManage.h"
#include "Core/Manage/CoroutinesManage.h"
#include "Core/Manage/ThreadGraphManage.h"
#include "Tickable.h"
#include "Core/Manage/ResourceLoadingManage.h"

namespace TM
{
	class THREADTOOL_API FThreadManage :public TSharedFromThis<FThreadManage>,public FTickableGameObject
	{
	public:
		static TSharedRef<FThreadManage>Get();
		static void Destroy();

	private:
		virtual void Tick(float DeltaTime);
		virtual TStatId GetStatId() const;

	public:
		static FThreadProxyManage& GetProxy() { return Get()->ThreadProxyManage; }
		static FThreadTaskManage& GetTask() { return Get()->ThreadTaskManage; }
		static FThreadAbandonableManage& GetAbandonable() { return Get()->ThreadAbandonableManage; }
		static FCoroutinesManage& GetCoroutines() { return Get()->CoroutinesManage; }
		static FResourceLoadingManage& GetResourceLoading() { return Get()->ResourceLoadingManage; }

	protected:
		//自定义线程
		FThreadProxyManage ThreadProxyManage;
		//自定义线程池
		FThreadTaskManage ThreadTaskManage;
		//从UE4自己的线程池获取线程执行
		FThreadAbandonableManage ThreadAbandonableManage;
		//可以设置前置任务的线程
		FThreadGraphManage ThreadGraphManage;
		//协程对象
		FCoroutinesManage CoroutinesManage;
		//资源读取
		FResourceLoadingManage ResourceLoadingManage;
	private:
		static TSharedPtr<FThreadManage> ThreadManage;
	};
}
using namespace TM;

typedef TM::FThreadManage GThread;