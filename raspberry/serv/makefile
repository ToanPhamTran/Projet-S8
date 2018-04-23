LDLIBS = -lpthread

serveur: serveur.c
	gcc serveur.c -o serveur $(LDLIBS)

clean :
	rm -f serveur

play : serveur
	./serveur

