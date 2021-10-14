// Fill out your copyright notice in the Description page of Project Settings.


#include "SCOssManage.h"
#include "SCOssMacro.h"
#include "Async/AsyncWork.h"
#include "Async/TaskGraphInterfaces.h"
#include "Misc/ScopeLock.h"
#include "Misc/ConfigCacheIni.h"
#include "Misc/FileHelper.h"
#include "CoreGlobals.h"
#include "Setting/MyOSSConfig.h"

#include "alibabacloud/oss/OssClient.h"

#include <memory>
#include <fstream>

using namespace AlibabaCloud::OSS;

SCOssManage* SCOssManage::SCOss = nullptr;

//异步工具
class FOSSAsynTask :public FNonAbandonableTask
{
public:
	FOSSAsynTask(const TFunction<void()>InFunction)
		:Function(InFunction) 
	{}

	void DoWork()
	{
		Function();
	}

	FORCEINLINE TStatId GetStatId() const 
	{
		RETURN_QUICK_DECLARE_CYCLE_STAT(FOSSAsynTask, STATGROUP_ThreadPoolAsyncTasks);
	}

protected:
	const TFunction<void()>Function;
};

SCOssManage::SCOssManage()
{
}

SCOssManage::~SCOssManage()
{
}

SCOssManage* SCOssManage::Get()
{
	if (!SCOss)
	{
		SCOss = new SCOssManage();

		if (!IsSdkInitialized())
		{
			InitializeSdk();
		}
	}

	return SCOss;
}

void SCOssManage::Destroy()
{
	if (SCOss)
	{
		if (IsSdkInitialized())
		{
			ShutdownSdk();
		}
		delete SCOss;
	}

	SCOss = nullptr;
}

//类外小工具
struct FAuxiliaryTools
{
	//将自定义配置表类转换成oss sdk原生的配置表类,防止用户使用插件时需要包含oss sdk的头文件
	ClientConfiguration CovertToOssConf(const FClientConfiguration& InConf)
	{
		ClientConfiguration OSSConf;

		FString NetworkInterface;
		OSSConf.caFile = TCHAR_TO_UTF8(*InConf.CaFile);
		OSSConf.scheme = (AlibabaCloud::OSS::Http::Scheme)InConf.Scheme;
		OSSConf.proxyScheme = (AlibabaCloud::OSS::Http::Scheme)InConf.ProxyScheme;
		OSSConf.maxConnections = InConf.MaxConnections;
		OSSConf.requestTimeoutMs = InConf.RequestTimeoutMs;
		OSSConf.enableDateSkewAdjustment = InConf.bEnableDateSkewAdjustment;
		OSSConf.enableCrc64 = InConf.bEnableCrc64;
		OSSConf.isCname = InConf.bCname;
		OSSConf.verifySSL = InConf.bVerifySSL;
		OSSConf.caPath = TCHAR_TO_UTF8(*InConf.CaPath);
		OSSConf.proxyPassword = TCHAR_TO_UTF8(*InConf.ProxyPassword);
		OSSConf.proxyUserName = TCHAR_TO_UTF8(*InConf.ProxyUserName);
		OSSConf.proxyPort = InConf.ProxyPort;
		OSSConf.connectTimeoutMs = InConf.ConnectTimeoutMs;
		OSSConf.proxyHost = TCHAR_TO_UTF8(*InConf.ProxyHost);

		if (InConf.RecvRateLimiter != 0)
		{
			std::shared_ptr<FOSSRateLimiter> Recv = std::make_shared<FOSSRateLimiter>();
			Recv->setRate(InConf.RecvRateLimiter);
			OSSConf.recvRateLimiter = Recv;
		}

		if (InConf.SendRateLimiter != 0)
		{
			std::shared_ptr<FOSSRateLimiter> Send = std::make_shared<FOSSRateLimiter>();
			Send->setRate(InConf.SendRateLimiter);
			OSSConf.sendRateLimiter = Send;
		}

		return OSSConf;
	}


	void Print(const FString& Msg, float Time = 10.f, FColor Color = FColor::Red)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, Time, Color, Msg);
		}
	}
	void Print(const string& Msg, float Time = 10.f, FColor Color = FColor::Red) 
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, Time, Color, Msg.c_str());
		}
	}

	int64_t GetFileSize(const string& file)
	{
		std::fstream f(file, std::ios::in | std::ios::binary);
		f.seekg(0, f.end);
		int64_t size = f.tellg();
		f.close();

		return size;
	}
};

void SCOssManage::FOSS::InitAccounts()
{
	AccessKeyId = TCHAR_TO_UTF8(*(GetDefault<UMyOSSConfig>()->AccessKeyID));
	AccessKeySecret = TCHAR_TO_UTF8(*(GetDefault<UMyOSSConfig>()->AccessSecret));
	Endpoint = TCHAR_TO_UTF8(*(GetDefault<UMyOSSConfig>()->Endpoint));
	InBucketName = TCHAR_TO_UTF8(*(GetDefault<UMyOSSConfig>()->BucketName));
}

void SCOssManage::FOSS::InitConf(const FClientConfiguration& InConf)
{
	Conf = InConf;
}

bool SCOssManage::FOSS::CreateBucket(EOSSStorageType OSSStorageType, EAcl Acl)
{
	FAuxiliaryTools AuxiliaryTools;
	OssClient Client(Endpoint, AccessKeyId, AccessKeySecret, AuxiliaryTools.CovertToOssConf(Conf));
	
	//创建桶
	CreateBucketRequest Request(InBucketName, (StorageClass)OSSStorageType, (CannedAccessControlList)Acl);
	auto Outcome = Client.CreateBucket(Request);

	//判断桶是否已经存在
	if (!Outcome.isSuccess())
	{
#if WITH_EDITOR
		OSSTOOL_MACRO_ERROR(Outcome);
#endif
		return false;
	}
	return true;
}

bool SCOssManage::FOSS::ListBuckets(TArray<FString>& BucketNameArray)
{
	FAuxiliaryTools AuxiliaryTools;
	OssClient Client(Endpoint, AccessKeyId, AccessKeySecret, AuxiliaryTools.CovertToOssConf(Conf));

	//列举储存空间
	ListBucketsRequest Request;
	auto Outcome = Client.ListBuckets(Request);

	if (Outcome.isSuccess())
	{
		for (auto result : Outcome.result().Buckets())
		{
			FString BucketName = result.Name().c_str();
			BucketNameArray.Add(BucketName);
		}
	}
	else
	{
#if WITH_EDITOR
		OSSTOOL_MACRO_ERROR(Outcome);
#endif
		return false;
	}
	return true;
}

