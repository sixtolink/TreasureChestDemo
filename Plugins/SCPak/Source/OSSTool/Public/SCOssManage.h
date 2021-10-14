// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SCOssType.h"
#include "Misc/Paths.h"

#include <string>

#if PLATFORM_WINDOWS
#include "Windows/WindowsCriticalSection.h"
#else
#if PLATFORM_LINUX
#include "Linux/LinuxCriticalSection.h"
#else
#if PLATFORM_MAC
#include "Mac/MacCriticalSection.h"
#endif // PLATFORM_MAC
#endif // PLATFORM_LINUX
#endif // PLATFORM_WINDOWS

#define OSSTOOL SCOssManage::Get()->GetOSS()

using namespace std;

/**
 *
 */
class OSSTOOL_API SCOssManage
{
public:
	SCOssManage();
	~SCOssManage();

	static SCOssManage* Get();

	static void Destroy();

	struct OSSTOOL_API FOSS
	{

#pragma region Init

		void InitAccounts();

		void InitConf(const FClientConfiguration& InConf);

#pragma endregion Init

#pragma region Bucket
		//桶处理
		///////////////////////////////////////////////////////////////////////////////////////////////////////
		
		/**
		*创建桶
		*InBucketName:创建桶名称
		*/
		bool CreateBucket(EOSSStorageType OSSStorageType = EOSSStorageType::IA, EAcl Acl = EAcl::PUBLICREAD);

		/**
		*列举桶
		*InBucketName:得到的桶合集
		*/
		bool ListBuckets(TArray<FString>& BucketNameArray);
		
		/**
		*获取桶所在地域
		*InBucketName:需要找地域的桶
		*InLocation:返回的地域
		*/
		bool GetBucketLocation();
		
		/**
		*删除桶
		*InBucketName:需要删除的桶
		*/
		bool DeleteBucket();
		
		/**
		*设置桶权限
		*InBucketName:需要设置权限的桶
		*BucketAcl:新权限
		*/
		bool SetBucketAcl(EAcl BucketAcl = EAcl::DEFAULT);
		
		/**
		*获取桶权限
		*InBucketName:需要获取权限的桶
		*/
		EAcl GetBucketAcl();
		
		/**
		*设置桶的请求者付费模式
		*InBucketName:桶名称
		*RequestPayer:请求者模式
		*/
		bool SetBucketRequestPayment(ERequestPayerType InRequestPayer = ERequestPayerType::NOTSET);
		
		/**
		*获取桶的请求者付费模式
		*InBucketName:桶名称
		*/
		ERequestPayerType GetBucketRequestPayment();
		
		/**
		*设置防盗链
		*InBucketName:桶名称
		*URLRefererList:防盗链列表
		*bAllowEmptyReferer:是否允许空链
		*/
		bool SetBucketReferer(const TArray<FString>&URLReferer, bool bAllowEmptyReferer = false);
		
		/**
		*获取桶防盗链列表
		*InBucketName:桶名称
		*/
		FRefererList GetBucketReferer();
		
		/**
		*删除防盗链
		*InBucketName:桶名称
		*URLReferer:防盗链列表
		*bAllowEmptyReferer:是否允许空的链
		*/
		bool DeleteBucketReferer(bool bAllowEmptyReferer = true);

		/**
		*是否存在桶
		*InBucketName:桶名称
		*/
		bool DoesBucketExist();

#pragma endregion Bucket

#pragma region Object

		//对象处理
		///////////////////////////////////////////////////////////////////////////////////////////////////////
		/**
		*获取对象元数据
		*InBucketName:桶名称
		*InObjectName:对象名
		*FOSSObjectMeta:返回的对象信息
		*第一种有内存拷贝(降低效率
		*/
		//FOSSObjectMeta GetObjectMeta(const FString& InBucketName, const FString& InObjectName);
		bool GetObjectMeta(const FString& InObjectName, FOSSObjectMeta& OSSObjectInfo);

		/**
		*获取对象读写权限
		*InBucketName:桶名称
		*InObjectName:对象名
		*枚举不太占空间，因此适当允许拷贝，直接返回使用更方便
		*/
		EAcl GetObjectAcl(const FString& InObjectName);
		
		/**
		*设置对象读写权限
		*InBucketName:桶名称
		*InObjectName:对象名
		*/
		bool SetObjectAcl(const FString& InObjectName, EAcl InAcl = EAcl::DEFAULT);
		
		/**
		*是否存在对象
		*InBucketName:桶名称
		*InObjectName:对象名
		*/
		bool DoesObjectExist(const FString& InObjectName);
		
		/**
		*列举对象
		*InBucketName:桶名称
		*InObjectNames:列举对象名
		*MaxNumber:列举个数
		*/
		bool ListObjects(TArray<FOSSObjectInfo>& ObjectName, int32 MaxNumber = 100);
		
