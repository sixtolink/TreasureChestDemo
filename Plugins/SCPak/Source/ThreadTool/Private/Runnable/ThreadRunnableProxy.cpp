#include "Runnable/ThreadRunnableProxy.h"
#include "HAL/RunnableThread.h"
#include "ThreadPlatform.h"

int32 FThreadRunnable::ThreadCount = 0;

FThreadRunnable::FThreadRunnable(bool InSuspendAtFirst)
	:IThreadProxy()
	, StopTaskCounter(0)
	, bSuspendAtFirst(InSuspendAtFirst)
	, Thread(nullptr)
{

}

FThreadRunnable::~FThreadRunnable()
{
	if (Thread != NULL)
	{
		delete Thread;
		Thread = nullptr;
	}
}

void FThreadRunnable::CreateSafeThread()
{
	//允许执行业务逻辑

	ThreadName = *(TEXT("SimpleThread_%i") + FString::Printf(TEXT("%i"), ThreadCount));
	Thread = FRunnableThread::Create(this, *ThreadName.ToString(), 0, TPri_BelowNormal);

	ThreadCount++;
}

void FThreadRunnable::WakeupThread()
{
	ThreadEvent.Trigger();
}

bool FThreadRunnable::IsSuspend()
{
	return ThreadEvent.IsWait();
}

void FThreadRunnable::WaitAndCompleted()
{
	//结束业务逻辑
	Stop();
	if (ThreadEvent.IsWait())
	{
		//把自身唤醒
		ThreadEvent.Trigger();
		//把启动自身的线程休眠
		StartUpEvent.Wait();
		FPlatformProcess::Sleep(0.03f);
	}
}

void FThreadRunnable::BlockingAndCompletion()
{
	ThreadEvent.Trigger();
	WaitExecuteEvent.Wait();
}

bool FThreadRunnable::Init()
{
	if (!FPlatformProcess::SupportsMultithreading())
	{
		Stop();
	}
	return StopTaskCounter.GetValue() == 0;
}

uint32 FThreadRunnable::Run()
{
	while (StopTaskCounter.GetValue() == 0)
	{
		if (!bSuspendAtFirst)
			ThreadEvent.Wait();
		//业务逻辑,调用代理

		if (ThreadDelegate.IsBound())
		{
			ThreadDelegate.Execute();
			ThreadDelegate.Unbind();
		}
		WaitExecuteEvent.Trigger();

		//挂起
		bSuspendAtFirst = false;
	}

	return 0;
}

void FThreadRunnable::Stop()
{
	StopTaskCounter.Increment();
}

void FThreadRunnable::Exit()
{
	StartUpEvent.Trigger();
}

