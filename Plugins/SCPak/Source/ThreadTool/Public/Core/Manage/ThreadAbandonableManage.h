#pragma once 

#include "CoreMinimal.h"
#include "Interface/ThreadManageInterface.h"
#include "ManageBase/ThreadManageBase.h"

//Bind   ͬ���󶨴��� �����������߳� ����߳���������¼������������߳�
//Create �첽�󶨴��� ������ɺ��Զ�����
struct THREADTOOL_API FThreadAbandonableManage :FThreadTemplate<IAbandonableContainer>
{
	
};