bool SCOssManage::FOSS::GetBucketLocation()
{
	FAuxiliaryTools AuxiliaryTools;
	OssClient Client(Endpoint, AccessKeyId, AccessKeySecret, AuxiliaryTools.CovertToOssConf(Conf));

	//获取储存空间当地s
	GetBucketLocationRequest Request(InBucketName);
	auto Outcome = Client.GetBucketLocation(Request);

	//判断桶是否已经存在
	if (!Outcome.isSuccess())
	{
#if WITH_EDITOR
		OSSTOOL_MACRO_ERROR(Outcome);
#endif
		return false;
	}
	return true;
}

bool SCOssManage::FOSS::DeleteBucket()
{
	int32 Number = 1000;
	//列举上传分片
	TArray<FMultipartPartsUploadsInfo> MultipartPartsUploadsInfo;
	if (ListMultipartUploads(MultipartPartsUploadsInfo, Number))
	{
		//先删除碎片
		for (auto& Tmp : MultipartPartsUploadsInfo)
		{
			AbortMultipartUpload(Tmp.Key, Tmp.UploadId);
		}
		//列举对象
		TArray<FOSSObjectInfo> OSSObjectInfo;
		if (ListObjects(OSSObjectInfo, Number))
		{
			TArray<FString> ObjectName;
			for (auto& Tmp : OSSObjectInfo)
			{
				ObjectName.Add(Tmp.Name);
			}
			//删除列举的对象
			DeleteObjects(ObjectName);

			FAuxiliaryTools AuxiliaryTools;
			OssClient Client(Endpoint, AccessKeyId, AccessKeySecret, AuxiliaryTools.CovertToOssConf(Conf));

			//指定删除桶
			DeleteBucketRequest Request(InBucketName);
			auto Outcome = Client.DeleteBucket(Request);

			if (!Outcome.isSuccess())
			{
#if WITH_EDITOR
				OSSTOOL_MACRO_ERROR(Outcome);
#endif
			}
			else
			{
				return true;
			}
		}
	}
	return false;
}

bool SCOssManage::FOSS::SetBucketAcl(EAcl BucketAcl)
{
	FAuxiliaryTools AuxiliaryTools;
	OssClient Client(Endpoint, AccessKeyId, AccessKeySecret, AuxiliaryTools.CovertToOssConf(Conf));

	//设置桶访问权限
	SetBucketAclRequest Request(InBucketName, (CannedAccessControlList)BucketAcl);
	auto Outcome = Client.SetBucketAcl(Request);

	if (!Outcome.isSuccess())
	{
#if WITH_EDITOR
		OSSTOOL_MACRO_ERROR(Outcome);
#endif
		return false;
	}
	return true;
}

EAcl SCOssManage::FOSS::GetBucketAcl()
{
	FAuxiliaryTools AuxiliaryTools;
	OssClient Client(Endpoint, AccessKeyId, AccessKeySecret, AuxiliaryTools.CovertToOssConf(Conf));

	//获取桶权限
	GetBucketAclRequest Request(InBucketName);
	auto Outcome = Client.GetBucketAcl(Request);

	if (!Outcome.isSuccess())
	{
#if WITH_EDITOR
		OSSTOOL_MACRO_ERROR(Outcome);
#endif
		return EAcl::NONE;
	}
	return (EAcl)Outcome.result().Acl();
}

bool SCOssManage::FOSS::SetBucketRequestPayment(ERequestPayerType InRequestPayer)
{
	FAuxiliaryTools AuxiliaryTools;
	OssClient Client(Endpoint, AccessKeyId, AccessKeySecret, AuxiliaryTools.CovertToOssConf(Conf));

	//设置桶请求者付费模式
	SetBucketRequestPaymentRequest Request(InBucketName);
	Request.setRequestPayer((RequestPayer)InRequestPayer);
	auto Outcome = Client.SetBucketRequestPayment(Request);

	if (!Outcome.isSuccess())
	{
#if WITH_EDITOR
		OSSTOOL_MACRO_ERROR(Outcome);
#endif
		return false;
	}
	return true;
}

ERequestPayerType SCOssManage::FOSS::GetBucketRequestPayment()
{
	FAuxiliaryTools AuxiliaryTools;
	OssClient Client(Endpoint, AccessKeyId, AccessKeySecret, AuxiliaryTools.CovertToOssConf(Conf));

	//获取桶请求者付费模式
	GetBucketRequestPaymentRequest Request(InBucketName);
	auto Outcome = Client.GetBucketRequestPayment(Request);

	if (!Outcome.isSuccess())
	{
#if WITH_EDITOR
		OSSTOOL_MACRO_ERROR(Outcome);
#endif
		return ERequestPayerType::NONE;
	}
	return (ERequestPayerType)Outcome.result().Payer();
}

bool SCOssManage::FOSS::SetBucketReferer(const TArray<FString>& URLReferer, bool bAllowEmptyReferer)
{
	FAuxiliaryTools AuxiliaryTools;
	OssClient Client(Endpoint, AccessKeyId, AccessKeySecret, AuxiliaryTools.CovertToOssConf(Conf));

	//设置防盗链
	SetBucketRefererRequest Request(InBucketName);
	for (auto& Tmp : URLReferer)
	{
		Request.addReferer(TCHAR_TO_UTF8(*Tmp));
	}
	Request.setAllowEmptyReferer(bAllowEmptyReferer);

	auto Outcome = Client.SetBucketReferer(Request);

	if (!Outcome.isSuccess())
	{
#if WITH_EDITOR
		OSSTOOL_MACRO_ERROR(Outcome);
#endif
		return false;
	}
	return true;
}

FRefererList SCOssManage::FOSS::GetBucketReferer()
{
	FRefererList OutRefererList;

	FAuxiliaryTools AuxiliaryTools;
	OssClient Client(Endpoint, AccessKeyId, AccessKeySecret, AuxiliaryTools.CovertToOssConf(Conf));

	//获取防盗链
	GetBucketRefererRequest Request(InBucketName);
	auto Outcome = Client.GetBucketReferer(Request);

	if (!Outcome.isSuccess())
	{
#if WITH_EDITOR
		OSSTOOL_MACRO_ERROR(Outcome);
#endif
	}
	else
	{
		OutRefererList.RequestId = Outcome.result().RequestId().c_str();
		OutRefererList.bAllowEnptyReferer = Outcome.result().AllowEmptyReferer();
		OutRefererList.RefererListNum = Outcome.result().RefererList().size();
	}
	return OutRefererList;
}

