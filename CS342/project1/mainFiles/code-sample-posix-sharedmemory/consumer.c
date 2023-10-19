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
	char sharedmem_name[200];
	int fd;		

	void *shm_start;	
	struct shared_data *sdata_ptr; 
	
	struct stat sbuf;  
        // attributes of the file referring to the segment

	if (argc != 1) {
		printf("usage: consumer \n");
		exit(1);
	}

	strcpy(sharedmem_name, SHAREDMEM_NAME);

	fd = shm_open(sharedmem_name, O_RDWR, 0660);  

	if (fd < 0) {
		perror("can not open shared memory\n");
		exit (1); 
	} else {
		printf
		    ("sharedmem open success, fd = %d  \n", fd);
	}

	fstat(fd, &sbuf);
	printf("size of sharedmem = %d\n", (int) sbuf.st_size);

	// map the shared segment into your address space
	shm_start =
	    mmap(NULL, sbuf.st_size, 
		 PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

	if (shm_start < 0) {
		perror("can not map shared memory \n");
		exit (1); 
	} else
		printf("mapping ok, start address = 0x%lx\n",
		       (unsigned long) shm_start);

	close(fd);


	sdata_ptr = (struct shared_data *)  shm_start; 

	while (1) {
        /*  note that the following code is not race condition free (not synchronized);
            that means if producer and consumer access shared  data in an
            interleaved manner (which may happen sometimes), data corruption may occur */
        
		while (sdata_ptr->in == sdata_ptr->out) 
		  ; // buffer is empty -- wait in a busy loop

		i = sdata_ptr->buffer[sdata_ptr->out]; 
		sdata_ptr->out = (sdata_ptr->out + 1) % BUFFER_SIZE; 
		
		printf ("consumer retrieved item %d from buffer\n", i); 

		sleep (1); 

		if (i == NUM_ITEMS_TOPASS) 
			break; 
	}

	shm_unlink(sharedmem_name);	
        // remove the shared segment

	printf("removed the shared memory segment!. bye...\n");
	exit(0);
}
