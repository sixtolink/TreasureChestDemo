#pragma once

#include "CoreTypes.h"

#if PLATFORM_WINDOWS
struct THREADTOOL_API FWindowsPlatformThread
{
	static void Show();

	static void Hide();

	static bool IsShow();

	static FSimpleDelegate CompletedDelegate;

	static FSimpleDelegate RunDelegate;
};
#endif