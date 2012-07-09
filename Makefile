APP = backend

CC = gcc
LIBEVENT = /usr/local
CFLAGS = -fno-strict-aliasing -O3 -march=core2 -msse4.1 -w -pipe -DNDEBUG -g -fwrapv -Wall -Wstrict-prototypes
CFLAGS += -I$(LIBEVENT)/include -Isrc -L$(LIBEVENT)/lib -L/usr/local/lib -L/usr/lib
SOURCES = $(LIBEVENT)/lib/libevent.a $(LIBEVENT)/lib/libevent_core.a $(LIBEVENT)/lib/libevent_extra.a $(LIBEVENT)/lib/libevent_pthreads.a

all :
	 $(CC) $(CFLAGS) -o $(APP) src/main.c $(SOURCES)
