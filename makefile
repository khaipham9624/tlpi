main: main.c lib/get_num.c lib/error_functions.c
	gcc -o main main.c lib/get_num.c lib/error_functions.c -I lib/