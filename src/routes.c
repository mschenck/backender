#include "http_requests.h"
#include "constants.h"
#include "latency.h"

void
delayed_response (evutil_socket_t fd, short what, void *arg) {
  struct evhttp_request *req = arg;
  http_response( req, HTTP_OK, "OK", "^_^", HTML_CONTENT );
}

void 
def_root (struct evhttp_request *req, void *arg) {
  struct event_base *ev_base = arg;
  struct event *response;
  int latency = random_latency( 300 ) + 300; 
  struct timeval pause = { 0, (latency * 1000) };

  response = evtimer_new( ev_base, delayed_response, req );

  if ( latency % 5 == 0 ) {
    syslog( LOG_INFO, "Requested '%s' paused for %d milliseconds", req->uri, pause.tv_usec / 1000 );
  }

  evtimer_add( response, &pause );
}

void 
def_404 (struct evhttp_request *req, void *arg) {
  http_response(req, HTTP_NOTFOUND, "Not found", "Not found .. ~_~", HTML_CONTENT);  
  // TODO: better logging than -> printf("Request: %s\n", req->uri);
}

/* Register routes */
void
routes (struct evhttp *ev_httpd, struct event_base *ev_base) {
  // Defined route(s)
  evhttp_set_cb(ev_httpd, "/", &def_root, ev_base);
  
  // Default route (404)
  evhttp_set_gencb(ev_httpd, &def_404, NULL);
}
