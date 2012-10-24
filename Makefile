CC = c99
CFLAGS = -Wall -Wno-unused-variable -lz

.PHONY: all
all: rpcp

rpcp: dcp.o hcp.o protoskel.o rpcp.o
	$(CC) $(CFLAGS) dcp.o hcp.o protoskel.o rpcp.o -o rpcp

.PHONY: clean
clean:
	rm -f *.o rpcp
