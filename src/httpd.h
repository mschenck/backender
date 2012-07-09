#include "httpd.c"

int run_server(char* ip, short port, int timeout_s, int backlog);

void http_response(struct evhttp_request *req, int http_code, char *msg,
  char *content, char *content_type);