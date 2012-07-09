#include <stdlib.h>
#include "httpd.h"
#include "constants.h"

int
main(int argc, char **argv) {
  char  *listen_ip = '0.0.0.0';
  int   listen_port = PORT;
  int   timeout_s = TIMEOUT;
  int   backlog = BACKLOG;
  
  return run_server(listen_ip, listen_port, timeout_s, backlog);
}
