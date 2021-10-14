#include "Interface/ProxyInterface.h"

//Éú³ÉÎ¨Ò»ID
uint64 SpawnUniqueID()
{
	return FMath::Abs(FMath::RandRange(100, 1256343) + FDateTime::Now().GetTicks());
}

FSimpleThreadHandle::FSimpleThreadHandle()
	:GUIDTypeA(SpawnUniqueID())
	,GUIDTypeB(SpawnUniqueID())
	,GUIDTypeC(SpawnUniqueID())
	,GUIDTypeD(SpawnUniqueID())
{

}

IThreadProxy::IThreadProxy()
	:ThreadHandle(MakeShareable(new FSimpleThreadHandle))
{

}

IThreadProxy::~IThreadProxy()
{

}