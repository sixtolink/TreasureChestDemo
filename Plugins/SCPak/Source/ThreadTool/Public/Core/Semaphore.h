#pragma once

#include "CoreMinimal.h"

struct FSimpleSemaphore
{
	FSimpleSemaphore();
	~FSimpleSemaphore();

	void Wait();
	void Wait(uint32 waitTime, const bool bIgnoreThreadIdleStats = false);
	void Trigger();

	FORCEINLINE bool IsWait() { return bWait; }

private:
	class FEvent* Event;
	uint8 bWait : 1;
};