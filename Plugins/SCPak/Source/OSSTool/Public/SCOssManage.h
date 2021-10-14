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
		//Ͱ����
		///////////////////////////////////////////////////////////////////////////////////////////////////////
		
		/**
		*����Ͱ
		*InBucketName:����Ͱ����
		*/
		bool CreateBucket(EOSSStorageType OSSStorageType = EOSSStorageType::IA, EAcl Acl = EAcl::PUBLICREAD);

		/**
		*�о�Ͱ
		*InBucketName:�õ���Ͱ�ϼ�
		*/
		bool ListBuckets(TArray<FString>& BucketNameArray);
		
		/**
		*��ȡͰ���ڵ���
		*InBucketName:��Ҫ�ҵ����Ͱ
		*InLocation:���صĵ���
		*/
		bool GetBucketLocation();
		
		/**
		*ɾ��Ͱ
		*InBucketName:��Ҫɾ����Ͱ
		*/
		bool DeleteBucket();
		
		/**
		*����ͰȨ��
		*InBucketName:��Ҫ����Ȩ�޵�Ͱ
		*BucketAcl:��Ȩ��
		*/
		bool SetBucketAcl(EAcl BucketAcl = EAcl::DEFAULT);
		
		/**
		*��ȡͰȨ��
		*InBucketName:��Ҫ��ȡȨ�޵�Ͱ
		*/
		EAcl GetBucketAcl();
		
		/**
		*����Ͱ�������߸���ģʽ
		*InBucketName:Ͱ����
		*RequestPayer:������ģʽ
		*/
		bool SetBucketRequestPayment(ERequestPayerType InRequestPayer = ERequestPayerType::NOTSET);
		
		/**
		*��ȡͰ�������߸���ģʽ
		*InBucketName:Ͱ����
		*/
		ERequestPayerType GetBucketRequestPayment();
		
		/**
		*���÷�����
		*InBucketName:Ͱ����
		*URLRefererList:�������б�
		*bAllowEmptyReferer:�Ƿ��������
		*/
		bool SetBucketReferer(const TArray<FString>&URLReferer, bool bAllowEmptyReferer = false);
		
		/**
		*��ȡͰ�������б�
		*InBucketName:Ͱ����
		*/
		FRefererList GetBucketReferer();
		
		/**
		*ɾ��������
		*InBucketName:Ͱ����
		*URLReferer:�������б�
		*bAllowEmptyReferer:�Ƿ�����յ���
		*/
		bool DeleteBucketReferer(bool bAllowEmptyReferer = true);

		/**
		*�Ƿ����Ͱ
		*InBucketName:Ͱ����
		*/
		bool DoesBucketExist();

#pragma endregion Bucket

