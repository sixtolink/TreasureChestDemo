
#define DEFINITION_HTTP_TYPE(VerbString,Content) \
HttpRequest->SetURL(URL); \
HttpRequest->SetVerb(TEXT(##VerbString)); \
HttpRequest->SetHeader(TEXT("Content-Type"), TEXT(##Content));//����ͨ����������ΪĬ���������������

#define REQUEST_BIND_FUN \
Request \
<< FHttpRequestHeaderReceivedDelegate::CreateRaw(this, &SCHttpManage::HttpRequestHeaderReceived) \
<< FHttpRequestProgressDelegate::CreateRaw(this, &SCHttpManage::HttpRequestProgress) \
<< FHttpRequestCompleteDelegate::CreateRaw(this, &SCHttpManage::HttpRequestComplete);