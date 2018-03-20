#include "mongoose.h"
#include <Windows.h>
#include <sstream>
#include <string>
#include "sharedmemory.h"
#include <stdio.h>
class RestfulService {
public:
	RestfulService();
	void handleHTTPRequest(struct mg_connection *mc, struct http_message *hm);
};