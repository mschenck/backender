#include <stdlib.h>
#include <fcntl.h>
#include <time.h>

int
random_latency ( int base, int range ) {
  int random_int;
  srand( time(NULL) );

  int random_fd = open( "/dev/urandom", O_RDONLY );
  read( random_fd, &random_int, sizeof random_int );
  close( random_fd );

  return ( ( abs( random_int ) * abs( rand() ) ) % range ) + base;
}

void
incur_latency ( int latency ) {
  struct timespec * remaining;
  struct timespec pause = { 0, ( latency * 1000000 ) };
  int results = nanosleep( &pause, remaining );
}

void
generate_latency ( int base, int range ) {
  int latency = random_latency( base, range );
  incur_latency( latency );
}

