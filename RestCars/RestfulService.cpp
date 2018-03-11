#include "RestfulService.h"
#include "JSONRenderer.h"

#define HTTP_503 "{\"status\": \"503 Restcars unavailable, make sure Project Cars 2 is running and Shared Memory enabled!\"}"
#define HTTP_409 "{\"status\": \"409 Conflict, Shared Memory Definition seems to be outdated. Make sure you have the latest version of Restcars!\"}"
#define SHARED_MEMORY_OBJECT "$pcars2$"



RestfulService::RestfulService() {};


static JSONRenderer jsonRenderer = JSONRenderer();


void response503(struct mg_connection *mc)
{
	mg_printf(mc, "HTTP/1.1 503 Service unaivalable\r\n"
		"Content-Type: application/json\r\n"
		"Cache-Control: no-cache\r\n"
		"Access-Control-Allow-Origin: *\r\n"
		"Content-Length: %d\r\n\r\n%s",
		(int)strlen(HTTP_503), HTTP_503);
}


void response409(struct mg_connection *mc)
{
	mg_printf(mc, "HTTP/1.1 409 Conflict\r\n"
		"Content-Type: application/json\r\n"
		"Cache-Control: no-cache\r\n"
		"Access-Control-Allow-Origin: *\r\n"
		"Content-Length: %d\r\n\r\n%s",
		(int)strlen(HTTP_409), HTTP_409);
}

void responseOptions(struct mg_connection *mc)
{
	mg_printf(mc, "HTTP/1.1 200 Ok\r\n"
		"Access-Control-Allow-Origin: *\r\n"
		"Access-Control-Allow-Methods: GET, OPTIONS\r\n"
		"Access-Control-Max-Age: 86400\r\n"
		"Content-Length: 0\r\n");
}

std::string getQueryString(struct http_message *hm)
{
	if (hm->query_string.len > 0)
	{
		std::string queryString(hm->query_string.p, hm->query_string.len);
		return queryString;
	}
	else {
		return "";
	}
}


std::string getRequestMethod(struct http_message *hm)
{
	if (hm->method.len > 0)
	{
		std::string requestMethod(hm->method.p, hm->method.len);
		return requestMethod;
	}
	else {
		return "";
	}
}


void prepareResponse(struct mg_connection *mc, const SharedMemory* sharedData, struct http_message *hm)
{
	std::string json = jsonRenderer.renderJSON(sharedData, getQueryString(hm));
	mg_printf(mc, "HTTP/1.1 200 Ok\r\n"
		"Content-Type: application/json\r\n"
		"Cache-Control: no-cache\r\n"
		"Access-Control-Allow-Origin: *\r\n"
		"Content-Length: %d\r\n\r\n", (int)json.size());
	mg_send(mc, json.data(), json.size());

}

void prepareData(struct mg_connection *mc, const SharedMemory* sharedData, struct http_message *hm)
{
	if (sharedData->mVersion != SHARED_MEMORY_VERSION)
	{
		response409(mc);
	}
	else {
		prepareResponse(mc, sharedData, hm);
	}
}

void handleFile(struct mg_connection *mc, HANDLE fileHandle, struct http_message *hm)
{
	const SharedMemory* sharedData = (SharedMemory*)MapViewOfFile(fileHandle, PAGE_READONLY, 0, 0, sizeof(SharedMemory));
	if (sharedData == NULL)
	{
		response409(mc);
	}
	else {
		prepareData(mc, sharedData, hm);
	}
}


void handleGetRequest(struct mg_connection *mc, struct http_message *hm)
{
	HANDLE fileHandle = OpenFileMappingA(PAGE_READONLY, FALSE, SHARED_MEMORY_OBJECT);
	if (fileHandle == NULL)
	{
		response503(mc);
	}
	else {
		handleFile(mc, fileHandle, hm);
		CloseHandle(fileHandle);
	}
}



void RestfulService::handleHTTPRequest(struct mg_connection *mc, struct http_message *hm)
{
	std::string requestMethod = getRequestMethod(hm);
	if (requestMethod.compare("GET") == 0)
	{
		handleGetRequest(mc, hm);
	}
	else if(requestMethod.compare("OPTIONS") == 0)
	{
		responseOptions(mc);
	}
}