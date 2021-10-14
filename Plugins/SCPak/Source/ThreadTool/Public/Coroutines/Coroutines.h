#pragma once

#include "CoreMinimal.h"
#include "Core/ThreadType.h"

struct THREADTOOL_API FCoroutinesRequest 
{
	FCoroutinesRequest(float InIntervalTime);

	bool bCompleteRequest;
	float IntervalTime;
};

//接口
class THREADTOOL_API ICoroutinesObject :public TSharedFromThis<ICoroutinesObject>
{
	friend class ICoroutinesContainer;

public:
	ICoroutinesObject();
	virtual ~ICoroutinesObject() {}

	bool operator==(const ICoroutinesObject& ThreadHandle)
	{
		return this->Handle == ThreadHandle.Handle;
	}

	FORCEINLINE void Awaken() { bAwaken = true; }

protected:
	virtual void Update(FCoroutinesRequest& CoroutinesRequest) = 0;

protected:
	//协程容器
	static TArray<TSharedPtr<ICoroutinesObject>> Array;

	//用来唤醒协程
	uint8 bAwaken : 1;

	//用来确保唯一性
	FThreadHandle Handle;
};

typedef TWeakPtr<ICoroutinesObject> FCoroutinesHandle;

//协程对象，继承接口
class THREADTOOL_API FCoroutinesObject :public ICoroutinesObject
{
public:
	FCoroutinesObject(const FSimpleDelegate& InSimpleDelegate);
	FCoroutinesObject(float InTotalTime, const FSimpleDelegate& InSimpleDelegate);
protected:
	//final停止子类继续重写
	virtual void Update(FCoroutinesRequest& CoroutinesRequest) final;

private:
	FSimpleDelegate SimpleDelegate;
	const float TotalTime;
	float RuningTime;
};