#include "APIService.h"
#include "fossa.h"
#include "FossaUtils.h"
#include "sharedmemory.h"
#include <Windows.h>

APIService::APIService() {};


#define HTTP_RESPONSE_503 "{\"status\": \"503 APIService unavailable, make sure Project Cars 2 is running and Shared Memory enabled!\"}"
#define HTTP_RESPONSE_409 "{\"status\": \"409 Conflict, Shared Memory Definition seems to be outdated. Make sure to get the latest version of pcars2-streamy!\"}"
#define SHARED_MEMORY_OBJECT "$pcars2$"



void responseUnavailable(struct ns_connection *nc)
{
	ns_printf(nc, "HTTP/1.1 503 Service unaivalable\r\n"
		"Content-Type: application/json\r\n"
		"Cache-Control: no-cache\r\n"
		"Access-Control-Allow-Origin: *\r\n"
		"Content-Length: %d\r\n\r\n%s",
		(int)strlen(HTTP_RESPONSE_503), HTTP_RESPONSE_503);
}


void responseConflict(struct ns_connection *nc)
{
	ns_printf(nc, "HTTP/1.1 409 Conflict\r\n"
		"Content-Type: application/json\r\n"
		"Cache-Control: no-cache\r\n"
		"Access-Control-Allow-Origin: *\r\n"
		"Content-Length: %d\r\n\r\n%s",
		(int)strlen(HTTP_RESPONSE_409), HTTP_RESPONSE_409);
}

void responseOptions(struct ns_connection *nc)
{
	ns_printf(nc, "HTTP/1.1 200 Ok\r\n"
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
	else
	{
		return "";
	}
}


std::string getRequestMethod(struct http_message *hm)
{
	if (hm->method.len > 0)
	{
		std::string requestMethod (hm->method.p, hm->method.len);
		return requestMethod;
	}
	else
	{
		return "";
	}
}

void handleFile(struct ns_connection *nc, HANDLE fileHandle, struct http_message *hm)
{
	const SharedMemory* sharedData = (SharedMemory*)MapViewOfFile(fileHandle, PAGE_READONLY, 0, 0, sizeof(SharedMemory));

	if (sharedData == NULL)
	{
		responseUnavailable(nc);
	}
}

void responding(struct ns_connection *nc, const SharedMemory* sharedData, struct http_message *hm)
{

}

void processingData(struct ns_connection *nc, const SharedMemory* sharedData, struct http_message *hm)
{
	if (sharedData->mVersion != SHARED_MEMORY_VERSION) {
		responseConflict(nc);
		printf("Tool seems to be outdated...\n\n");
		printf("Game-Version: %s\n", sharedData->mVersion);
		printf("Tool-Version: %s\n", SHARED_MEMORY_VERSION);
		printf("Please update...\n");
	}
	else {
		responding(nc, sharedData, hm);
	}
}


void APIService::handle(struct ns_connection *nc, struct http_message *hm)
{
	std::string requestMethod = getRequestMethod(hm);
	if (requestMethod.compare("GET") == 0)
	{
		handleGetRequest(nc, hm);
	}
	else if(requestMethod.compare("OPTIONS") == 0) 
	{
		responseOptions(nc);
	}
}

void handleGetRequest(struct ns_connection *nc, struct http_message *hm)
{
	HANDLE fileHandle = OpenFileMappingA(PAGE_READONLY, FALSE, SHARED_MEMORY_OBJECT);

	if (fileHandle == NULL) {
		responseUnavailable(nc);
	}
	else
	{
		handleFile(nc, fileHandle, hm);
		CloseHandle(fileHandle);
	}
}