bool SCOssManage::FOSS::DeleteBucketReferer(bool bAllowEmptyReferer)
{
	FAuxiliaryTools AuxiliaryTools;
	OssClient Client(Endpoint, AccessKeyId, AccessKeySecret, AuxiliaryTools.CovertToOssConf(Conf));

	//删除防盗链，然后需要新建一个默认允许空引用的规则覆盖之前的规则
	SetBucketRefererRequest Request(InBucketName);
	Request.setAllowEmptyReferer(bAllowEmptyReferer);

	auto Outcome = Client.SetBucketReferer(Request);

	if (!Outcome.isSuccess())
	{
#if WITH_EDITOR
		OSSTOOL_MACRO_ERROR(Outcome);
#endif
		return false;
	}
	return true;
}

bool SCOssManage::FOSS::GetObjectMeta(const FString& InObjectName, FOSSObjectMeta& OSSObjectInfo)
{
	string ObjectName = TCHAR_TO_UTF8(*InObjectName);

	FAuxiliaryTools AuxiliaryTools;
	OssClient Client(Endpoint, AccessKeyId, AccessKeySecret, AuxiliaryTools.CovertToOssConf(Conf));

	auto Outcome = Client.HeadObject(InBucketName, ObjectName);

	if (!Outcome.isSuccess())
	{
#if WITH_EDITOR
		OSSTOOL_MACRO_ERROR(Outcome);
#endif
		return false;
	}
	else
	{
		auto headMeta = Outcome.result();
		OSSObjectInfo.CacheControl = headMeta.CacheControl().c_str();
		OSSObjectInfo.ContentType = headMeta.ContentType().c_str();
		OSSObjectInfo.ContentLength = headMeta.ContentLength();
		OSSObjectInfo.ContentDisposition = headMeta.ContentDisposition().c_str();
		OSSObjectInfo.ContentEncoding = headMeta.ContentEncoding().c_str();
		OSSObjectInfo.ContentMd5 = headMeta.ContentMd5().c_str();

		OSSObjectInfo.Tag = headMeta.ETag().c_str();
		OSSObjectInfo.LastModified	 = headMeta.LastModified().c_str();
		OSSObjectInfo.ExpirationTime = headMeta.ExpirationTime().c_str();
		OSSObjectInfo.ObjectType = headMeta.ObjectType().c_str();

		OSSObjectInfo.AcceptRanges = headMeta.HttpMetaData()["Accept-Ranges"].c_str();
		OSSObjectInfo.Connection = headMeta.HttpMetaData()["Connection"].c_str();
		OSSObjectInfo.Date = headMeta.HttpMetaData()["Date"].c_str();
		OSSObjectInfo.Server = headMeta.HttpMetaData()["Server"].c_str();
		OSSObjectInfo.x_oss_hash_crc64ecma = headMeta.HttpMetaData()["x-oss-hash-crc64ecma"].c_str();
		OSSObjectInfo.x_oss_object_type = headMeta.HttpMetaData()["x-oss-object-type"].c_str();
		OSSObjectInfo.x_oss_request_id = headMeta.HttpMetaData()["x-oss-request-id"].c_str();
		OSSObjectInfo.x_oss_storage_class = headMeta.HttpMetaData()["x-oss-storage-class"].c_str();

		//std Map 转 UE4 Map
		for (map<string, string>::iterator iter = headMeta.HttpMetaData().begin(); iter != headMeta.HttpMetaData().end(); ++iter)
		{
			OSSObjectInfo.MetaData.Add(iter->first.c_str(), iter->second.c_str());
		}
		
		//std Map 转 UE4 Map
		for (map<string, string>::iterator iter = headMeta.UserMetaData().begin(); iter != headMeta.HttpMetaData().end(); ++iter)
		{
			OSSObjectInfo.UserMetaData.Add(iter->first.c_str(), iter->second.c_str());
		}
	}
	return true;
}

EAcl SCOssManage::FOSS::GetObjectAcl(const FString& InObjectName)
{
	string ObjectName = TCHAR_TO_UTF8(*InObjectName);

	FAuxiliaryTools AuxiliaryTools;
	OssClient Client(Endpoint, AccessKeyId, AccessKeySecret, AuxiliaryTools.CovertToOssConf(Conf));

	GetObjectAclRequest Request(InBucketName, ObjectName);
	auto Outcome = Client.GetObjectAcl(Request);

	if (!Outcome.isSuccess())
	{
#if WITH_EDITOR
		OSSTOOL_MACRO_ERROR(Outcome);
#endif
		return EAcl::NONE;
	}
	return (EAcl)Outcome.result().Acl();
}

bool SCOssManage::FOSS::SetObjectAcl(const FString& InObjectName, EAcl InAcl /*= EAcl::DEFAULT*/)
{
	string ObjectName = TCHAR_TO_UTF8(*InObjectName);

	FAuxiliaryTools AuxiliaryTools;
	OssClient Client(Endpoint, AccessKeyId, AccessKeySecret, AuxiliaryTools.CovertToOssConf(Conf));

	SetObjectAclRequest Request(InBucketName, ObjectName);
	Request.setAcl((CannedAccessControlList)InAcl);

	auto Outcome = Client.SetObjectAcl(Request);

	if (!Outcome.isSuccess())
	{
#if WITH_EDITOR
		OSSTOOL_MACRO_ERROR(Outcome);
#endif
		return false;
	}
	return true;
}

bool SCOssManage::FOSS::DoesObjectExist(const FString& InObjectName)
{
	string ObjectName = TCHAR_TO_UTF8(*InObjectName);

	FAuxiliaryTools AuxiliaryTools;
	OssClient Client(Endpoint, AccessKeyId, AccessKeySecret, AuxiliaryTools.CovertToOssConf(Conf));

	return Client.DoesObjectExist(InBucketName, ObjectName);
}

bool SCOssManage::FOSS::DoesBucketExist()
{
	FAuxiliaryTools AuxiliaryTools;
	OssClient Client(Endpoint, AccessKeyId, AccessKeySecret, AuxiliaryTools.CovertToOssConf(Conf));

	return Client.DoesBucketExist(InBucketName);
}

