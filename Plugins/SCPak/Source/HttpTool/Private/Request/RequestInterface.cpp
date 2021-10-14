#include "Request/RequestInterface.h"
#include "HttpModule.h"

SimpleHTTP::HTTP::IHTTPClientRequest::IHTTPClientRequest()
	:HttpRequest(FHttpModule::Get().CreateRequest())
{

}

bool SimpleHTTP::HTTP::IHTTPClientRequest::ProcessRequest()
{
	return HttpRequest->ProcessRequest();
}

void SimpleHTTP::HTTP::IHTTPClientRequest::CancelRequest()
{
	HttpRequest->CancelRequest();
}
