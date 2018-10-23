#include "RestfulService.h"
#include <conio.h>
#include <stdio.h>
#include <iostream>


//
// Rest Cars (c) Nico Weiser
// Restful API for Project Cars 2 using mongoose embedded webserver library.
// Providing shared memory data via portable and accecssible HTTP interface.
// Written as a native windows command prompt application.
// Repository: http://www.github.com/nweiser94/rest-cars
//


#define VERSION "V0.1"
#define URL "/restcars/api"
#define POLLING_INTERVAL 17
#define HTTP_404 "{\"status\": \"404 not found, please use the correct URL: " URL "\"}"
#define READY_TEST "{\"status\": \"200 ok, ready to process data\"}"

static const char *s_http_port = "8000";
static struct mg_serve_http_opts s_http_server_opts;


static RestfulService restfulService = RestfulService();


/**
	
*/
static void handleEvent(struct mg_connection *mc, int ev, void *ev_data)
{
	struct http_message *hm = (struct http_message *) ev_data;
	

	switch (ev)
	{
	case MG_EV_HTTP_REQUEST:
		if (mg_vcmp(&hm->uri, URL) == 0)
		{
			// Handle the REQUEST if the URI equals '/restcars/api'
			restfulService.handleHTTPRequest(mc, hm);
		}
		else
		{
			// Data is only provided via '/restcars/api' else return an 404 Status
			mg_printf(mc, "HTTP/1.1 404 Not found\r\n"
				"Content-Type: application/json\r\n"
				"Cache-Control: no-cache\r\n"
				"Access-Control-Allow-Origin: *\r\n"
				"Content-Length: %d\r\n\r\n%s",
				(int)strlen(HTTP_404), HTTP_404);
		}
	default:
		break;
	}
}


/**
	Main application entry point.
*/
int main()
{
	struct mg_mgr mgr;
	struct mg_connection *mc;
	mg_mgr_init(&mgr, NULL);
	mc = mg_bind(&mgr, s_http_port, handleEvent);
	mg_set_protocol_http_websocket(mc);
	s_http_server_opts.document_root = ".";

	// Print out basic application information

	std::cout << "# (c) Nico Weiser" << std::endl << std::endl;
	std::cout << "# RestCars " << VERSION << std::endl;
	std::cout << "# The RESTful API for Project Cars 2" << std::endl;
	std::cout << "# Rest Server listens on http://localhost:" << s_http_port << URL << std::endl;
	std::cout << "# Hit ESC to exit..." << std::endl;


	while (true)
	{
		mg_mgr_poll(&mgr, POLLING_INTERVAL);

		if (_kbhit() && _getch() == 27)
		{
			break;
		}
	}

	mg_mgr_free(&mgr);

	return EXIT_SUCCESS;
}