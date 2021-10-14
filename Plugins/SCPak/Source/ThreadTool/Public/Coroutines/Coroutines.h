#pragma once

#include "CoreMinimal.h"
#include "Core/ThreadType.h"

struct THREADTOOL_API FCoroutinesRequest 
{
	FCoroutinesRequest(float InIntervalTime);

	bool bCompleteRequest;
	float IntervalTime;
};

//�ӿ�
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
	//Э������
	static TArray<TSharedPtr<ICoroutinesObject>> Array;

	//��������Э��
	uint8 bAwaken : 1;

	//����ȷ��Ψһ��
	FThreadHandle Handle;
};

typedef TWeakPtr<ICoroutinesObject> FCoroutinesHandle;

//Э�̶��󣬼̳нӿ�
class THREADTOOL_API FCoroutinesObject :public ICoroutinesObject
{
public:
	FCoroutinesObject(const FSimpleDelegate& InSimpleDelegate);
	FCoroutinesObject(float InTotalTime, const FSimpleDelegate& InSimpleDelegate);
protected:
	//finalֹͣ���������д
	virtual void Update(FCoroutinesRequest& CoroutinesRequest) final;

private:
	FSimpleDelegate SimpleDelegate;
	const float TotalTime;
	float RuningTime;
};