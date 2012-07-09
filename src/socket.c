#include <event2/event.h>


evutil_socket_t
create_socket(char* ip, short port, int timeout_s, int backlog) {
  struct sockaddr_in          sin;
  evutil_socket_t             socket_fd;
  
  socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  evutil_make_socket_nonblocking(socket_fd);
  
  if (socket_fd < 0) {
    printf("could not create socket");
    return -1;
  }

  // memset(&sin, 0, sizeof(sin));
  sin.sin_family = AF_INET;
  sin.sin_addr.s_addr = htonl(0);
  sin.sin_port = htons(port);

  if (bind(socket_fd, (struct sockaddr *)&sin, sizeof(sin)) < 0) {
    printf("could not bind");
    return -1;
  }
  
  listen(socket_fd, backlog);
  
  return socket_fd;
}
