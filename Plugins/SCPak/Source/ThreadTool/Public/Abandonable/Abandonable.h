#pragma once

#include "CoreMinimal.h"

struct THREADTOOL_API FAbandonable :FNonAbandonableTask 
{
	FAbandonable(const FSimpleDelegate& InThreadDelegate);

	void DoWork();

	FORCEINLINE TStatId GetStatId() const
	{
		RETURN_QUICK_DECLARE_CYCLE_STAT(FAbandonable, STATGROUP_ThreadPoolAsyncTasks);
	}
protected:
	FSimpleDelegate ThreadDelegate;
};