		/**
		*递归列举对象
		*InBucketName:桶名称
		*InKeyPrefix:目录
		*InObjectNames:列举对象名
		*MaxNumber:列举个数
		*/
		bool ListObjectsByPrefix(const FString& InKeyPrefix, TArray<FOSSObjectInfo>& ObjectName, int32 MaxNumber = 100);
		
		/**
		*设置对象储存类型
		*InBucketName:桶名称
		*InObjectNames:对象名
		*OSSStorageType:储存类型
		*/
		bool SetObjectStorageType(const FString& InObjectName, EOSSStorageType OSSStorageType = EOSSStorageType::IA);
		
		/**
		*获取对象储存类型
		*InBucketName:桶名称
		*InObjectNames:对象名
		*/
		EOSSStorageType GetObjectStorageType(const FString& InObjectName);
		
		/**
		*创建对象软链接（快捷方式
		*InBucketName:桶名称
		*InObjectNames:对象名
		*InLinkObjectName:链接名
		*/
		bool CreateSymlink(const FString& InObjectName, const FString& InLinkObjectName);
		
		/**
		*获取软链接指向的文件
		*InBucketName:桶名称
		*InLinkObjectName:链接名
		*/
		FString GetSymlink(const FString& InLinkName);

		/**
		*拷贝对象
		*InSourceBucketName:原桶名称
		*InSourceObjectName:原对象名
		*InCopyBucketName:拷贝桶名称
		*InCopyObjectName:拷贝对象名
		*第一种有内存拷贝(降低效率
		*/
		bool CopyObject(const FString& InSourceBucketName, const FString& InSourceObjectName, const FString& InCopyBucketName, const FString& InCopyObjectName, ProgressCallback InProgressCallback = nullptr);
		
		/**
		*异步拷贝对象
		*InSourceBucketName:原桶名称
		*InSourceObjectName:原对象名
		*InCopyBucketName:拷贝桶名称
		*InCopyObjectName:拷贝对象名
		*第一种有内存拷贝(降低效率
		*/
		void AsyncCopyObject(const FString& InSourceBucketName, const FString& InSourceObjectName, const FString& InCopyBucketName, const FString& InCopyObjectName, ProgressCallback InProgressCallback = nullptr);

		/**
		*删除单个对象
		*InBucketName:桶名称
		*InObjectName:对象名
		*/
		bool DeleteObject(const FString& InObjectName, ProgressCallback InProgressCallback = nullptr);

		/**
		*删除多个对象
		*InBucketName:桶名称
		*InObjectName:对象名
		*InProgressCallback:回调函数
		*/
		bool DeleteObjects(const TArray<FString>& InObjectName, ProgressCallback InProgressCallback = nullptr);
		
		/**
		*异步删除多个对象
		*InBucketName:桶名称
		*InObjectName:对象名
		*InProgressCallback:回调函数
		*/
		void AsyncDeleteObjects(const TArray<FString>& InObjectName, ProgressCallback InProgressCallback = nullptr);

		/**
		*列举上传分片
		*InUploadId:上传名
		*InBucketName:桶名称
		*InObjectName:对象名
		*PartsInfo:分片信息
		*MaxParts:列举最大数量
		*/
		bool ListMultipartUploads(TArray<FMultipartPartsUploadsInfo>& MultipartPartsInfo, int MaxParts = 1000);

#pragma endregion Object

#pragma region Upload

		//上传处理
		///////////////////////////////////////////////////////////////////////////////////////////////////////

		/**
		*从内存上传资源
		*InBucketName:桶名称
		*InObjectName:对象名
		*InprogressCallback:回调函数
		*CustomMeta:自定义元数据
		*OSSobjectMeta:OSS元数据
		*DebugMsg:debug信息
		*/
		bool PutObjectByMemory(const FString& InObjectName, ProgressCallback InprogressCallback = nullptr, const TMap<FString, FString>& CustomMeta = TMap<FString, FString>(), const FOSSObjectMeta& OSSobjectMeta = FOSSObjectMeta(), const FString& DebugMsg = TEXT("Thank you for using Oss Storage Service!"));
		
		/**
		*从本地上传资源（本质也是加载到内存然后上传
		*InBucketName:桶名称
		*InLocalPaths:本地路径
		*InprogressCallback:回调函数
		*CustomMeta:自定义元数据
		*OSSobjectMeta:OSS元数据
		*DebugMsg:debug信息
		*/
		bool PutObjectByLocal(const FString& InLocalPaths, const FString& InObjectName, ProgressCallback InprogressCallback = nullptr, const TMap<FString, FString>& CustomMeta = TMap<FString, FString>(), const FOSSObjectMeta& OSSobjectMeta = FOSSObjectMeta(), const FString& DebugMsg = TEXT("Thank you for using Oss Storage Service!"));
		
