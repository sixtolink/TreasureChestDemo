#include "Client/HttpClient.h"

HttpUtilityTool::FHttpClient::FHttpClient()
{
}

bool HttpUtilityTool::FHttpClient::HttpRequestProgress(FHttpClientRequest& Request)
{
	return Request.ProgressRequest();
}

void HttpUtilityTool::FHttpClient::HttpRequestCancel(FHttpClientRequest& Request)
{
	Request.CancelRequest();
}