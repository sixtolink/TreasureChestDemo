#pragma once 

#include "CoreMinimal.h"
#include "Interface/ThreadManageInterface.h"
#include "ManageBase/ThreadManageBase.h"

//Bind �����̲߳��󶨣�����ִ�� ͨ��join��detach��ִ���첽����ͬ��ִ��
//Create �����̲߳�ִ�У������ݵĵ��첽��ʽ
class THREADTOOL_API FThreadProxyManage :public FThreadTemplate<IThreadProxyContainer, FThreadHandle>
{
public:
	FThreadProxyManage();
	~FThreadProxyManage();

	//ͬ��
	bool Join(FThreadHandle Handle);

	//�첽
	bool Detach(FThreadHandle Handle);

	EThreadState Joinable(FThreadHandle Handle);
};
