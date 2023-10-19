#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>
#include <mqueue.h>


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

//function that prints given array, for testing purposes
void printarray(int array[], int count)
{
    for (int i = 0; i < count; i++) {
        printf("%d ", array[i]);
    }
}

int main(int argc,char* argv[])
{
	//message queue elements to send histogram properties
	mqd_t mq;
	struct histogram hist;

    hist.intervalcount = atoi(argv[1]);
    hist.intervalwidth = atoi(argv[2]);
    hist.intervalstart = atoi(argv[3]);

	mq = mq_open("/clienttoserver", O_WRONLY);

	if (mq == -1) {
		perror("can not open msg queue\n");
		exit(1);
	}

	int error = mq_send(mq, (char *) &hist, sizeof(struct histogram), 0);

	if (error == -1) {
		perror("mq_send failed\n");
		exit(1);
	}


	//message queue elements to receive histogram data
	mqd_t mqfinal;
	struct mq_attr mq_attr;

    struct num num;
    struct num *receivenum;
	int r;
	char *bufptr;
	int buflen;

    for (int i = 0; i < 1000; i++)
    {
        num.data[i] = 0;
    }
    
    
	mqfinal = mq_open("/servertoclient", O_RDWR | O_CREAT, 0666, NULL);
	if (mqfinal == -1) {
		perror("can not create msg queue\n");
		exit(1);
	}

	mq_getattr(mqfinal, &mq_attr);

	// allocate large enough space for the buffer to store an incoming message
    buflen = mq_attr.mq_msgsize;
	bufptr = (char *) malloc(buflen);

	r = mq_receive(mqfinal, (char *) bufptr, buflen, NULL);
	if (r == -1) {
		perror("mq_receive failed\n");
		exit(1);
	}
	
    receivenum = (struct num *) bufptr;

	int interval[atoi(argv[1]) + 1];
    int index = 0;

    for (int i = atoi(argv[3]); i <= atoi(argv[3]) + atoi(argv[2])*5; i = i + atoi(argv[2]))
    {
        interval[index] = i;
        index++;
    }

	for(int i = 0; i < atoi(argv[1]); i++)
	{
		printf("[%d, %d): %d\n", interval[i], interval[i+1], receivenum->data[i]);
	}

	//final message to trigger termination
	num.data[0] = -1;
	error = mq_send(mq, (char *) &num, sizeof(struct num), 0);

	if (error == -1) {
		perror("mq_send failed\n");
		exit(1);
	}

	free(bufptr);
	mq_close(mqfinal);
	mq_close(mq);
    return 0;
}