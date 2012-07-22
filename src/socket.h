#include <event2/event.h>

#include "socket.c"

evutil_socket_t create_socket(char* ip, short port, int timeout_s, int backlog);