#pragma region Object

		//������
		///////////////////////////////////////////////////////////////////////////////////////////////////////
		/**
		*��ȡ����Ԫ����
		*InBucketName:Ͱ����
		*InObjectName:������
		*FOSSObjectMeta:���صĶ�����Ϣ
		*��һ�����ڴ濽��(����Ч��
		*/
		//FOSSObjectMeta GetObjectMeta(const FString& InBucketName, const FString& InObjectName);
		bool GetObjectMeta(const FString& InObjectName, FOSSObjectMeta& OSSObjectInfo);

		/**
		*��ȡ�����дȨ��
		*InBucketName:Ͱ����
		*InObjectName:������
		*ö�ٲ�̫ռ�ռ䣬����ʵ���������ֱ�ӷ���ʹ�ø�����
		*/
		EAcl GetObjectAcl(const FString& InObjectName);
		
		/**
		*���ö����дȨ��
		*InBucketName:Ͱ����
		*InObjectName:������
		*/
		bool SetObjectAcl(const FString& InObjectName, EAcl InAcl = EAcl::DEFAULT);
		
		/**
		*�Ƿ���ڶ���
		*InBucketName:Ͱ����
		*InObjectName:������
		*/
		bool DoesObjectExist(const FString& InObjectName);
		
		/**
		*�оٶ���
		*InBucketName:Ͱ����
		*InObjectNames:�оٶ�����
		*MaxNumber:�оٸ���
		*/
		bool ListObjects(TArray<FOSSObjectInfo>& ObjectName, int32 MaxNumber = 100);
		
		/**
		*�ݹ��оٶ���
		*InBucketName:Ͱ����
		*InKeyPrefix:Ŀ¼
		*InObjectNames:�оٶ�����
		*MaxNumber:�оٸ���
		*/
		bool ListObjectsByPrefix(const FString& InKeyPrefix, TArray<FOSSObjectInfo>& ObjectName, int32 MaxNumber = 100);
		
		/**
		*���ö��󴢴�����
		*InBucketName:Ͱ����
		*InObjectNames:������
		*OSSStorageType:��������
		*/
		bool SetObjectStorageType(const FString& InObjectName, EOSSStorageType OSSStorageType = EOSSStorageType::IA);
		
		/**
		*��ȡ���󴢴�����
		*InBucketName:Ͱ����
		*InObjectNames:������
		*/
		EOSSStorageType GetObjectStorageType(const FString& InObjectName);
		
		/**
		*�������������ӣ���ݷ�ʽ
		*InBucketName:Ͱ����
		*InObjectNames:������
		*InLinkObjectName:������
		*/
		bool CreateSymlink(const FString& InObjectName, const FString& InLinkObjectName);
		
		/**
		*��ȡ������ָ����ļ�
		*InBucketName:Ͱ����
		*InLinkObjectName:������
		*/
		FString GetSymlink(const FString& InLinkName);

		/**
		*��������
		*InSourceBucketName:ԭͰ����
		*InSourceObjectName:ԭ������
		*InCopyBucketName:����Ͱ����
		*InCopyObjectName:����������
		*��һ�����ڴ濽��(����Ч��
		*/
		bool CopyObject(const FString& InSourceBucketName, const FString& InSourceObjectName, const FString& InCopyBucketName, const FString& InCopyObjectName, ProgressCallback InProgressCallback = nullptr);
		
		/**
		*�첽��������
		*InSourceBucketName:ԭͰ����
		*InSourceObjectName:ԭ������
		*InCopyBucketName:����Ͱ����
		*InCopyObjectName:����������
		*��һ�����ڴ濽��(����Ч��
		*/
		void AsyncCopyObject(const FString& InSourceBucketName, const FString& InSourceObjectName, const FString& InCopyBucketName, const FString& InCopyObjectName, ProgressCallback InProgressCallback = nullptr);

		/**
		*ɾ����������
		*InBucketName:Ͱ����
		*InObjectName:������
		*/
		bool DeleteObject(const FString& InObjectName, ProgressCallback InProgressCallback = nullptr);

		/**
		*ɾ���������
		*InBucketName:Ͱ����
		*InObjectName:������
		*InProgressCallback:�ص�����
		*/
		bool DeleteObjects(const TArray<FString>& InObjectName, ProgressCallback InProgressCallback = nullptr);
		
		/**
		*�첽ɾ���������
		*InBucketName:Ͱ����
		*InObjectName:������
		*InProgressCallback:�ص�����
		*/
		void AsyncDeleteObjects(const TArray<FString>& InObjectName, ProgressCallback InProgressCallback = nullptr);

		/**
		*�о��ϴ���Ƭ
		*InUploadId:�ϴ���
		*InBucketName:Ͱ����
		*InObjectName:������
		*PartsInfo:��Ƭ��Ϣ
		*MaxParts:�о��������
		*/
		bool ListMultipartUploads(TArray<FMultipartPartsUploadsInfo>& MultipartPartsInfo, int MaxParts = 1000);

#pragma endregion Object

