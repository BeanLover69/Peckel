#==========================================
#    Makefile: makefile for peckel 1.0
#              Copyright 2026
#                 Egon Dogo
#		   (borissopko5@gmail.com)
#	      Last Modified: 2026/02/12
#==========================================

CC=gcc
CFLAGS=-O -Wall

all: peckel

peckel: peckel.c
	$(CC) $(CFLAGS) -o peckel peckel.c -lX11

clean:
	rm -f peckel

distclean: clean
