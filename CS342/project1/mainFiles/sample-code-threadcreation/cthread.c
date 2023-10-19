
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>


#define MAXTHREADS  20		/* max number of threads */
#define MAXFILENAME 50		/* max length of a filename */


/* 
   thread function will take a pointer to this structure
*/
struct arg {
	int n;			/* min value */
	int m;			/* max value */
	int t_index;		/* the index of the created thread */
};


/* this is function to be executed by the threads */
static void *do_task(void *arg_ptr)
{
	int i;
	FILE *fp;
	char filename[MAXFILENAME];
	char *retreason; 

	printf("thread %d started\n", ((struct arg *) arg_ptr)->t_index);

	sprintf(filename, "output_of_thread%d.txt",
		((struct arg *) arg_ptr)->t_index);

	fp = fopen(filename, "w");
	if (fp == NULL) {
		perror("do_task:");
		exit(1);
	}

	for (i = ((struct arg *) arg_ptr)->n;
	     i <= ((struct arg *) arg_ptr)->m; ++i) {
		fprintf(fp, "integer = %d\n", i);
	}
	
	fclose(fp);
	
	retreason = malloc (200); 
	strcpy (retreason, "normal termination of thread"); 
	pthread_exit(retreason);  // just tell a reason to the thread that is waiting in join
}




int main(int argc, char *argv[])
{
	pthread_t tids[MAXTHREADS];	/*thread ids*/
	int count;		        /*number of threads*/
	struct arg t_args[MAXTHREADS];	/*thread function arguments*/
	
	int i;
	int ret;
	char *retmsg; 

	if (argc != 4) {
		printf
		    ("usage: cthread <numthreads> <minvalue> <maxvalue>\n");
		exit(1);
	}

	count = atoi(argv[1]);	/* number of threads to create */

	for (i = 0; i < count; ++i) {
		t_args[i].n = atoi(argv[2]);
		t_args[i].m = atoi(argv[3]);
		t_args[i].t_index = i;

		ret = pthread_create(&(tids[i]),
				     NULL, do_task, (void *) &(t_args[i]));

		if (ret != 0) {
			printf("thread create failed \n");
			exit(1);
		}
		printf("thread %i with tid %u created\n", i,
		       (unsigned int) tids[i]);
	}


	printf("main: waiting all threads to terminate\n");
	for (i = 0; i < count; ++i) {
	    ret = pthread_join(tids[i], (void **)&retmsg);
		if (ret != 0) {
			printf("thread join failed \n");
			exit(1);
		}
		printf ("thread terminated, msg = %s\n", retmsg);
		// we got the reason as the string pointed by retmsg
		// space for that was allocated in thread function; now freeing. 
		free (retmsg); 
	}

	printf("main: all threads terminated\n");
	return 0;
}
