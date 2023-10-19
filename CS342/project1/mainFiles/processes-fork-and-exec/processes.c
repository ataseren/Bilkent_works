/*    -*- linux-c -*- */
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>


int main(int argc, char *argv[])
{
    int count, i;
    pid_t apid1, apid2;

    if (argc != 2) {
	printf("wrong number of arguments \n");
	printf("usage: process <numberofintegers> \n");
	exit(1);
    }

    count = atoi(argv[1]); 

    printf("this is the parent process that you started, pid = %d\n",
               (int) getpid());

    apid1 = fork();		
    if (apid1 < 0) {
	perror("main():");
	exit(1);
    }

    if (apid1 == 0) {
	printf("this is first child, pid=%d\n", 
	       (int) getpid());
	fflush(stdout);
	
	for (i = 1; i <= count; i++)
	    printf("%d\n", i);
	
	printf("first child terminating, bye...\n");
	exit(0); // child will exit and will not continue to the test of this program. 
	
    }

    // create the second child
    apid2 = fork(); 
    if (apid2 == 0) {
	printf ("this is the second child, pid=%d. It will run another program.\n", 
		(int) getpid()); 
	execlp ("/bin/ps", "ps", "aux", NULL);
	// the rest of the program will not be seen by this child since it is now loaded another program
    }


    // wait for children to terminate by using their ids. 
    printf("parent is waiting for first child\n");
    waitpid(apid1, NULL, 0);
    printf("first child finished.\n");

    printf("parent is waiting for second child\n");
    waitpid(apid2, NULL, 0);
    printf("second child finished.\n");

    printf ("parent terminating\n");     
    return 0;
}
