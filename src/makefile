# design pattern makefile
CC=g++

main: main.o iterator.o state.o
	$(CC) -o main main.o iterator.o state.o

main.o: main.cpp
	$(CC) -c main.cpp
	
iterator.o: iterator.cpp iterator.h
	$(CC) -c iterator.cpp

state.o: state.cpp state.h
	$(CC) -c state.cpp

clean:
	rm main main.o iterator.o state.o
