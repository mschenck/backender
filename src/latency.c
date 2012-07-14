#include <stdlib.h>
#include <fcntl.h>

int
random_latency ( int range ) {
  int random_fd, random_data, randomer;

  // Start time-based random
  srand( time(NULL) );

  // Get file-based random
  random_fd = open( "/dev/urandom", O_RDONLY );
  read( random_fd, &random_data, sizeof random_data );
  close( random_fd );

  randomer = (24 * random_data) / (8 * rand());

  return abs(randomer % range);
}

void
generate_latency ( int base, int range ) {
  int latency = random_latency( range ) + base; 
  struct timespec *remaining;
  struct timespec pause = { 0, ( latency * 1000000 ) };
  nanosleep( &pause, remaining );
}

