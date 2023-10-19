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
	char c; 
	struct stat sbuf;  

	fd = shm_open("/afilename", O_RDWR, 0660);  
	fstat(fd, &sbuf);
	sptr = mmap(NULL, sbuf.st_size, 
		    PROT_READ | PROT_WRITE, MAP_SHARED, 
		    fd, 0);
	close(fd);
	p = (char *)sptr; 
	
	for (i=0; i<100; ++i) {
		c = p[i]; 
		printf ("%d ", c); 
	}
	printf ("\n");

	shm_unlink ("/afilename");	

	exit(0);
}
