#==========================================
#    Makefile: makefile for peckel 1.0
#              Copyright 2026
#                 Egon Dogo
#		   (borissopko5@gmail.com)
#	      Last Modified: 2026/02/12
#==========================================

peckel.out: peckel.c
	gcc peckel.c -lx11 -o peckel.out
