all:testc

#which compiler
CC = gcc

#whre are include files kept
#INCFLAGS = -I ./sm/include -I ./sm/source -I ./common

#options for development
CFLAGS = -g -Wall -ansi -std=c99

#options for release
#CFLAGS = -O -Wall -ansi

testc: testconsumer.o msrp_sm.o share_synch.o
	$(CC) -o testc testconsumer.o msrp_sm.o share_synch.o

testconsumer.o: testconsumer.c msrp_sm.h share_synch.h msrp_cmdtype.h 
	$(CC) $(CFLAGS)  -c testconsumer.c

msrp_sm.o: msrp_sm.c msrp_sm.h msrp_cmdtype.h msrp_common.h mrp_common.h
	$(CC) $(CFLAGS)  -c msrp_sm.c

share_synch.o: share_synch.c share_synch.h
	$(CC) $(CFLAGS)  -c share_synch.c
