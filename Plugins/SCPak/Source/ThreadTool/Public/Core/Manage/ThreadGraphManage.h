
#pragma 

#include "CoreMinimal.h"
#include "Core/Manage/ManageBase/ThreadManageBase.h"
#include "Interface/ThreadManageInterface.h"

struct THREADTOOL_API FThreadGraphManage :FThreadTemplate<IGraphContainer, FGraphEventRef>
{
	static void Wait(const FGraphEventRef& EventRef);
	static void Wait(const FGraphEventArray& EventRef);
};