#pragma once 

#include "CoreMinimal.h"
#include "Interface/ThreadManageInterface.h"
#include "ManageBase/ThreadManageBase.h"

//Bind 添加到任务队列 如果有空线程会去执行
//Create 直接在线程池里寻找，如果有空线程，直接运行

class THREADTOOL_API FThreadTaskManage : public FThreadTemplate<IThreadTaskContainer>
{
public:
	FThreadTaskManage();
	~FThreadTaskManage();

	void Init(int32 ThreadNum);

	void Tick(float DeltaTime);
};