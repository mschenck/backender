# Backender

Simple C HTTP server for simulating latency (and varience) while load-testing intermediary HTTP service (such as a reverse proxy)

## Routes and Responses

Currently there are two route/response scenarios

1. / (root)
    * Response string: `^_^`
    * Response code:   200
    * Response timing: *random* latency (currently 300-600 ms range - TODO: make configuratoin)
2. Any other URI path
    * Response string: `Not found .. ~_~`
    * Response code:   404
    * Response timing: As fast as possible - no synthesized latency [**NOTE:**`Intended for use as a CONTROL variable`]

## Building

Only tested on Linux and Darwin

**NOTE:** You want to fix the LIBEVENT path in the Makefile (and maybe gcc if it's not in your PATH)

`make`