bool SCOssManage::FOSS::ListObjects(TArray<FOSSObjectInfo>& ObjectName, int32 MaxNumber)
{
	FAuxiliaryTools AuxiliaryTools;
	OssClient Client(Endpoint, AccessKeyId, AccessKeySecret, AuxiliaryTools.CovertToOssConf(Conf));

	ListObjectsRequest Request(InBucketName);
	//设置列举最大个数
	Request.setMaxKeys(MaxNumber);

	auto Outcome = Client.ListObjects(Request);

	if (!Outcome.isSuccess())
	{
#if WITH_EDITOR
		OSSTOOL_MACRO_ERROR(Outcome);
#endif
		return false;
	}
	else
	{
		for (const auto& Object : Outcome.result().ObjectSummarys())
		{
			FOSSObjectInfo OSSObjectInfo;
			OSSObjectInfo.Name = FString(Object.Key().c_str());
			OSSObjectInfo.Size = Object.Size();
			OSSObjectInfo.LastModifyTime = FString(Object.LastModified().c_str());
			ObjectName.Add(OSSObjectInfo);
		}
	}
	return true;
}

bool SCOssManage::FOSS::ListObjectsByPrefix(const FString& InKeyPrefix, TArray<FOSSObjectInfo>& ObjectName, int32 MaxNumber)
{
	bool bSuccess = true;
	string KeyPrefix = TCHAR_TO_UTF8(*InKeyPrefix);

	FAuxiliaryTools AuxiliaryTools;
	OssClient Client(Endpoint, AccessKeyId, AccessKeySecret, AuxiliaryTools.CovertToOssConf(Conf));

	string nextMarker = "";
	ListObjectOutcome Outcome;
	do 
	{
		//列举文件
		ListObjectsRequest Request(InBucketName);

		//设置文件夹分隔符
		Request.setDelimiter("/");
		Request.setPrefix(KeyPrefix);
		Request.setMarker(nextMarker);

		Outcome = Client.ListObjects(Request);

		if (!Outcome.isSuccess())
		{
#if WITH_EDITOR
			OSSTOOL_MACRO_ERROR(Outcome);
#endif
			bSuccess = false;
			break;
		}

		for (const auto& Object : Outcome.result().ObjectSummarys())
		{
			FOSSObjectInfo OSSObjectInfo;
			OSSObjectInfo.Name = FString(Object.Key().c_str());
			OSSObjectInfo.Size = Object.Size();
			OSSObjectInfo.LastModifyTime = FString(Object.LastModified().c_str());
			ObjectName.Add(OSSObjectInfo);
		}
#if WITH_EDITOR
		for (const auto& CommonPrefix : Outcome.result().CommonPrefixes())
		{
			AuxiliaryTools.Print(CommonPrefix);
		}
#endif
		nextMarker = Outcome.result().NextMarker();
	} while (Outcome.result().IsTruncated());
	return bSuccess;
}

bool SCOssManage::FOSS::SetObjectStorageType(const FString& InObjectName, EOSSStorageType OSSStorageType)
{
	EOSSStorageType storageType = GetObjectStorageType(InObjectName);
	if (storageType != EOSSStorageType::NONE)
	{
		//枚举->字符串转换lamda函数
		auto SSStorage = [](EOSSStorageType OSSStorageType)->string
		{
			switch (OSSStorageType)
			{
			case SimpleOSS::OSS::EOSSStorageType::STANDARD:
				return "Standard";
			case SimpleOSS::OSS::EOSSStorageType::IA:
				return "IA";
			case SimpleOSS::OSS::EOSSStorageType::ARCHIVE:
				return "Archive";
			}
			return "";
		};

		string ObjectName = TCHAR_TO_UTF8(*InObjectName);

		FAuxiliaryTools AuxiliaryTools;
		OssClient Client(Endpoint, AccessKeyId, AccessKeySecret, AuxiliaryTools.CovertToOssConf(Conf));

		if (storageType == EOSSStorageType::ARCHIVE)
		{
			//判断文件是否为归档类型文件，是的话则需要等待解冻时间
			auto RestoreOutcome = Client.RestoreObject(InBucketName, ObjectName);
			if (!RestoreOutcome.isSuccess())
			{
#if WITH_EDITOR
				OSSTOOL_MACRO_ERROR(RestoreOutcome);
#endif
				return false;
			}

			std::string OnGoingRestore("ongoing-request=\"false\"");
			int32 MaxWaitTimeInSeconds = 600;
			while (MaxWaitTimeInSeconds > 0)
			{
				auto meta = Client.HeadObject(InBucketName, ObjectName);
				std::string RestoreStatus = meta.result().HttpMetaData()["x-oss-restore"];
				std::transform(RestoreStatus.begin(), RestoreStatus.end(), RestoreStatus.begin(), ::_tolower);
				if (!RestoreStatus.empty() && RestoreStatus.compare(0, OnGoingRestore.size(), OnGoingRestore) == 0)
				{
#if WITH_EDITOR
					//成功解冻
					AuxiliaryTools.Print(RestoreStatus);
#endif
					break;
				}
				std::this_thread::sleep_for(std::chrono::seconds(10));
				MaxWaitTimeInSeconds--;
			}
		}

		ObjectMetaData ObjectMeta;
		ObjectMeta.addHeader("x-oxx-storage-class", SSStorage(OSSStorageType));
		CopyObjectRequest Request(InBucketName, ObjectName);

		//修改文件储存类型
		auto Outcome = Client.CopyObject(Request);

		if (!Outcome.isSuccess())
		{
#if WITH_EDITOR
			OSSTOOL_MACRO_ERROR(Outcome);
#endif
			return false;
		}
		return true;
	}
	return false;
}

EOSSStorageType SCOssManage::FOSS::GetObjectStorageType(const FString& InObjectName)
{
	FOSSObjectMeta OSSobjectInfo;
	if (GetObjectMeta(InObjectName, OSSobjectInfo))
	{
		//字符串->枚举转换lamda函数
		auto SSStorage = [](const FString& OSSStorageType)->EOSSStorageType
		{
			if (OSSStorageType == "Standard")
			{
				return EOSSStorageType::STANDARD;
			}
			else if (OSSStorageType == "IA")
			{
				return EOSSStorageType::IA;
			}
			else if (OSSStorageType == "Archive")
			{
				return EOSSStorageType::ARCHIVE;
			}
			else
			{
				return EOSSStorageType::NONE;
			}
		};
		return SSStorage(OSSobjectInfo.x_oss_storage_class);
	}
	return EOSSStorageType::NONE;
}