#pragma region Upload

		//�ϴ�����
		///////////////////////////////////////////////////////////////////////////////////////////////////////

		/**
		*���ڴ��ϴ���Դ
		*InBucketName:Ͱ����
		*InObjectName:������
		*InprogressCallback:�ص�����
		*CustomMeta:�Զ���Ԫ����
		*OSSobjectMeta:OSSԪ����
		*DebugMsg:debug��Ϣ
		*/
		bool PutObjectByMemory(const FString& InObjectName, ProgressCallback InprogressCallback = nullptr, const TMap<FString, FString>& CustomMeta = TMap<FString, FString>(), const FOSSObjectMeta& OSSobjectMeta = FOSSObjectMeta(), const FString& DebugMsg = TEXT("Thank you for using Oss Storage Service!"));
		
		/**
		*�ӱ����ϴ���Դ������Ҳ�Ǽ��ص��ڴ�Ȼ���ϴ�
		*InBucketName:Ͱ����
		*InLocalPaths:����·��
		*InprogressCallback:�ص�����
		*CustomMeta:�Զ���Ԫ����
		*OSSobjectMeta:OSSԪ����
		*DebugMsg:debug��Ϣ
		*/
		bool PutObjectByLocal(const FString& InLocalPaths, const FString& InObjectName, ProgressCallback InprogressCallback = nullptr, const TMap<FString, FString>& CustomMeta = TMap<FString, FString>(), const FOSSObjectMeta& OSSobjectMeta = FOSSObjectMeta(), const FString& DebugMsg = TEXT("Thank you for using Oss Storage Service!"));
		
		/**
		*�첽�ӱ����ϴ���Դ������Ҳ�Ǽ��ص��ڴ�Ȼ���ϴ�
		*InBucketName:Ͱ����
		*InLocalPaths:����·��
		*InprogressCallback:�ص�����
		*CustomMeta:�Զ���Ԫ����
		*OSSobjectMeta:OSSԪ����
		*DebugMsg:debug��Ϣ
		*/
		void AsyncPutObject(const FString& InLocalPaths, const FString& InObjectName, ProgressCallback InprogressCallback = nullptr, const TMap<FString, FString>& CustomMeta = TMap<FString, FString>(), const FOSSObjectMeta& OSSobjectMeta = FOSSObjectMeta(), const FString& DebugMsg = TEXT("Thank you for using Oss Storage Service!"));

		/**
		*�ϵ�����
		*InObjectName:Ŀ���ļ���
		*InUploadFilePath:�ϴ�·��
		*InCheckpointFilePath:��Ƭ����·��
		*InprogressCallback:�ص�����
		*CustomMeta:�Զ���Ԫ����
		*OSSobjectMeta:OSSԪ����
		*DebugMsg:debug��Ϣ
		*/
		bool ResumableUploadObject(const FString& InObjectName, const FString& InUploadFilePath, const FString& InCheckpointFilePath = FPaths::ProjectSavedDir() / TEXT("OSSCache"), ProgressCallback InprogressCallback = nullptr, const TMap<FString, FString>& CustomMeta = TMap<FString, FString>(), const FOSSObjectMeta& OSSobjectMeta = FOSSObjectMeta(), const FString& DebugMsg = TEXT("Thank you for using Oss Storage Service!"));
		
		/**
		*�첽�ϵ�����
		*InObjectName:Ŀ���ļ���
		*InUploadFilePath:�ϴ�·��
		*InCheckpointFilePath:��Ƭ����·��
		*InprogressCallback:�ص�����
		*CustomMeta:�Զ���Ԫ����
		*OSSobjectMeta:OSSԪ����
		*DebugMsg:debug��Ϣ
		*/
		void AsyncResumableUploadObject(const FString& InObjectName, const FString& InUploadFilePath, const FString& InCheckpointFilePath = FPaths::ProjectSavedDir() / TEXT("OSSCache"), ProgressCallback InprogressCallback = nullptr, const TMap<FString, FString>& CustomMeta = TMap<FString, FString>(), const FOSSObjectMeta& OSSobjectMeta = FOSSObjectMeta(), const FString& DebugMsg = TEXT("Thank you for using Oss Storage Service!"));
		
		/**
		*��Ƭ�ϴ�
		*InUploadId:�ϴ�ID
		*InBucketName:Ͱ����
		*InObjectName:��������
		*InLocalPaths:����·��
		*PartSize:��Ƭ��С
		*InprogressCallback:�ص�����
		*CustomMeta:�Զ���Ԫ����
		*OSSobjectMeta:OSSԪ����
		*DebugMsg:debug��Ϣ
		*/
		bool UploadPart(FString& InUploadId, const FString& InObjectName, const FString& InLocalPaths, int32 PartSize = 1024 * 1024 * 10, ProgressCallback InprogressCallback = nullptr, const TMap<FString, FString>& CustomMeta = TMap<FString, FString>(), const FOSSObjectMeta& OSSobjectMeta = FOSSObjectMeta(), const FString& DebugMsg = TEXT("Thank you for using Oss Storage Service!"));
		
		/**
		*�첽��Ƭ�ϴ�
		*InUploadId:�ϴ�ID
		*InBucketName:Ͱ����
		*InObjectName:��������
		*InLocalPaths:����·��
		*PartSize:��Ƭ��С
		*InprogressCallback:�ص�����
		*CustomMeta:�Զ���Ԫ����
		*OSSobjectMeta:OSSԪ����
		*DebugMsg:debug��Ϣ
		*/
		void AsyncUploadPart(FString& InUploadId,const FString& InObjectName, const FString& InLocalPaths, int32 PartSize = 1024 * 1024 * 10, ProgressCallback InprogressCallback = nullptr, const TMap<FString, FString>& CustomMeta = TMap<FString, FString>(), const FOSSObjectMeta& OSSobjectMeta = FOSSObjectMeta(), const FString& DebugMsg = TEXT("Thank you for using Oss Storage Service!"));
		
		/**
		*ȡ����Ƭ�ϴ�
		*InBucketName:Ͱ����
		*InObjectName:��������
		*InUploadId:�ϴ�ID
		*/
		bool AbortMultipartUpload(const FString& InObjectName, const FString& InUploadId);

#pragma endregion Upload

