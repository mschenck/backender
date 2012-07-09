#include <event2/event.h>
#include <event2/http.h>
#include "http_requests.h"
#include "constants.h"
#include "latency.h"


void
latency_cb (evutil_socket_t fd, short what, void *arg) {
  generate_latency(300, 300);
}

void 
def_root (struct evhttp_request *req, void *arg) {
/*
  struct event_base *ev_thinking_base;
  struct event_config *ev_thinking_cfg;

  ev_thinking_cfg = event_config_new();
  event_config_set_flag( ev_thinking_cfg, EVENT_BASE_FLAG_NOLOCK );
  ev_thinking_base = event_base_new_with_config( ev_thinking_cfg );

  if (!ev_thinking_base) {
    printf("ERROR: Failed to initialize worker event loop!\n");
    return -1;
  }
*/

  // This should be moved to an async method
  generate_latency( 300, 300 );
  http_response( req, HTTP_OK, "OK", "^_^", HTML_CONTENT );
}

void 
def_404 (struct evhttp_request *req, void *arg) {
  http_response(req, HTTP_NOTFOUND, "Not found", "Not found .. ~_~", HTML_CONTENT);  
  // printf("Request: %s\n", req->uri);
}

/* Register routes */
void
routes (struct evhttp *ev_httpd) {
  // Defined route(s)
  evhttp_set_cb(ev_httpd, "/", &def_root, NULL);
  
  // Default route (404)
  evhttp_set_gencb(ev_httpd, &def_404, NULL);
}
