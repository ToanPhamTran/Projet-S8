LDLIBS = -lwiringPi -lwiringPiDev

all : spi.o conversion.o fic.o
	gcc spi.o conversion.o fic.o -o Programme $(LDLIBS)

spi.o: spirasp.c conversion.h fic.h
	gcc -c spirasp.c -o spi.o $(LDLIBS)

conversion.o: conversion.c
	gcc -c conversion.c -o conversion.o

fic.o : fic.c
	gcc -c fic.c -o fic.o $(LDLIBS)

clean :
	rm -f Programme spi.o conversion.o fic.o

play : Programme
	./Programme

