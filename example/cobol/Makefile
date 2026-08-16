all:
	cobc -c main.cbl -o main.cbl.o
	cobc -Q -shared -Q -Wl,-soname,mylib.so -o mylib.so main.cbl.o
	ln -sf mylib.so libmylib.so.0
	ln -sf libmylib.so.0 libmylib.so
	gcc -c main.c -o main.c.o
	cobc -x -o main main.c.o -lmylib -L. -Q -Wl,-rpath,'$$ORIGIN'