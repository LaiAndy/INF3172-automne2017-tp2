client_andy_lai: client_andy_lai.o
	gcc -o client_andy_lai client_andy_lai.o

client_andy_lai.o: client_andy_lai.c
	gcc -c -W -Wall client_andy_lai.c

.PHONY: clean

clean:
	rm -f *.o *.out client_andy_lai
