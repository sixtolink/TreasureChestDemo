#pragma once

#include "CoreMinimal.h"

struct THREADTOOL_API FSimpleThreadHandle :public TSharedFromThis<FSimpleThreadHandle>
{
	FSimpleThreadHandle();

	bool operator==(FSimpleThreadHandle& SimpleThreadHandle)
	{
		return 
			this->GUIDTypeA == SimpleThreadHandle.GUIDTypeA &&
			this->GUIDTypeB == SimpleThreadHandle.GUIDTypeB &&
			this->GUIDTypeC == SimpleThreadHandle.GUIDTypeC &&
			this->GUIDTypeD == SimpleThreadHandle.GUIDTypeD;
	}
protected:
	uint64 GUIDTypeA;
	uint64 GUIDTypeB;
	uint64 GUIDTypeC;
	uint64 GUIDTypeD;
};

enum class EThreadState
{
	LEISURELY,
	WORKING,
	ERROR
};

//线程Handle弱指针
typedef TWeakPtr<struct FSimpleThreadHandle> FThreadHandle;

//Lambda函数指针
typedef TFunction<void()> FThreadLambda;