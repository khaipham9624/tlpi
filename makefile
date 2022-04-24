main: main.c lib/libtlpi.a
	gcc -o main main.c -Ilib -Llib -ltlpi