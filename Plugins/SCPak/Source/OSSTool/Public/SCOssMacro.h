

#define OSSTOOL_MACRO_ERROR(Outcome) \
AuxiliaryTools.Print(Outcome##.error().Code()); \
AuxiliaryTools.Print(Outcome##.error().Message()); \
AuxiliaryTools.Print(Outcome##.error().RequestId());

#define OSSTOOL_MACRO_META(Request) \
auto meta = Request##.MetaData(); \
if (!OSSobjectMeta.ContentType.IsEmpty()) \
{ \
	meta.setContentType(TCHAR_TO_UTF8(*OSSobjectMeta.ContentType)); \
} \
if (!OSSobjectMeta.CacheControl.IsEmpty()) \
{ \
	meta.setCacheControl(TCHAR_TO_UTF8(*OSSobjectMeta.CacheControl)); \
} \
if (!OSSobjectMeta.ContentDisposition.IsEmpty()) \
{ \
	meta.setContentDisposition(TCHAR_TO_UTF8(*OSSobjectMeta.ContentDisposition)); \
} \
if (!OSSobjectMeta.ContentEncoding.IsEmpty()) \
{ \
	meta.setContentEncoding(TCHAR_TO_UTF8(*OSSobjectMeta.ContentEncoding)); \
} \
if (!OSSobjectMeta.ContentMd5.IsEmpty()) \
{ \
	meta.setContentMd5(TCHAR_TO_UTF8(*OSSobjectMeta.ContentMd5)); \
} \
for (auto& Tmp : CustomMeta) \
{ \
	meta.UserMetaData()[TCHAR_TO_UTF8(*Tmp.Key)] = TCHAR_TO_UTF8(*Tmp.Value); \
} \
TransferProgress ProgressCallback = { InprogressCallback,nullptr }; \
Request##.setTransferProgress(ProgressCallback);