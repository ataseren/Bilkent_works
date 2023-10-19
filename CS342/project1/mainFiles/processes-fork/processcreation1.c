  
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
   pid_t  n; // stores process id
   int i; 
   pid_t parentid;
   int x;

   parentid = getpid();

   printf ("I am parent and my pid is: %d\n", parentid); 
   
   for (i = 0; i < 3; ++i) {
       n = fork();
       if (n == 0) {
	   /* this part executed by child process*/

	   srandom(100 + i*10); 
	   printf ("I am child=%d and mypid=%d\n",  i, getpid());
	   int k = 0; 
	   while (k < 10) {
	       k = k+1; 
	       printf ("iteration=%d: I am child=%d and mypid=%d\n", k, getpid(), i);
	       x = 1000000 + 1000000 * (random() / RAND_MAX);
	       usleep(x); 
	   }
	   exit(0); /* child is terminating */
       }
       else {
	   /* parent process */
	   printf ("parent created child and child pid= %d\n", n);
       }
   }


   // wait for all children to terminate
   for (i=0; i<3; ++i)
       wait(NULL); 

   printf ("all children terminated. bye... \n");

}
