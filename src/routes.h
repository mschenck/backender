#include <event2/event.h>
#include <event2/http.h>
#include <syslog.h>
#include <time.h>
#include "routes.c"

void def_root (struct evhttp_request *req, void *arg);
void def_404 (struct evhttp_request *req, void *arg);  
void routes (struct evhttp *ev_httpd, struct event_base *base);
