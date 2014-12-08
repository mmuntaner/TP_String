all:String_main

String_main: String_main.cpp String.o
	g++  -o String_main String_main.cpp String.o

String.o: String.h String.cpp
	g++ -c -o String.o String.cpp

clean:
	rm *.o