#pragma region Download
		
		//�ϴ�����
		///////////////////////////////////////////////////////////////////////////////////////////////////////

		/**
		*���ص��ڴ�
		*InBucketName:Ͱ����
		*InObjectName:������
		*ContextString:ʵ����������
		*InprogressCallback:�ص�����
		*/
		bool GetObjectToMemory(const FString& InObjectName, FString& ContextString, SimpleOSS::OSS::FRange Range = FRange(),ProgressCallback InprogressCallback = nullptr);
		
		/**
		*���ص�·��
		*InBucketName:Ͱ����
		*InObjectName:������
		*InLocalPaths:����·��
		*InprogressCallback:�ص�����
		*/
		bool GetObjectToLocal(const FString& InObjectName, FString& InLocalPaths, SimpleOSS::OSS::FRange Range = FRange(),ProgressCallback InprogressCallback = nullptr);
		
		/**
		*�첽���ص�·��
		*InBucketName:Ͱ����
		*InObjectName:������
		*InLocalPaths:����·��
		*InprogressCallback:�ص�����
		*/
		void AsyncGetObjectToLocal(const FString& InObjectName, FString& InLocalPaths, SimpleOSS::OSS::FRange Range = FRange(),ProgressCallback InprogressCallback = nullptr);
		
		/**
		*�ϵ�����
		*InObjectName:������
		*InDownloadFilePath:����·��
		*InCheckpointFilePath������λ��
		*Range��������С
		*InprogressCallback:�ص�����
		*/
		bool ResumableDownloadObject(const FString& InObjectName, FString& InDownloadFilePath, const FString& InCheckpointFilePath = FPaths::ProjectSavedDir() / TEXT("OSSCache"), SimpleOSS::OSS::FRange Range = FRange(),ProgressCallback InprogressCallback = nullptr);
		
		/**
		*�첽�ϵ�����
		*InObjectName:������
		*InDownloadFilePath:����·��
		*InCheckpointFilePath������λ��
		*Range��������С
		*InprogressCallback:�ص�����
		*/
		void AsyncResumableDownloadObject(const FString& InObjectName, FString& InDownloadFilePath, const FString& InCheckpointFilePath = FPaths::ProjectSavedDir() / TEXT("OSSCache"), SimpleOSS::OSS::FRange Range = FRange(), ProgressCallback InprogressCallback = nullptr);

#pragma endregion Download

#pragma region Image

		//ͼƬ����
		///////////////////////////////////////////////////////////////////////////////////////////////////////
		/**
		*��������ͼƬ����
		*Size:���Ŵ�С
		*InBucketName:Ͱ����
		*InObjectName:ͼƬ��
		*InFileNametoSave:������
		*/
		bool GetImageObjectResize(const FVector2D& Size, const FString& InObjectName, const FString& InFileNametoSave);
		
		/**
		*�ü�����ͼƬ����
		*Size:�ü���С
		*InBucketName:Ͱ����
		*InObjectName:ͼƬ��
		*InFileNametoSave:������
		*/
		bool GetImageObjectCrop(const FVector4& Size, int32 Ratio, const FString& InObjectName, const FString& InFileNametoSave);
		
		/**
		*������ͼƬ����
		*Size:�ü���С
		*InBucketName:Ͱ����
		*InObjectName:ͼƬ��
		*InFileNametoSave:������
		*/
		bool GetImageObjectSharpen(const int32 Sharpen, const FString& InObjectName, const FString& InFileNametoSave);
		
		/**
		*����ͼƬ�������ˮӡ
		*WaterMarkObjectName:ˮӡ����
		*InBucketName:Ͱ����
		*InObjectName:ͼƬ��
		*InFileNametoSave:������
		*/
		bool GetImageObjectWaterMark(const FString& WaterMarkObjectName, const FString& InObjectName, const FString& InFileNametoSave);
		
		/**
		*ʹ��OSSģ����ʽ
		*OSSStyleName:��ʽ��
		*InBucketName:Ͱ����
		*InObjectName:ͼƬ��
		*InFileNametoSave:������
		*/
		bool GetImageObjectStyle(const FString& OSSStyleName, const FString& InObjectName, const FString& InFileNametoSave);
		
		/**
		*����������������
		*CascadeCommand:������
		*InBucketName:Ͱ����
		*InObjectName:ͼƬ��
		*InFileNametoSave:������
		*/
		bool GetImageObjectCascade(const TArray<FString>& CascadeCommand, const FString& InObjectName, const FString& InFileNametoSave);

#pragma endregion Image

	private:
		/**
		*����ͼƬ����
		*InBucketName:Ͱ����
		*InObjectName:ͼƬ��
		*InFileNametoSave:������
		*Command:ִ�д�������
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