bool SCOssManage::FOSS::CreateSymlink(const FString& InObjectName, const FString& InLinkObjectName)
{
	string ObjectName = TCHAR_TO_UTF8(*InObjectName);
	string LinkObjectName = TCHAR_TO_UTF8(*InLinkObjectName);

	FAuxiliaryTools AuxiliaryTools;
	OssClient Client(Endpoint, AccessKeyId, AccessKeySecret, AuxiliaryTools.CovertToOssConf(Conf));

	//创建软链接
	auto Meta = ObjectMetaData();
	CreateSymlinkRequest Request(InBucketName, ObjectName, Meta);
	Request.SetSymlinkTarget(LinkObjectName);
	auto Outcome = Client.CreateSymlink(Request);
	if (!Outcome.isSuccess())
	{
#if WITH_EDITOR
		OSSTOOL_MACRO_ERROR(Outcome);
#endif
		return false;
	}
	return true;
}

FString SCOssManage::FOSS::GetSymlink(const FString& InLinkName)
{
	string LinkName = TCHAR_TO_UTF8(*InLinkName);

	FAuxiliaryTools AuxiliaryTools;
	OssClient Client(Endpoint, AccessKeyId, AccessKeySecret, AuxiliaryTools.CovertToOssConf(Conf));

	//获得软链接
	GetSymlinkRequest Request(InBucketName, LinkName);
	auto Outcome = Client.GetSymlink(Request);
	if (!Outcome.isSuccess())
	{
#if WITH_EDITOR
		OSSTOOL_MACRO_ERROR(Outcome);
#endif
		return "";
	}
	return Outcome.result().SymlinkTarget().c_str();
}

bool SCOssManage::FOSS::PutObjectByMemory(const FString& InObjectName, ProgressCallback InprogressCallback, const TMap<FString, FString>& CustomMeta, const FOSSObjectMeta& OSSobjectMeta, const FString& DebugMsg)
{
	string ObjectName = TCHAR_TO_UTF8(*InObjectName);

	FAuxiliaryTools AuxiliaryTools;
	OssClient Client(Endpoint, AccessKeyId, AccessKeySecret, AuxiliaryTools.CovertToOssConf(Conf));

	std::shared_ptr<std::iostream> content = std::make_shared<std::stringstream>();
	*content << *DebugMsg;

	PutObjectRequest Request(InBucketName, ObjectName, content);

	OSSTOOL_MACRO_META(Request);

	auto Outcome = Client.PutObject(Request);

	if (!Outcome.isSuccess())
	{
#if WITH_EDITOR
		OSSTOOL_MACRO_ERROR(Outcome);
#endif
		return false;
	}
	return true;
}

bool SCOssManage::FOSS::PutObjectByLocal(const FString& InLocalPaths, const FString& InObjectName, ProgressCallback InprogressCallback, const TMap<FString, FString>& CustomMeta, const FOSSObjectMeta& OSSobjectMeta, const FString& DebugMsg)
{
	FScopeLock ScopeLock(&Mutex);

	FAuxiliaryTools AuxiliaryTools;
	OssClient Client(Endpoint, AccessKeyId, AccessKeySecret, AuxiliaryTools.CovertToOssConf(Conf));

	std::shared_ptr<std::iostream> content = std::make_shared<std::fstream>(TCHAR_TO_UTF8(*InLocalPaths), std::ios::in | std::ios::binary);

	PutObjectRequest Request(InBucketName, TCHAR_TO_UTF8(*InObjectName), content);

	OSSTOOL_MACRO_META(Request);

	auto Outcome = Client.PutObject(Request);

	if (!Outcome.isSuccess())
	{
#if WITH_EDITOR
		OSSTOOL_MACRO_ERROR(Outcome);
#endif
		return false;
	}
	return true;
}

void SCOssManage::FOSS::AsyncPutObject(const FString& InLocalPaths, const FString& InObjectName, ProgressCallback InprogressCallback /*= nullptr*/, const TMap<FString, FString>& CustomMeta /*= TMap<FString, FString>()*/, const FOSSObjectMeta& OSSobjectMeta /*= FOSSObjectMeta()*/, const FString& DebugMsg /*= TEXT("Thank you for using Oss Storage Service!")*/)
{
	auto Lamada = [=]()
	{
		PutObjectByLocal(InLocalPaths, InObjectName, InprogressCallback, CustomMeta, OSSobjectMeta, DebugMsg);
	};

	//创建一个异步
	(new FAutoDeleteAsyncTask<FOSSAsynTask>(Lamada))->StartBackgroundTask();
}

bool SCOssManage::FOSS::ResumableUploadObject(const FString& InObjectName, const FString& InUploadFilePath, const FString& InCheckpointFilePath, ProgressCallback InprogressCallback, const TMap<FString, FString>& CustomMeta, const FOSSObjectMeta& OSSobjectMeta, const FString& DebugMsg)
{
	FScopeLock ScopeLock(&Mutex);
	string ObjectName = TCHAR_TO_UTF8(*InObjectName);
	string UploadFilePath = TCHAR_TO_UTF8(*InUploadFilePath);
	string CheckpointFilePath = TCHAR_TO_UTF8(*InCheckpointFilePath);

	FAuxiliaryTools AuxiliaryTools;
	OssClient Client(Endpoint, AccessKeyId, AccessKeySecret, AuxiliaryTools.CovertToOssConf(Conf));

	UploadObjectRequest Request(InBucketName, ObjectName, UploadFilePath, CheckpointFilePath);

	OSSTOOL_MACRO_META(Request);

	auto Outcome = Client.ResumableUploadObject(Request);
	if (!Outcome.isSuccess())
	{
#if WITH_EDITOR
		OSSTOOL_MACRO_ERROR(Outcome);
#endif
		return false;
	}
	return true;
}

void SCOssManage::FOSS::AsyncResumableUploadObject(const FString& InObjectName, const FString& InUploadFilePath, const FString& InCheckpointFilePath, ProgressCallback InprogressCallback, const TMap<FString, FString>& CustomMeta, const FOSSObjectMeta& OSSobjectMeta, const FString& DebugMsg)
{
	auto Lamada = [=]()
	{
		ResumableUploadObject(InObjectName, InUploadFilePath, InCheckpointFilePath, InprogressCallback, CustomMeta, OSSobjectMeta, DebugMsg);
	};

	//创建一个异步
	(new FAutoDeleteAsyncTask<FOSSAsynTask>(Lamada))->StartBackgroundTask();
}

