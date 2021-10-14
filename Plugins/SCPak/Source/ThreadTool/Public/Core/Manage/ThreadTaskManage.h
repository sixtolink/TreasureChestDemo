#pragma once 

#include "CoreMinimal.h"
#include "Interface/ThreadManageInterface.h"
#include "ManageBase/ThreadManageBase.h"

//Bind ��ӵ�������� ����п��̻߳�ȥִ��
//Create ֱ�����̳߳���Ѱ�ң�����п��̣߳�ֱ������

class THREADTOOL_API FThreadTaskManage : public FThreadTemplate<IThreadTaskContainer>
{
public:
	FThreadTaskManage();
	~FThreadTaskManage();

	void Init(int32 ThreadNum);

	void Tick(float DeltaTime);
};