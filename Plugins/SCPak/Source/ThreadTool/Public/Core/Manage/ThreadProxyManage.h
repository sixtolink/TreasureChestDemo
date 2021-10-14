#pragma once 

#include "CoreMinimal.h"
#include "Interface/ThreadManageInterface.h"
#include "ManageBase/ThreadManageBase.h"

//Bind 创建线程并绑定，单步执行 通过join和detach来执行异步还是同步执行
//Create 创建线程并执行，是最快捷的的异步方式
class THREADTOOL_API FThreadProxyManage :public FThreadTemplate<IThreadProxyContainer, FThreadHandle>
{
public:
	FThreadProxyManage();
	~FThreadProxyManage();

	//同步
	bool Join(FThreadHandle Handle);

	//异步
	bool Detach(FThreadHandle Handle);

	EThreadState Joinable(FThreadHandle Handle);
};
