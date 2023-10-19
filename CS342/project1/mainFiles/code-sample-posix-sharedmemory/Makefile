
all: producer consumer simple_p simple_c


consumer: consumer.c
	gcc -Wall -g -o consumer consumer.c -lrt


producer: producer.c
	gcc -Wall -g -o producer producer.c -lrt

simple_p: simple_p.c
	gcc -Wall -g -o simple_p simple_p.c -lrt
	  
simple_c: simple_c.c
	gcc -Wall -g -o simple_c simple_c.c -lrt

clean:
	rm -fr producer consumer simple_p simple_c *~ *.o   core*
