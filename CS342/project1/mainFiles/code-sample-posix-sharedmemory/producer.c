/* -*- linux-c -*- */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
        
#include "commondefs.h"

int
main(int argc, char **argv)
{

	int i;
	int fd;			
	char sharedmem_name[200];	

	void *shm_start;
	struct shared_data *sdata_ptr; /* pointer to the shared data */
	struct stat sbuf;

	if (argc != 1) {
		printf("usage: producer\n");
		exit(1);
	}

	strcpy(sharedmem_name, SHAREDMEM_NAME); 

	/* create a shared memory segment */
	fd = shm_open(sharedmem_name, O_RDWR | O_CREAT, 0660);
	if (fd < 0) {
		perror("can not create shared memory\n");
		exit (1); 

	} else {
		printf
		    ("sharedmem create success, fd = %d\n", fd);
	}

	/* set the size of the shared memory */
	ftruncate(fd, SHAREDMEM_SIZE);	

	fstat(fd, &sbuf); /* get info about shared memmory */
	/* check the size */
	printf("size = %d\n", (int) sbuf.st_size); 

	// map the shared memory into the address space of the process 
	shm_start = mmap(NULL, sbuf.st_size, 
			 PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

	if (shm_start < 0) {
		perror("can not map the shared memory \n");
		exit (1); 
	} else
		printf
		    ("mapping ok, start address = 0x%lx\n", 
		     (unsigned long) shm_start);

	close(fd);		
        /* we no longer need the file desciptor */

	sdata_ptr = (struct shared_data *) shm_start;

	sdata_ptr->in = 0; 
	sdata_ptr->out = 0; 

	i = 0; 

	while (1) {
		i++; /* we produced an integer: i */

		while ((sdata_ptr->in+1) % BUFFER_SIZE == sdata_ptr->out)
		  ; // buffer is full - wait in a busy loop

		sdata_ptr->buffer[sdata_ptr->in] = i; 
		sdata_ptr->in = (sdata_ptr->in + 1) % BUFFER_SIZE; 
		
		printf ("producer put item %d into buffer\n", i); 
		sleep (1); /* sleep 1 second */

		if (i == NUM_ITEMS_TOPASS)
			break; 
	}
		
	exit(0);
}