bool SCOssManage::FOSS::UploadPart(FString& InUploadId, const FString& InObjectName, const FString& InLocalPaths, int32 PartSize, ProgressCallback InprogressCallback, const TMap<FString, FString>& CustomMeta, const FOSSObjectMeta& OSSobjectMeta, const FString& DebugMsg)
{
	FScopeLock ScopeLock(&Mutex);
	string ObjectName = TCHAR_TO_UTF8(*InObjectName);
	string FileToUpload = TCHAR_TO_UTF8(*InLocalPaths);

	FAuxiliaryTools AuxiliaryTools;
	OssClient Client(Endpoint, AccessKeyId, AccessKeySecret, AuxiliaryTools.CovertToOssConf(Conf));

	InitiateMultipartUploadRequest InitUploadRequest(InBucketName, ObjectName);
	auto uploadIdResult = Client.InitiateMultipartUpload(InitUploadRequest);
	auto uploadId = uploadIdResult.result().UploadId();

	PartList partETagList;

	auto fileSize = AuxiliaryTools.GetFileSize(FileToUpload);
	int32 partCount = static_cast<int32>(fileSize / PartSize);

	//计算分片数量
	if (fileSize % PartSize != 0)
	{
		partCount++;
	}

	for (int32 i = 1; i <= partCount; ++i)
	{
		auto skipBytes = PartSize * (i - 1);
		auto size = (PartSize < fileSize - skipBytes) ? PartSize : (fileSize - skipBytes);
		std::shared_ptr<std::iostream> content = std::make_shared<std::fstream>(FileToUpload, std::ios::in | std::ios::binary);
		
		UploadPartRequest uploadPartRequest(InBucketName, ObjectName, content);
		uploadPartRequest.setContentLength(size);
		uploadPartRequest.setUploadId(uploadId);
		uploadPartRequest.setPartNumber(i);

		auto uploadPartOutcome = Client.UploadPart(uploadPartRequest);
		if (uploadPartOutcome.isSuccess())
		{
			Part part(i, uploadPartOutcome.result().ETag());
			partETagList.push_back(part);
		}
		else
		{
#if WITH_EDITOR
			OSSTOOL_MACRO_ERROR(uploadPartOutcome);
#endif
		}
	}

	CompleteMultipartUploadRequest Request(InBucketName, ObjectName);
	Request.setUploadId(uploadId);
	Request.setPartList(partETagList);

	OSSTOOL_MACRO_META(Request);

	auto Outcome = Client.CompleteMultipartUpload(Request);
	if (!Outcome.isSuccess())
	{
#if WITH_EDITOR
		OSSTOOL_MACRO_ERROR(Outcome);
#endif
		return false;
	}
	InUploadId = uploadId.c_str();
	return true;
}

void SCOssManage::FOSS::AsyncUploadPart(FString& InUploadId,const FString& InObjectName, const FString& InLocalPaths, int32 PartSize /*= 1024 * 1024 * 10*/, ProgressCallback InprogressCallback /*= nullptr*/, const TMap<FString, FString>& CustomMeta /*= TMap<FString, FString>()*/, const FOSSObjectMeta& OSSobjectMeta /*= FOSSObjectMeta()*/, const FString& DebugMsg /*= TEXT("Thank you for using Oss Storage Service!")*/)
{
	auto Lamada = [=]()
	{
		FString NewUploadId = InUploadId;
		UploadPart(NewUploadId, InObjectName, InLocalPaths, PartSize, InprogressCallback, CustomMeta, OSSobjectMeta, DebugMsg);
	};

	//创建一个异步
	(new FAutoDeleteAsyncTask<FOSSAsynTask>(Lamada))->StartBackgroundTask();
}

bool SCOssManage::FOSS::AbortMultipartUpload(const FString& InObjectName, const FString& InUploadId)
{
	string ObjectName = TCHAR_TO_UTF8(*InObjectName);
	string UploadId = TCHAR_TO_UTF8(*InUploadId);

	FAuxiliaryTools AuxiliaryTools;
	OssClient Client(Endpoint, AccessKeyId, AccessKeySecret, AuxiliaryTools.CovertToOssConf(Conf));

	AbortMultipartUploadRequest abortUploadRequest(InBucketName, ObjectName, UploadId);
	auto abortUploadIdResult = Client.AbortMultipartUpload(abortUploadRequest);
	if (!abortUploadIdResult.isSuccess())
	{
#if WITH_EDITOR
		OSSTOOL_MACRO_ERROR(abortUploadIdResult);
#endif
		return false;
	}
	return true;
}

bool SCOssManage::FOSS::GetObjectToMemory(const FString& InObjectName, FString& ContextString, SimpleOSS::OSS::FRange Range,ProgressCallback InprogressCallback)
{
	string ObjectName = TCHAR_TO_UTF8(*InObjectName);
	
	FAuxiliaryTools AuxiliaryTools;
	OssClient Client(Endpoint, AccessKeyId, AccessKeySecret, AuxiliaryTools.CovertToOssConf(Conf));

	GetObjectRequest Request(InBucketName, ObjectName);
	TransferProgress progressCallback = { InprogressCallback , nullptr };
	Request.setTransferProgress(progressCallback);
	if (Range.IsValid())
	{
		Request.setRange(Range.Start, Range.End);
	}

	auto Outcome = Client.GetObject(Request);
	if (Outcome.isSuccess())
	{
#if WITH_EDITOR
		AuxiliaryTools.Print(FString::FromInt(Outcome.result().Metadata().ContentLength()));
#endif
		//打印下载内容
		auto& stream = Outcome.result().Content();
		char buffer[256];

		while (stream->good()) {
			stream->read(buffer, 256);
			auto count = stream->gcount();
			/*根据实际情况处理数据。*/
		}
	}
	else
	{
#if WITH_EDITOR
		OSSTOOL_MACRO_ERROR(Outcome);
#endif
		return false;
	}
	return true;
}