		/**
		*异步从本地上传资源（本质也是加载到内存然后上传
		*InBucketName:桶名称
		*InLocalPaths:本地路径
		*InprogressCallback:回调函数
		*CustomMeta:自定义元数据
		*OSSobjectMeta:OSS元数据
		*DebugMsg:debug信息
		*/
		void AsyncPutObject(const FString& InLocalPaths, const FString& InObjectName, ProgressCallback InprogressCallback = nullptr, const TMap<FString, FString>& CustomMeta = TMap<FString, FString>(), const FOSSObjectMeta& OSSobjectMeta = FOSSObjectMeta(), const FString& DebugMsg = TEXT("Thank you for using Oss Storage Service!"));

		/**
		*断点续传
		*InObjectName:目标文件名
		*InUploadFilePath:上传路径
		*InCheckpointFilePath:分片缓存路径
		*InprogressCallback:回调函数
		*CustomMeta:自定义元数据
		*OSSobjectMeta:OSS元数据
		*DebugMsg:debug信息
		*/
		bool ResumableUploadObject(const FString& InObjectName, const FString& InUploadFilePath, const FString& InCheckpointFilePath = FPaths::ProjectSavedDir() / TEXT("OSSCache"), ProgressCallback InprogressCallback = nullptr, const TMap<FString, FString>& CustomMeta = TMap<FString, FString>(), const FOSSObjectMeta& OSSobjectMeta = FOSSObjectMeta(), const FString& DebugMsg = TEXT("Thank you for using Oss Storage Service!"));
		
		/**
		*异步断点续传
		*InObjectName:目标文件名
		*InUploadFilePath:上传路径
		*InCheckpointFilePath:分片缓存路径
		*InprogressCallback:回调函数
		*CustomMeta:自定义元数据
		*OSSobjectMeta:OSS元数据
		*DebugMsg:debug信息
		*/
		void AsyncResumableUploadObject(const FString& InObjectName, const FString& InUploadFilePath, const FString& InCheckpointFilePath = FPaths::ProjectSavedDir() / TEXT("OSSCache"), ProgressCallback InprogressCallback = nullptr, const TMap<FString, FString>& CustomMeta = TMap<FString, FString>(), const FOSSObjectMeta& OSSobjectMeta = FOSSObjectMeta(), const FString& DebugMsg = TEXT("Thank you for using Oss Storage Service!"));
		
		/**
		*分片上传
		*InUploadId:上传ID
		*InBucketName:桶名称
		*InObjectName:对象名称
		*InLocalPaths:本地路径
		*PartSize:分片大小
		*InprogressCallback:回调函数
		*CustomMeta:自定义元数据
		*OSSobjectMeta:OSS元数据
		*DebugMsg:debug信息
		*/
		bool UploadPart(FString& InUploadId, const FString& InObjectName, const FString& InLocalPaths, int32 PartSize = 1024 * 1024 * 10, ProgressCallback InprogressCallback = nullptr, const TMap<FString, FString>& CustomMeta = TMap<FString, FString>(), const FOSSObjectMeta& OSSobjectMeta = FOSSObjectMeta(), const FString& DebugMsg = TEXT("Thank you for using Oss Storage Service!"));
		
		/**
		*异步分片上传
		*InUploadId:上传ID
		*InBucketName:桶名称
		*InObjectName:对象名称
		*InLocalPaths:本地路径
		*PartSize:分片大小
		*InprogressCallback:回调函数
		*CustomMeta:自定义元数据
		*OSSobjectMeta:OSS元数据
		*DebugMsg:debug信息
		*/
		void AsyncUploadPart(FString& InUploadId,const FString& InObjectName, const FString& InLocalPaths, int32 PartSize = 1024 * 1024 * 10, ProgressCallback InprogressCallback = nullptr, const TMap<FString, FString>& CustomMeta = TMap<FString, FString>(), const FOSSObjectMeta& OSSobjectMeta = FOSSObjectMeta(), const FString& DebugMsg = TEXT("Thank you for using Oss Storage Service!"));
		
		/**
		*取消分片上传
		*InBucketName:桶名称
		*InObjectName:对象名称
		*InUploadId:上传ID
		*/
		bool AbortMultipartUpload(const FString& InObjectName, const FString& InUploadId);

#pragma endregion Upload

#pragma region Download
		
		//上传处理
		///////////////////////////////////////////////////////////////////////////////////////////////////////

		/**
		*下载到内存
		*InBucketName:桶名称
		*InObjectName:对象名
		*ContextString:实际下载内容
		*InprogressCallback:回调函数
		*/
		bool GetObjectToMemory(const FString& InObjectName, FString& ContextString, SimpleOSS::OSS::FRange Range = FRange(),ProgressCallback InprogressCallback = nullptr);
		
