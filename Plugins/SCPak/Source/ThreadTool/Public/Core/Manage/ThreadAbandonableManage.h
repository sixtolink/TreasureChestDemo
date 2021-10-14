#pragma once 

#include "CoreMinimal.h"
#include "Interface/ThreadManageInterface.h"
#include "ManageBase/ThreadManageBase.h"

//Bind   同步绑定代理 阻塞启动它线程 完成线程任务后重新激活启动它的线程
//Create 异步绑定代理 任务完成后自动销毁
struct THREADTOOL_API FThreadAbandonableManage :FThreadTemplate<IAbandonableContainer>
{
	
};