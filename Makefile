CC = c99
CFLAGS = -Wall 
LDLIBS = -lz

.PHONY: all
all: rpcp

rpcp: dcp.o hcp.o protoskel.o rpcp.o

.PHONY: clean
clean:
	rm -f *.o rpcp
