#include "Core/Semaphore.h"
#include "HAL/Event.h"
#include "ThreadPlatform.h"

FSimpleSemaphore::FSimpleSemaphore()
	:Event(FPlatformProcess::GetSynchEventFromPool())
	,bWait(false)
{

}

FSimpleSemaphore::~FSimpleSemaphore()
{
	FPlatformProcess::ReturnSynchEventToPool(Event);
}

void FSimpleSemaphore::Wait()
{
	bWait = true;
	Event->Wait();
}

void FSimpleSemaphore::Wait(uint32 waitTime, const bool bIgnoreThreadIdleStats /*= false*/)
{
	bWait = true;
	Event->Wait(waitTime, bIgnoreThreadIdleStats);
}

void FSimpleSemaphore::Trigger()
{
	Event->Trigger();
	bWait = false;
}

