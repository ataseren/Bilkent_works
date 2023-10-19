

// In this program, parent creates a child, and then parent sends data to the child via a pipe. 

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int
main(int argc, char *argv[])
{	
	int fd[2]; 
	int pid; 
	int i; 

	if (pipe(fd) < 0) {
	    printf ("could not create pipe\n"); 
	    exit (1); 
	}

	// pipe created. fd[0] is READ end, and fd[1] is WRITE end. 

	pid = fork(); 
	if (pid < 0) {
	    printf ("could not create child\n"); 
	    exit (1); 
	}

	if (pid == 0) {
	    // this is child
	    
	    close (fd[1]); // close the write end. child will read (receive) data. 

	    printf ("This is the child process. It will received data.\n");
	    
	    unsigned char recv_byte;
	    while (read(fd[0], &recv_byte, 1) > 0)
	    {
		printf ("%d ", recv_byte);
	    }
	    
	    printf ("\n"); 
	    fflush (stdout); 
	    close(fd[0]); 
	    printf ("child terminating\n"); 
	}
	else {
	    // this is parent
	    close(fd[0]);  // close the read end. parent will write (send) data. 
	    
	    // send some number of bytes
	    unsigned char sent_byte; 
	    for (i=0; i < 100; ++i)  {
		sent_byte = (unsigned char) i;
		write (fd[1], &sent_byte, 1);
	    }
	    
	    close(fd[1]); 
	    printf ("parent terminating\n"); 
	    exit (0); 
	}

	return 0; 
}
