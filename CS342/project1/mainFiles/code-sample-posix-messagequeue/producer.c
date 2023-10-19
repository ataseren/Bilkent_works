
      
#include <stdlib.h>
#include <mqueue.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
           
#include "shareddefs.h"

int main()
{

	mqd_t mq;
	struct item item;
	int n;

	mq = mq_open(MQNAME, O_RDWR);
	if (mq == -1) {
		perror("can not open msg queue\n");
		exit(1);
	}
	printf("mq opened, mq id = %d\n", (int) mq);
	int i = 0;

	while (1) {
		item.id = i;
		strcpy(item.astr, "this string is sample data\n");

		n = mq_send(mq, (char *) &item, sizeof(struct item), 0);

		if (n == -1) {
			perror("mq_send failed\n");
			exit(1);
		}

		printf("mq_send success, item size = %d\n",
		       (int) sizeof(struct item));
		printf("item->id   = %d\n", item.id);
		printf("item->astr = %s\n", item.astr);
		printf("\n");
		i++;
		sleep(1);
	}

	mq_close(mq);
	return 0;
}