bool SCOssManage::FOSS::GetObjectToLocal(const FString& InObjectName, FString& InLocalPaths, SimpleOSS::OSS::FRange Range,ProgressCallback InprogressCallback)
{
	FScopeLock ScopeLock(&Mutex);
	string ObjectName = TCHAR_TO_UTF8(*InObjectName);
	string FileNametoSave = TCHAR_TO_UTF8(*InLocalPaths);

	FAuxiliaryTools AuxiliaryTools;
	OssClient Client(Endpoint, AccessKeyId, AccessKeySecret, AuxiliaryTools.CovertToOssConf(Conf));

	GetObjectRequest Request(InBucketName, ObjectName);
	Request.setResponseStreamFactory([=]() {return std::make_shared<std::fstream>(FileNametoSave, std::ios_base::out | std::ios_base::in | std::ios_base::trunc | std::ios_base::binary); });

	TransferProgress progressCallback = { InprogressCallback , nullptr };
	Request.setTransferProgress(progressCallback);
	if (Range.IsValid())
	{
		Request.setRange(Range.Start, Range.End);
	}

	auto Outcome = Client.GetObject(Request);
	if (!Outcome.isSuccess())
	{
#if WITH_EDITOR
		OSSTOOL_MACRO_ERROR(Outcome);
#endif
		return false;
	}
	return true;
}

void SCOssManage::FOSS::AsyncGetObjectToLocal(const FString& InObjectName, FString& InLocalPaths, SimpleOSS::OSS::FRange Range /*= FRange()*/, ProgressCallback InprogressCallback /*= nullptr*/)
{
	auto Lamada = [=]()
	{
		FString NewInLocalPaths = InLocalPaths;
		GetObjectToLocal(InObjectName, NewInLocalPaths, Range, InprogressCallback);
	};
}

bool SCOssManage::FOSS::ResumableDownloadObject(const FString& InObjectName, FString& InDownloadFilePath, const FString& InCheckpointFilePath, SimpleOSS::OSS::FRange Range, ProgressCallback InprogressCallback)
{
	FScopeLock ScopeLock(&Mutex);
	string ObjectName = TCHAR_TO_UTF8(*InObjectName);
	string DownloadFilePath = TCHAR_TO_UTF8(*InDownloadFilePath);
	string CheckpointFilePath = TCHAR_TO_UTF8(*InCheckpointFilePath);

	FAuxiliaryTools AuxiliaryTools;
	OssClient Client(Endpoint, AccessKeyId, AccessKeySecret, AuxiliaryTools.CovertToOssConf(Conf));

	DownloadObjectRequest Request(InBucketName, ObjectName, DownloadFilePath, CheckpointFilePath);
	TransferProgress progressCallback = { InprogressCallback , nullptr };
	Request.setTransferProgress(progressCallback);
	if (Range.IsValid())
	{
		Request.setRange(Range.Start, Range.End);
	}

	auto Outcome = Client.ResumableDownloadObject(Request);
	if (!Outcome.isSuccess())
	{
#if WITH_EDITOR
		OSSTOOL_MACRO_ERROR(Outcome);
#endif
		return false;
	}
	return true;
}

void SCOssManage::FOSS::AsyncResumableDownloadObject(const FString& InObjectName, FString& InDownloadFilePath, const FString& InCheckpointFilePath, SimpleOSS::OSS::FRange Range, ProgressCallback InprogressCallback)
{
	auto Lamada = [=]()
	{
		FString NewDownloadFilePath = InDownloadFilePath;
		ResumableDownloadObject(InObjectName, NewDownloadFilePath, InCheckpointFilePath, Range, InprogressCallback);
	};

	//创建一个异步
	(new FAutoDeleteAsyncTask<FOSSAsynTask>(Lamada))->StartBackgroundTask();
}

bool SCOssManage::FOSS::CopyObject(const FString& InSourceBucketName, const FString& InSourceObjectName, const FString& InCopyBucketName, const FString& InCopyObjectName, ProgressCallback InProgressCallback)
{
	FScopeLock ScopeLock(&Mutex);
	string SourceBucketName = TCHAR_TO_UTF8(*InSourceBucketName);
	string SourceObjectName = TCHAR_TO_UTF8(*InSourceObjectName);
	string CopyBucketName = TCHAR_TO_UTF8(*InCopyBucketName);
	string CopyObjectName = TCHAR_TO_UTF8(*InCopyObjectName);

	FAuxiliaryTools AuxiliaryTools;
	OssClient Client(Endpoint, AccessKeyId, AccessKeySecret, AuxiliaryTools.CovertToOssConf(Conf));

	CopyObjectRequest Request(CopyBucketName, CopyObjectName);
	Request.setCopySource(SourceBucketName, SourceObjectName);

	TransferProgress progressCallback = { InProgressCallback,nullptr };
	Request.setTransferProgress(progressCallback);

	auto Outcome = Client.CopyObject(Request);
	if (!Outcome.isSuccess())
	{
#if WITH_EDITOR
		OSSTOOL_MACRO_ERROR(Outcome);
#endif
		return false;
	}
	return true;
}

void SCOssManage::FOSS::AsyncCopyObject(const FString& InSourceBucketName, const FString& InSourceObjectName, const FString& InCopyBucketName, const FString& InCopyObjectName, ProgressCallback InProgressCallback /*= nullptr*/)
{
	auto Lamada = [=]()
	{
		CopyObject(InSourceBucketName, InSourceObjectName, InCopyBucketName, InCopyObjectName, InProgressCallback);
	};

	//创建一个异步
	(new FAutoDeleteAsyncTask<FOSSAsynTask>(Lamada))->StartBackgroundTask();
}

bool SCOssManage::FOSS::DeleteObject(const FString& InObjectName, ProgressCallback InProgressCallback)
{
	TArray<FString> MyObjectName;
	MyObjectName.Add(InObjectName);
	return DeleteObjects(MyObjectName, InProgressCallback);
}

bool SCOssManage::FOSS::DeleteObjects(const TArray<FString>& InObjectName, ProgressCallback InProgressCallback)
{
	FAuxiliaryTools AuxiliaryTools;
	OssClient Client(Endpoint, AccessKeyId, AccessKeySecret, AuxiliaryTools.CovertToOssConf(Conf));

	DeleteObjectsRequest Request(InBucketName);
	TransferProgress progressCallback = { InProgressCallback,nullptr };
	Request.setTransferProgress(progressCallback);

	for (const auto& Tmp : InObjectName)
	{
		string ObjectName = TCHAR_TO_UTF8(*Tmp);
		Request.addKey(ObjectName);
	}

	auto Outcome = Client.DeleteObjects(Request);
	if (!Outcome.isSuccess())
	{
#if WITH_EDITOR
		OSSTOOL_MACRO_ERROR(Outcome);
#endif
		return false;
	}
	return true;
}

