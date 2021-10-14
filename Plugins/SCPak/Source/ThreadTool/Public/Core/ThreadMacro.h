#pragma once
#include "Misc/ScopeLock.h"
#include "Abandonable/Abandonable.h"
#include "Async/TaskGraphInterfaces.h"

#if PLATFORM_WINDOWS
#include <iostream>
#include <thread>
#define CPUThreadNumber std::thread::hardware_concurrency()
#else
#if PLATFORM_LINUX
#define CPUThreadNumber 12
#else
#if PLATFORM_MAC
#define CPUThreadNumber 12
#endif
#endif
#endif

#define MUTEX_LOCK FScopeLock ScopeLock(&Mutex)

//异步
#define USE_UE_THREAD_POOL_ASYNCTASK(ThreadDelegate) \
(new FAutoDeleteAsyncTask<FAbandonable>(ThreadDelegate))->StartBackgroundTask()

//绑定异步宏
#define ASYNCTASK_UOBJECT(Object,...) \
USE_UE_THREAD_POOL_ASYNCTASK(FSimpleDelegate::CreateUObject(Object,__VA_ARGS__))

#define ASYNCTASK_Raw(Object,...) \
USE_UE_THREAD_POOL_ASYNCTASK(FSimpleDelegate::CreateRaw(Object,__VA_ARGS__))

#define ASYNCTASK_SP(Object,...) \
USE_UE_THREAD_POOL_ASYNCTASK(FSimpleDelegate::CreateSP(Object,__VA_ARGS__))

#define ASYNCTASK_Lambda(...) \
USE_UE_THREAD_POOL_ASYNCTASK(FSimpleDelegate::CreateLambda(__VA_ARGS__))

#define ASYNCTASK_UFunction(Object,...) \
USE_UE_THREAD_POOL_ASYNCTASK(FSimpleDelegate::CreateUFunction(Object,__VA_ARGS__))

//执行异步同时阻塞主线程实现同步
#define USE_UE_THREAD_POOL_SYNCTASK(ThreadDelegate) \
{FAsyncTask<FAbandonable>*Abandonable = new FAsyncTask<FAbandonable>(ThreadDelegate); \
Abandonable->StartBackgroundTask(); \
Abandonable->EnsureLoadingComplete(); \
delete Abandonable;}

//绑定同步宏
#define SYNCTASK_UOBJECT(Object,...) \
USE_UE_THREAD_POOL_SYNCTASK(FSimpleDelegate::CreateUObject(Object,__VA_ARGS__))

#define SYNCTASK_Raw(Object,...) \
USE_UE_THREAD_POOL_SYNCTASK(FSimpleDelegate::CreateRaw(Object,__VA_ARGS__))

#define SYNCTASK_SP(Object,...) \
USE_UE_THREAD_POOL_SYNCTASK(FSimpleDelegate::CreateSP(Object,__VA_ARGS__))

#define SYNCTASK_Lambda(...) \
USE_UE_THREAD_POOL_SYNCTASK(FSimpleDelegate::CreateLambda(__VA_ARGS__))

#define SYNCTASK_UFunction(Object,...) \
USE_UE_THREAD_POOL_SYNCTASK(FSimpleDelegate::CreateUFunction(Object,__VA_ARGS__))

//呼叫线程 可以设置前置任务
#define CALL_THREAD(OtherTask,CallThreadName,InTaskDeletegate) \
FSimpleDelegateGraphTask::CreateAndDispatchWhenReady(InTaskDeletegate,TStatId(),OtherTask,CallThreadName);

#define CALL_THREAD_UOBJECT(OtherTask,CallThreadName,Object,...) \
CALL_THREAD(OtherTask,CallThreadName,FSimpleDelegate::CreateUObject(Object,__VA_ARGS__))

#define CALL_THREAD_Raw(OtherTask,CallThreadName,Object,...) \
CALL_THREAD(OtherTask,CallThreadName,FSimpleDelegate::CreateRaw(Object,__VA_ARGS__))

#define CALL_THREAD_SP(OtherTask,CallThreadName,Object,...) \
CALL_THREAD(OtherTask,CallThreadName,FSimpleDelegate::CreateSP(Object,__VA_ARGS__))

#define CALL_THREAD_Lambda(OtherTask,CallThreadName,...) \
CALL_THREAD(OtherTask,CallThreadName,FSimpleDelegate::CreateLambda(__VA_ARGS__))

#define CALL_THREAD_UFunction(OtherTask,CallThreadName,Object,...) \
CALL_THREAD(CallThreadName,FSimpleDelegate::CreateUFunction(Object,__VA_ARGS__))


#define WAITING_OTHER_THREADS_COMPLETED(EventRef) \
FTaskGraphInterface::Get().WaitUntilTaskCompletes(EventRef);

#define WAITING_OTHER_THREADS_COMPLETED_MULTI(EventRef) \
FTaskGraphInterface::Get().WaitUntilTasksComplete(EventRef);