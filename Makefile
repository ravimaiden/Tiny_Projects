all: irctc

irctc:  main.o ui.o user.o
	g++ main.cpp ui.cpp user.cpp
