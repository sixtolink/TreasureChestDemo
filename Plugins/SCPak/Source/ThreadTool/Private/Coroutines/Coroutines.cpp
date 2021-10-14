#include "Coroutines/Coroutines.h"

ICoroutinesObject::ICoroutinesObject()
	:bAwaken(false)
{

}

TArray<TSharedPtr<ICoroutinesObject>> ICoroutinesObject::Array;

void FCoroutinesObject::Update(FCoroutinesRequest& CoroutinesRequest)
{
	if (TotalTime != INDEX_NONE)
	{
		//¼ÆÊ±
		RuningTime += CoroutinesRequest.IntervalTime;
		if (RuningTime >= TotalTime)
		{
			SimpleDelegate.ExecuteIfBound();
			CoroutinesRequest.bCompleteRequest = true;
		}
	}
	else
	{
		if (bAwaken)
		{
			SimpleDelegate.ExecuteIfBound();
			CoroutinesRequest.bCompleteRequest = true;
		}
	}
}

FCoroutinesRequest::FCoroutinesRequest(float InIntervalTime)
	:bCompleteRequest(false)
	, IntervalTime(InIntervalTime)
{

}

FCoroutinesObject::FCoroutinesObject(const FSimpleDelegate& InSimpleDelegate)
	:ICoroutinesObject()
	, SimpleDelegate(InSimpleDelegate)
	, TotalTime(INDEX_NONE)
	, RuningTime(0.f)
{
}

FCoroutinesObject::FCoroutinesObject(float InTotalTime, const FSimpleDelegate& InSimpleDelegate)
	:ICoroutinesObject()
	, SimpleDelegate(InSimpleDelegate)
	, TotalTime(InTotalTime)
	, RuningTime(0.f)
{
}