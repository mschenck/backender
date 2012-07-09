#include "http_requests.c"


void http_response(struct evhttp_request *req, int http_code, char *msg,
  char *content, char *content_type);