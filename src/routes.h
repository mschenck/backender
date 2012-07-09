#include "routes.c"

void def_root (struct evhttp_request *req, void *arg);
void def_404 (struct evhttp_request *req, void *arg);  
void routes (struct evhttp *ev_httpd);
