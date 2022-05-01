INCLUDEDIR = .
LIBDIR = ../lib
BIN = main
OBJECTS = *.o
CSOURCES = *c
CFLAGS = -I$(INCLUDE) -L$(LIBDIR)

$(BIN): $(OBJECTS)
	gcc -o $@ $^
	rm $^

$(OBJECTS): $(CSOURCES)
	gcc -c $(CFLAGS) $^ 