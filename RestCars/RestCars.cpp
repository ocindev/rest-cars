#include "RestfulService.h"
#include <conio.h>
#include <stdio.h>


//
//	RestService for the game Project Cars 2 using mongoose embedded webserver library.
//
//


#define VERSION "V0.1"
#define HTTP_404 ""
#define URL "/restcars/api"
#define URL_WEB "/restcars/overlays"
#define POLLING_INTERVAL 17
#define HTTP_404 "{\"status\": \"404 not found, please use the correct URL: " URL "\"}"
#define READY_TEST "{\"status\": \"200 ok, ready to process data\"}"

static const char *s_http_port = "8000";
static struct mg_serve_http_opts s_http_server_opts;


static RestfulService restfulService = RestfulService();

static void handleEvent(struct mg_connection *mc, int ev, void *ev_data)
{
	struct http_message *hm = (struct http_message *) ev_data;
	

	switch (ev)
	{
	case MG_EV_HTTP_REQUEST:
		if (mg_vcmp(&hm->uri, URL) == 0)
		{
			restfulService.handleHTTPRequest(mc, hm);
		}
		else
		{
			mg_serve_http(mc, (struct http_message *) ev_data, s_http_server_opts);
		}
	default:
		break;
	}
}



int main()
{
	struct mg_mgr mgr;
	struct mg_connection *mc;
	mg_mgr_init(&mgr, NULL);
	mc = mg_bind(&mgr, s_http_port, handleEvent);
	mg_set_protocol_http_websocket(mc);
	s_http_server_opts.document_root = "./html/";
	s_http_server_opts.enable_directory_listing = "yes";

	printf("# RestCars %s\n", VERSION);
	printf("# (c) Nico Weiser\n\n");
	printf("# Rest Server listens on http://localhost:%s%s \n", s_http_port, URL);
	printf("# Hit ESC to exit...\n");


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