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
	//�ܷ�run����FThreadSafeCounter�̼߳���
	FThreadSafeCounter StopTaskCounter;
	//�Ƿ����
	bool bSuspendAtFirst;
	//�߳�ʵ��
	class FRunnableThread* Thread;
	//�߳���
	FName ThreadName;
	//�߳��¼�
	FSimpleSemaphore ThreadEvent;
	//֪ͨ�߳��������̵߳��¼�
	FSimpleSemaphore StartUpEvent;
	//ͬ���¼����ȴ���ִ��
	FSimpleSemaphore WaitExecuteEvent;
	//��
	FCriticalSection Mutex;
	//�̼߳���
	static int32 ThreadCount;
};