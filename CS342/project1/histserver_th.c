#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>
#include <mqueue.h>
#include <pthread.h>
#include <time.h>
#include <sys/time.h>

#define MAXTHREADS  10

//struct for properties of histogram
struct histogram {
    int intervalcount;
    int intervalwidth;
    int intervalstart;
};

//struct for carrying arrays (mostly histogram data) on message queue
struct num {
    int id;
    int data[1000];
};

//struct for thread arguments
struct arg {
    char *filename;
    int intervalcount;
};

int result[1000] = {0};
int interval[1000] = {0};

//function to be executed by the threads for calculating histogram data
static void *do_task(void *arg_ptr)
{
    char *retreason; 
	char *filename = ((struct arg *) arg_ptr)->filename;
    FILE *fp = fopen(filename, "r");

    if (fp == NULL)
    {
        perror("do_task:");
		exit(1);
    }
    char buffer[50];
    while (fgets(buffer, 50, fp))
    {
        int a = atoi(buffer);
        for (int x = 0; x <= ((struct arg *) arg_ptr)->intervalcount; x++)
        {

            if(a >= interval[x] && a < interval[x+1])
            {   
                result[x] = result[x] + 1;
                break;
            }
        }
    }
    // close the file
    fclose(fp);
	
	retreason = malloc (200); 
	pthread_exit(retreason);  // just tell a reason to the thread that is waiting in join
}

//function that prints given array, for testing purposes
void printarray(int array[], int count)
{
    for (int i = 0; i < count; i++) {
        printf("%d ", array[i]);
    }
}

int main(int argc,char* argv[])
{
    //variables for experiments
    /*
    struct timeval begin;
	struct timeval end;
    */

    //message queue elements to receive histogram properties
    mqd_t mq;
	struct mq_attr mq_attr;
	struct histogram *histptr;
    struct num *receivenum;
	int r;
	char *bufptr;
	int buflen;
    
    
	mq = mq_open("/clienttoserver", O_RDWR | O_CREAT, 0666, NULL);
	if (mq == -1) {
		perror("can not create msg queue\n");
		exit(1);
	}


	mq_getattr(mq, &mq_attr);


	// allocate large enough space for the buffer to store an incoming message
    buflen = mq_attr.mq_msgsize;
	bufptr = (char *) malloc(buflen);

	r = mq_receive(mq, (char *) bufptr, buflen, NULL);
	if (r == -1) {
		perror("mq_receive failed\n");
		exit(1);
	}
	
    //data extracted from message queue
    histptr = (struct histogram *) bufptr;

    int intervalcount = histptr->intervalcount;
    int intervalwidth = histptr->intervalwidth;
    int intervalstart = histptr->intervalstart;

	free(bufptr);

    //to set data for intervals
    int index = 0;
    for (int i = intervalstart; i <= intervalstart + intervalwidth*5; i = i + intervalwidth)
    {
        interval[index] = i;
        index++;
    }

    //thread creation
    pthread_t tids[MAXTHREADS];	/*thread ids*/
	int count;		        /*number of threads*/
	
	int i;
	int ret;
	char *retmsg; 
    struct arg t_args[MAXTHREADS];	/*thread function arguments*/

	count = atoi(argv[1]);	/* number of threads to create */
    
    //built-in function for experiments
    //gettimeofday(&begin, NULL);
	for (i = 0; i < count; ++i) {
		t_args[i].filename = argv[i+2];
		t_args[i].intervalcount = intervalcount;

		ret = pthread_create(&(tids[i]),
				     NULL, do_task, (void *) &(t_args[i]));

		if (ret != 0) {
			printf("thread create failed \n");
			exit(1);
		}
	}

	for (i = 0; i < count; ++i) {
	    ret = pthread_join(tids[i], (void **)&retmsg);
		if (ret != 0) {
			printf("thread join failed \n");
			exit(1);
		}
		// we got the reason as the string pointed by retmsg
		// space for that was allocated in thread function; now freeing. 
		free (retmsg); 
	}
    //built-in function for experiments
    //gettimeofday(&end, NULL);
    
    //message queue elements to send histogram data
    mqd_t mqfinal;
	struct num numfinal;
    for(int i = 0; i<intervalcount;i++)
    {
        numfinal.data[i] = result[i];
    }

	mqfinal = mq_open("/servertoclient", O_RDWR);

	if (mqfinal == -1) {
		perror("can not open msg queue\n");
		exit(1);
	}

	int error = mq_send(mqfinal, (char *) &numfinal, sizeof(struct num), 0);

	if (error == -1) {
		perror("mq_send failed\n");
		exit(1);
	}

    mq_getattr(mq, &mq_attr);


	// allocate large enough space for the buffer to store an incoming message
    buflen = mq_attr.mq_msgsize;
	bufptr = (char *) malloc(buflen);

	r = mq_receive(mq, (char *) bufptr, buflen, NULL);
	if (r == -1) {
		perror("mq_receive failed\n");
		exit(1);
	}

    receivenum = (struct num *) bufptr;

    free(bufptr);

    //termination trigger
    //shuts down message queues
    if(receivenum->data[0] == -1)
    {
        mq_close(mq);
        mq_close(mqfinal);
    }
    else
    { 
        printf("Queue shutdown failed!!!");
    }
    //to print experiment results
    /*
    printf("Execution took %ld seconds and %ld microseconds\n", end.tv_sec - begin.tv_sec, 
    end.tv_sec - begin.tv_sec+ end.tv_usec - begin.tv_usec);
    */

    return 0;
}