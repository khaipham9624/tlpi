.PHONY: all 
all: main

main: main.cpp libmyMath.a
	g++ -o main main.cpp -lmyMath -L. -I.

libmyMath.a: sum.o sub.o
	ar -r libmyMath.a sum.o sub.o
	ar -tv libmyMath.a
	rm sum.o sub.o

sub.o: sub.cpp
	g++ -c sub.cpp

sum.o: sum.cpp
	g++ -c sum.cpp