void SCOssManage::FOSS::AsyncDeleteObjects(const TArray<FString>& InObjectName, ProgressCallback InProgressCallback /*= nullptr*/)
{
	auto Lamada = [=]()
	{
		DeleteObjects(InObjectName, InProgressCallback);
	};

	//创建一个异步
	(new FAutoDeleteAsyncTask<FOSSAsynTask>(Lamada))->StartBackgroundTask();
}

bool SCOssManage::FOSS::ListMultipartUploads(TArray<FMultipartPartsUploadsInfo>& MultipartPartsInfo, int MaxParts)
{
	bool bSuccess = true;

	FAuxiliaryTools AuxiliaryTools;
	OssClient Client(Endpoint, AccessKeyId, AccessKeySecret, AuxiliaryTools.CovertToOssConf(Conf));

	ListMultipartUploadsRequest listMultiUploadRequest(InBucketName);
	listMultiUploadRequest.setMaxUploads(MaxParts);

	ListMultipartUploadsOutcome listResult;
	do
	{
		listResult = Client.ListMultipartUploads(listMultiUploadRequest);
		if (!listResult.isSuccess())
		{
#if WITH_EDITOR
			OSSTOOL_MACRO_ERROR(listResult);
#endif
			bSuccess = false;
			break;
		}
		else
		{
			for (const auto& part : listResult.result().MultipartUploadList())
			{
				FMultipartPartsUploadsInfo MultipartpartsUploadsInfo;
				MultipartpartsUploadsInfo.Key = part.Key.c_str();
				MultipartpartsUploadsInfo.UploadId = part.UploadId.c_str();
				MultipartpartsUploadsInfo.Initiated = part.Initiated.c_str();
				MultipartPartsInfo.Add(MultipartpartsUploadsInfo);
			}
		}
		listMultiUploadRequest.setKeyMarker(listResult.result().NextKeyMarker());
		listMultiUploadRequest.setUploadIdMarker(listResult.result().NextUploadIdMarker());
	} while (listResult.result().IsTruncated());
	return bSuccess;
}

bool SCOssManage::FOSS::GetImageObjectResize(const FVector2D& Size, const FString& InObjectName, const FString& InFileNametoSave)
{
	//拼接相应command
	FString Command = FString::Printf(TEXT("image/resize,m_fixed,w_%i,h_%i"), (int32)Size.X, (int32)Size.Y);
	return GetImageObject(InObjectName, InFileNametoSave, Command);;
}

bool SCOssManage::FOSS::GetImageObjectCrop(const FVector4& Size, int32 Ratio, const FString& InObjectName, const FString& InFileNametoSave)
{
	//拼接相应command
	FString Command = FString::Printf(TEXT("image/crop,w_%i,h_%i,x_%i,y_%i,r_%i"), (int32)Size.X, (int32)Size.Y, (int32)Size.Z, (int32)Size.W, (int32)Ratio);
	return GetImageObject(InObjectName, InFileNametoSave, Command);;
}

bool SCOssManage::FOSS::GetImageObjectSharpen(const int32 Sharpen, const FString& InObjectName, const FString& InFileNametoSave)
{
	//拼接相应command
	FString Command = FString::Printf(TEXT("image/shaarpen,%d"), Sharpen);
	return GetImageObject(InObjectName, InFileNametoSave, Command);;
}

bool SCOssManage::FOSS::GetImageObjectWaterMark(const FString& WaterMarkObjectName, const FString& InObjectName, const FString& InFileNametoSave)
{
	//拼接相应command
	FString Command = FString::Printf(TEXT("image/watermark,%s"), *WaterMarkObjectName);
	return GetImageObject(InObjectName, InFileNametoSave, Command);
}

bool SCOssManage::FOSS::GetImageObjectStyle(const FString& OSSStyleName, const FString& InObjectName, const FString& InFileNametoSave)
{
	//拼接相应command
	FString Command = FString::Printf(TEXT("style/%s"), *OSSStyleName);
	return GetImageObject(InObjectName, InFileNametoSave, Command);;
}

bool SCOssManage::FOSS::GetImageObjectCascade(const TArray<FString>& CascadeCommand, const FString& InObjectName, const FString& InFileNametoSave)
{
	FString Command;
	for (auto& Tmp : CascadeCommand)
	{
		Command /= Tmp;
	}
	Command.RemoveFromStart(TEXT("/"));
	return GetImageObject(InObjectName, InFileNametoSave, Command);;
}

bool SCOssManage::FOSS::GetImageObject(const FString& InObjectName, const FString& InFileNametoSave, const FString& Command)
{
	string ObjectName = TCHAR_TO_UTF8(*InObjectName);
	string FileNameToSave = TCHAR_TO_UTF8(*InFileNametoSave);
	string Process = TCHAR_TO_UTF8(*Command);

	FAuxiliaryTools AuxiliaryTools;
	OssClient Client(Endpoint, AccessKeyId, AccessKeySecret, AuxiliaryTools.CovertToOssConf(Conf));

	GetObjectRequest Request(InBucketName, ObjectName);

	Request.setResponseStreamFactory([=]()
	{
		return std::make_shared<std::fstream>
		(
			FileNameToSave,
			std::ios_base::out |
			std::ios_base::in |
			std::ios_base::trunc |
			std::ios_base::binary
		);
	});
	Request.setProcess(Process);

	auto Outcome = Client.GetObject(Request);
	if (!Outcome.isSuccess())
	{
#if WITH_EDITOR
		OSSTOOL_MACRO_ERROR(Outcome);
#endif
		return false;
	}
	return true;
}

FClientConfiguration::FClientConfiguration()
	:Scheme(OSS::Scheme::HTTP)
	,MaxConnections(16)
	,RequestTimeoutMs(10000)
	,ConnectTimeoutMs(5000)
	,ProxyScheme(OSS::Scheme::HTTP)
	,ProxyPort(0)
	,bVerifySSL(false)
	,bCname(false)
	,bEnableCrc64(true)
	,bEnableDateSkewAdjustment(true)
	,SendRateLimiter(0)
	,RecvRateLimiter(0)
{

}