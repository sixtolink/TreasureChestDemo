#include "Interface/HttpRequestInterface.h"
#include "HttpModule.h"

HttpUtilityTool::IHttpClientRequest::IHttpClientRequest()
	:HttpRequest(FHttpModule::Get().CreateRequest())
{

}

bool HttpUtilityTool::IHttpClientRequest::ProgressRequest()
{
	return HttpRequest->ProcessRequest();
}

void HttpUtilityTool::IHttpClientRequest::CancelRequest()
{
	HttpRequest->CancelRequest();
}
