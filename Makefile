CC = c99
CFLAGS = -Wall

.PHONY: all
all: rpcp

rpcp: dcp.o hcp.o rpcp.o

.PHONY: clean
clean:
	rm -f *.o rpcp
