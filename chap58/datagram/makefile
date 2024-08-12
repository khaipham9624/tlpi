.PHONY: all server client clean_server clean_client clean_all

all: server client

server: datagram_server

datagram_server: datagram_server.c
	gcc -o datagram_server datagram_server.c

client: datagram_client

datagram_client: datagram_client.c
	gcc -o datagram_client datagram_client.c

clean_server:
	rm -f datagram_server

clean_client:
	rm -f datagram_client

clean_all:
	rm -f datagram_server datagram_client