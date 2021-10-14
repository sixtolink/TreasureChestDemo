#pragma once

#include "CoreMinimal.h"
#include "Core/ThreadType.h"

class THREADTOOL_API IThreadProxy : public TSharedFromThis<IThreadProxy>
{
public:

	IThreadProxy();
	virtual ~IThreadProxy();

	virtual void CreateSafeThread() = 0;
	virtual void WakeupThread() = 0;
	virtual bool IsSuspend() = 0;
	virtual void WaitAndCompleted() = 0;
	virtual void BlockingAndCompletion() = 0;

	//��������
	FORCEINLINE FSimpleDelegate& GetThreadDelegate() { return ThreadDelegate; }
	//��������������ط�ȫ���������ã���ȫ
	FORCEINLINE FThreadHandle GetThreadHandle() { return ThreadHandle; }
protected:
	//UE4�򵥴���
	FSimpleDelegate ThreadDelegate;
private:
	//�߳̾��
	TSharedPtr<FSimpleThreadHandle> ThreadHandle;
};