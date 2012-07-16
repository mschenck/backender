#include <event2/event.h>
#include <event2/http.h>
#include <event2/buffer.h>
#include <event2/http_struct.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/tcp.h>
#include <syslog.h>
#include "httpd.c"

int run_server(char* ip, short port, int timeout_s, int backlog);

void http_response(struct evhttp_request *req, int http_code, char *msg,
  char *content, char *content_type);
