.PHONY: all

all: main

clean:
	rm main
	rm libmyMath.so.1.0
	rm *.o

main: main.cpp libmyMath.so.1.0
	g++ -o main main.cpp libmyMath.so.1.0

# libmyMath.so: sum.o sub.o
# 	g++ -shared -o libmyMath.so sum.o sub.o
# 	rm *.o

# use soname
libmyMath.so.1.0: sum.o sub.o
	g++ -shared -Wl,-soname,libmyMath.so.1 -o libmyMath.so.1.0 sum.o sub.o
	objdump -p libmyMath.so.1.0 |grep SONAME
	readelf -d libmyMath.so.1.0 |grep SONAME
	rm *.o

sum.o: sum.cpp
	g++ -c -fPIC sum.cpp
sub.o: sub.cpp
	g++ -c -fPIC sub.cpp
