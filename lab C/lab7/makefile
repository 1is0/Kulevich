all: build run clean
LR7.o: lab7.cpp book.cpp menu.cpp book.h menu.h
	      gcc -c -o LR7.o app.cpp basicunit.cpp menuunit.cpp basicunit.h menuunit.h
build: LR7.o
      	gcc -o LR7 LR7.o
run:
      	LR7.exe
clean:
      	del *.o LR7