		/**
		*下载到路径
		*InBucketName:桶名称
		*InObjectName:对象名
		*InLocalPaths:下载路径
		*InprogressCallback:回调函数
		*/
		bool GetObjectToLocal(const FString& InObjectName, FString& InLocalPaths, SimpleOSS::OSS::FRange Range = FRange(),ProgressCallback InprogressCallback = nullptr);
		
		/**
		*异步下载到路径
		*InBucketName:桶名称
		*InObjectName:对象名
		*InLocalPaths:下载路径
		*InprogressCallback:回调函数
		*/
		void AsyncGetObjectToLocal(const FString& InObjectName, FString& InLocalPaths, SimpleOSS::OSS::FRange Range = FRange(),ProgressCallback InprogressCallback = nullptr);
		
		/**
		*断点下载
		*InObjectName:对象名
		*InDownloadFilePath:下载路径
		*InCheckpointFilePath：缓存位置
		*Range：缓存块大小
		*InprogressCallback:回调函数
		*/
		bool ResumableDownloadObject(const FString& InObjectName, FString& InDownloadFilePath, const FString& InCheckpointFilePath = FPaths::ProjectSavedDir() / TEXT("OSSCache"), SimpleOSS::OSS::FRange Range = FRange(),ProgressCallback InprogressCallback = nullptr);
		
		/**
		*异步断点下载
		*InObjectName:对象名
		*InDownloadFilePath:下载路径
		*InCheckpointFilePath：缓存位置
		*Range：缓存块大小
		*InprogressCallback:回调函数
		*/
		void AsyncResumableDownloadObject(const FString& InObjectName, FString& InDownloadFilePath, const FString& InCheckpointFilePath = FPaths::ProjectSavedDir() / TEXT("OSSCache"), SimpleOSS::OSS::FRange Range = FRange(), ProgressCallback InprogressCallback = nullptr);

#pragma endregion Download

#pragma region Image

		//图片处理
		///////////////////////////////////////////////////////////////////////////////////////////////////////
		/**
		*缩放下载图片对象
		*Size:缩放大小
		*InBucketName:桶名称
		*InObjectName:图片名
		*InFileNametoSave:保存名
		*/
		bool GetImageObjectResize(const FVector2D& Size, const FString& InObjectName, const FString& InFileNametoSave);
		
		/**
		*裁剪下载图片对象
		*Size:裁剪大小
		*InBucketName:桶名称
		*InObjectName:图片名
		*InFileNametoSave:保存名
		*/
		bool GetImageObjectCrop(const FVector4& Size, int32 Ratio, const FString& InObjectName, const FString& InFileNametoSave);
		
		/**
		*锐化下载图片对象
		*Size:裁剪大小
		*InBucketName:桶名称
		*InObjectName:图片名
		*InFileNametoSave:保存名
		*/
		bool GetImageObjectSharpen(const int32 Sharpen, const FString& InObjectName, const FString& InFileNametoSave);
		
		/**
		*下载图片对象添加水印
		*WaterMarkObjectName:水印文字
		*InBucketName:桶名称
		*InObjectName:图片名
		*InFileNametoSave:保存名
		*/
		bool GetImageObjectWaterMark(const FString& WaterMarkObjectName, const FString& InObjectName, const FString& InFileNametoSave);
		
		/**
		*使用OSS模板样式
		*OSSStyleName:样式名
		*InBucketName:桶名称
		*InObjectName:图片名
		*InFileNametoSave:保存名
		*/
		bool GetImageObjectStyle(const FString& OSSStyleName, const FString& InObjectName, const FString& InFileNametoSave);
		
		/**
		*级联处理（多种命令
		*CascadeCommand:多命令
		*InBucketName:桶名称
		*InObjectName:图片名
		*InFileNametoSave:保存名
		*/
		bool GetImageObjectCascade(const TArray<FString>& CascadeCommand, const FString& InObjectName, const FString& InFileNametoSave);

#pragma endregion Image

	private:
		/**
		*下载图片对象
		*InBucketName:桶名称
		*InObjectName:图片名
		*InFileNametoSave:保存名
		*Command:执行处理命令
		*/
		bool GetImageObject(const FString& InObjectName, const FString& InFileNametoSave, const FString& Command);

	private:
		string AccessKeyId;
		string AccessKeySecret;
		string Endpoint;
		string InBucketName;

		FCriticalSection Mutex;
		FClientConfiguration Conf;
	};

	FORCEINLINE FOSS& GetOSS() { return OSS; }

private:
	static SCOssManage* SCOss;

	FOSS OSS;
};