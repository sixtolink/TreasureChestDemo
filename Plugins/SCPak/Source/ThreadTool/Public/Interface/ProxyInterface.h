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

	//公开代理
	FORCEINLINE FSimpleDelegate& GetThreadDelegate() { return ThreadDelegate; }
	//公开句柄，其他地方全都是弱引用，安全
	FORCEINLINE FThreadHandle GetThreadHandle() { return ThreadHandle; }
protected:
	//UE4简单代理
	FSimpleDelegate ThreadDelegate;
private:
	//线程句柄
	TSharedPtr<FSimpleThreadHandle> ThreadHandle;
};