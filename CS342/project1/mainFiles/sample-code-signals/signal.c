#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>


/* When we press Cntl-C characters, interrupt - SIGINT - signal is sent to the process and this handler will run asynchronously. */
static void sigint_handler()
{
    printf("I received SIGINT signal. bye... \n");
    fflush(stdout);
    exit(0);
}



/* this handler will run asynchronously when SIGALARM is sent to the
 process. The alarm() function sets the duration (seconds) after which signal will be sent to the process. */
static void sigalarm_handler(int signum)
{
    printf("I received alarm signal.... \n");
    fflush(stdout);
    alarm(3);
    
}


int main()
{
    signal(SIGINT, sigint_handler);
    
    signal(SIGALRM, sigalarm_handler);
    
    alarm (3);
    
    while (1) {
        printf ("I am in loop\n");
        sleep(1);
    }
}
