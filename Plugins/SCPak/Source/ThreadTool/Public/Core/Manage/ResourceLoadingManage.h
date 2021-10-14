#pragma once

#include "CoreMinimal.h"
#include "Interface/ThreadManageInterface.h"
#include "Core/Manage/ManageBase/ThreadManageBase.h"

//通过接口的Create函数 可以绑定异步结束后通知的事件
struct THREADTOOL_API FResourceLoadingManage :FThreadTemplateBase<IStreamableContainer, TSharedPtr<struct FStreamableHandle>>
{
	typedef FThreadTemplateBase<IStreamableContainer, TSharedPtr<struct FStreamableHandle>> Super;

	FResourceLoadingManage();
	~FResourceLoadingManage();

protected:
	virtual void SetObjectPath(const TArray<FSoftObjectPath>& InObjectPath) final;
	virtual TArray<FSoftObjectPath>& GetObjectPath() final;
	virtual FStreamableManager* GetStreamableManager() final;

private:
	TArray<FSoftObjectPath> SoftObjectPath;
	FStreamableManager* StreamableManager;
};