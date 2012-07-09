#include "socket.h"
#include "routes.h"
#include "constants.h"

int worker(struct event_base *ev_base) {
  event_reinit(ev_base);
  event_base_dispatch(ev_base);
}

/*
 * main loop - construct the event_base and start the loop
 */
int
run_server(char* ip, short port, int timeout_s, int backlog) {
  struct event_base           *ev_base;
  struct event_config         *ev_cfg;
  struct evhttp               *ev_httpd;
  evutil_socket_t             socket_fd;

  openlog("Backend", LOG_PID|LOG_NDELAY, LOG_LOCAL0);  

  ev_cfg = event_config_new();
  //event_config_set_flag(ev_cfg, EV_TIMEOUT|EV_PERSIST);
  ev_base = event_base_new_with_config(ev_cfg);
  
  if (!ev_base) {
    printf("ERROR: Failed to initialize HTTP event loop!\n");
    return -1;
  }
     
  // Set up httpd interface event
  ev_httpd = evhttp_new(ev_base);
  evhttp_set_timeout(ev_httpd, timeout_s);
  routes(ev_httpd, ev_base);

  socket_fd = create_socket(ip, port, timeout_s, backlog);
  evhttp_accept_socket(ev_httpd, socket_fd);
  
  int w;
  for (w = 0; w < WORKERS; w++) {
    if (fork() == 0) {
      printf("Starting worker %d ... ", w);
      worker(ev_base);
      printf("done.\n");
      exit(0);
    }
  }

  closelog();
  return 0;
}

