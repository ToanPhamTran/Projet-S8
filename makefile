LDLIBS = -lwiringPi -lwiringPiDev

spi: spirasp.c
	gcc spirasp.c -o spi $(LDLIBS)

clean :
	rm -f spi

play : spi
	./spi

