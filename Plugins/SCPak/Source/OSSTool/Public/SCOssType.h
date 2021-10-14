#pragma once

#include "CoreMinimal.h"
#include "RateLimiter.h"

class RateLimiter;

namespace SimpleOSS
{
    namespace OSS
    {
        struct OSSTOOL_API FMultipartPartsUploadsInfo
        {
            FString Key;
            FString UploadId;
            FString Initiated;
        };

        struct OSSTOOL_API FRange
        {
            FRange()
                :Start(0)
                ,End(0)
            {}
            uint64 Start;
            uint64 End;

            FORCEINLINE bool IsValid() { return Start < End&& End != 0; }
        };

        enum class EOSSStorageType :uint8
        {
            STANDARD,
            IA,
            ARCHIVE,
            NONE
        };

        struct OSSTOOL_API FOSSObjectInfo
        {
            FString Name;
            int64 Size;
            FString LastModifyTime;
        };

        struct OSSTOOL_API FOSSObjectMeta
        {
            FString AcceptRanges;
            FString Connection;
            FString Date;
            FString Server;
            FString x_oss_hash_crc64ecma;
            FString x_oss_object_type;
            FString x_oss_request_id;
            FString x_oss_storage_class;

            FString ContentType;
            int64 ContentLength;
            FString CacheControl;
            FString ContentDisposition;
            FString ContentEncoding;
            FString ContentMd5;
            FString ObjectType;
            FString Tag;
            FString LastModified;
            FString ExpirationTime;

            TMap<FString, FString> MetaData;
            TMap<FString, FString> UserMetaData;
        };

        struct OSSTOOL_API FRefererList
        {
            FRefererList()
                :RequestId("")
            {}

            FORCEINLINE bool IsValid() { return !RequestId.IsEmpty(); }

            bool bAllowEnptyReferer;
            int64 RefererListNum;
            FString RequestId;
        };

        enum class ERequestPayerType :uint8
        {
            NOTSET = 0,
            BUCKETOWNER,
            REQUESTER,
            NONE
        };

        enum class EAcl :uint8
        {
            PRIVATE = 0,
            PUBLICREAD,
            PUBLICREADWRITE,
            DEFAULT,
            NONE
        };

        class FOSSRateLimiter :public AlibabaCloud::OSS::RateLimiter
        {
        public:
            FOSSRateLimiter()
                :M_Rate(0)
            {}
            ~FOSSRateLimiter() {}
            virtual void setRate(int rate) { M_Rate = rate; }
            virtual int Rate()const { return M_Rate; }
        private:
            int32 M_Rate;
        };

		enum Scheme
		{
			HTTP,
			HTTPS
		};

        class OSSTOOL_API FClientConfiguration
        {
        public:
            FClientConfiguration();
            ~FClientConfiguration() = default;
        public:
            /**
            * Http scheme to use. E.g. Http or Https.
            */
            OSS::Scheme Scheme;
            /**
            * Max concurrent tcp connections for a single http client to use.
            */
            unsigned MaxConnections;
            /**
            * Socket read timeouts. Default 3000 ms.
            */
            long RequestTimeoutMs;
            /**
            * Socket connect timeout.
            */
            long ConnectTimeoutMs;
            /**
            * The proxy scheme. Default HTTP
            */
            OSS::Scheme ProxyScheme;
            /**
            * The proxy host.
            */
            FString ProxyHost;
            /**
            * The proxy port.
            */
            uint32 ProxyPort;
            /**
            * The proxy username.
            */
            FString ProxyUserName;
            /**
            *  The proxy password
            */
            FString ProxyPassword;
            /**
            * set false to bypass SSL check.
            */
            bool bVerifySSL;
            /**
            * your Certificate Authority path.
            */
            FString CaPath;
            /**
            * your certificate file.
            */
            FString CaFile;
            /**
            * your certificate file.
            */
            bool bCname;
            /**
            * enable or disable crc64 check.
            */
            bool bEnableCrc64;
            /**
            * enable or disable auto correct http request date.
            */
            bool bEnableDateSkewAdjustment;
            /**
            * Rate limit data upload speed.
            */
            uint32 SendRateLimiter;
            /**
            * Rate limit data download speed.
            */
            uint32 RecvRateLimiter;
            /**
            * The interface for outgoing traffic. E.g. eth0 in linux
            */
            FString NetworkInterface;
        };
    }
}

using namespace SimpleOSS::OSS;

//OSS上传进度回调
typedef void(*ProgressCallback)(uint64, int64, int64, void*);