#pragma once

#include "CoreMinimal.h"
#include "HAL/Runnable.h"
#include "Interface/ProxyInterface.h"
#include "Core/Semaphore.h"

class THREADTOOL_API FThreadRunnable :public FRunnable, public IThreadProxy
{
public:
	FThreadRunnable(bool InSuspendAtFirst = false);
	virtual ~FThreadRunnable();

	virtual void CreateSafeThread();
	virtual void WakeupThread();
	virtual bool IsSuspend();
	virtual void WaitAndCompleted();
	virtual void BlockingAndCompletion();

private:
	bool Init() override;
	uint32 Run() override;
	void Stop() override;
	void Exit() override;

private:
	//能否run——FThreadSafeCounter线程计数
	FThreadSafeCounter StopTaskCounter;
	//是否挂起
	bool bSuspendAtFirst;
	//线程实例
	class FRunnableThread* Thread;
	//线程名
	FName ThreadName;
	//线程事件
	FSimpleSemaphore ThreadEvent;
	//通知线程启动的线程的事件
	FSimpleSemaphore StartUpEvent;
	//同步事件，等待并执行
	FSimpleSemaphore WaitExecuteEvent;
	//锁
	FCriticalSection Mutex;
	//线程计数
	static int32 ThreadCount;
};