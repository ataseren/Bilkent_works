
all: producer consumer

consumer: consumer.c
	gcc -Wall -o consumer consumer.c -lrt


producer: producer.c
	gcc -Wall -o producer producer.c -lrt

clean: 
	rm -fr *~ producer consumer