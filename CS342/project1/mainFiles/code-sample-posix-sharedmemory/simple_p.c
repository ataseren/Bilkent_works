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

int
main(int argc, char **argv)
{
	int fd, i; 
	void *sptr; 
	char *p; 


	fd = shm_open("/afilename", O_RDWR | O_CREAT, 0660);
	ftruncate(fd, 512);	
	sptr = mmap(NULL, 512, 
			 PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	close(fd);		
	p = (char *)sptr; 

	for (i=0; i<100; ++i) {
		p[i] = 10 + i; 
	}

		
	exit(0);
}
