#include "Client/HTTPClient.h"

SimpleHTTP::HTTP::FHTTPClient::FHTTPClient()
{
}

bool SimpleHTTP::HTTP::FHTTPClient::GetObject(FGetObjectRequest& Request) const
{
	return Request.ProcessRequest();
}

bool SimpleHTTP::HTTP::FHTTPClient::DeleteObject(FDeleteObjectRequest& Request) const
{
	return Request.ProcessRequest();
}

bool SimpleHTTP::HTTP::FHTTPClient::PutObject(FPutObjectRequest& Request) const
{
	return Request.ProcessRequest();
}

void SimpleHTTP::HTTP::FHTTPClient::AbortObject(FPutObjectRequest& Request)
{
	Request.CancelRequest();
}
