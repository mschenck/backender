APP = backend

CC = gcc

OS := $(shell uname)
ifeq ($(OS), Darwin)
  # MacOS 
  LIBEVENT = /opt/tumblr/libevent-tumblr
  CFLAGS = -fno-strict-aliasing -O3 -march=core2 -msse4.1 -w -pipe -DNDEBUG -g -fwrapv -Wall -Wstrict-prototypes 
else
  # Linux
  LIBEVENT = /usr/local
  CFLAGS = -fno-strict-aliasing -O3 -w -pipe -DNDEBUG -g -fwrapv -Wall -Wstrict-prototypes -lrt
endif

LIBEVENT_LIB = "${LIBEVENT}/lib"
LIBEVENT_INCLUDE = "${LIBEVENT}/include"

CFLAGS += -I$(LIBEVENT_INCLUDE) -Isrc -L$(LIBEVENT_LIB) -L/usr/local/lib -L/usr/lib
SOURCES = $(LIBEVENT_LIB)/libevent.a $(LIBEVENT_LIB)/libevent_core.a $(LIBEVENT_LIB)/libevent_extra.a $(LIBEVENT_LIB)/libevent_pthreads.a

all :
	 $(CC) $(CFLAGS) -o $(APP) src/main.c $(SOURCES)
