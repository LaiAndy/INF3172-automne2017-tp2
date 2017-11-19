all: client serveur

client:
	gcc -Wall -o client client.c

serveur:
	gcc -Wall -o serveur serveur.c

.PHONY: clean

clean:
	rm -f *.o *.out client
	rm -f *.o *.out serveur
