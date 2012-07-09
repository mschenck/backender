APP = backend

CC = gcc
LIBEVENT = /opt/tumblr/libevent-tumblr
CFLAGS = -fno-strict-aliasing -O3 -w -pipe -DNDEBUG -g -fwrapv -Wall -Wstrict-prototypes -lrt
CFLAGS += -I$(LIBEVENT)/include -Isrc -L$(LIBEVENT)/lib -L/usr/local/lib -L/usr/lib
SOURCES = $(LIBEVENT)/lib/libevent.a $(LIBEVENT)/lib/libevent_core.a $(LIBEVENT)/lib/libevent_extra.a $(LIBEVENT)/lib/libevent_pthreads.a

all :
	 $(CC) $(CFLAGS) -o $(APP) src/main.c $(SOURCES)
