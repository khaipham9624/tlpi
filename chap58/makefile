.PHONY: all server client clean_server clean_client clean_all

all: server client

server: stream_server

stream_server: stream_server.c
	gcc -o stream_server stream_server.c

client: stream_client

stream_client: stream_client.c
	gcc -o stream_client stream_client.c

clean_server:
	rm -f stream_server

clean_client:
	rm -f stream_client

clean_all:
	rm -f stream_server stream_client