#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

static pthread_key_t key1;
/*  key1 this is global variable that will be bound to thread specific data;
 all threads will use key1 to access data; each thread will access its own data. */

/*
   (one-time initialization facility is not used - therefore we comment out the following)
    pthread_once_t key1_once = PTHREAD_ONCE_INIT;
*/

static void key1destructor(void *ptr)
{
    free (ptr);
}

/* 
   (one-time initialization facility is not used)                                                                                
static void keycreationonce (void) {
    pthread_key_create (&key1, key1destructor); 
}
*/


int printtdata() {
    char *p;

    p = pthread_getspecific (key1);
    printf ("printing %s\n", p); 

    return(0);
}


int putdata(long n)
{
    char astring[1000];
    char  *ptr;
    
    sprintf (astring, "data-for-thread-%ld\n",  n); 
    
    // we use key1 to access data
    // all threads use key1
    // key1 is global variable
    // but the data associated with key1 is thread-specific.
    // key1 can be used in all functions a thread is calling. 
    // here we are setting the data for key1
    ptr = pthread_getspecific (key1);
    strcpy (ptr, astring);
    return (0);
}

void *thread_task (void *x)
{
    char *ptr;

    if (pthread_getspecific (key1) == NULL) {
	ptr  = malloc (1024);
        pthread_setspecific (key1, ptr);
    }
    
    putdata((long)x);  

    // we use key1 to access data in each thread;
    // that means key (i.e., name) of data is the same
    // key1  is a global variable. 
    ptr  = pthread_getspecific(key1); 
    printf ("thread specific data for thread %ld is: %s\n",  (long)x, ptr);

    printtdata(); 
    
    pthread_exit (NULL); 
}


int main (int argc, char **argv)
{
    int result;
    pthread_t threads[100];
    long i; 
    
    pthread_key_create(&key1, key1destructor);
    // we create the key1 once (by creating it before the threads that will use it)

    /* 
       (one-time initialization facility is not used)                                                                            
       pthread_once (&key1_once, keycreationonce); 
    */
    
    for (i = 0; i < 5; i++) {
        printf("In main thread: creating thread %ld.\n", i);
        result = pthread_create(&threads[i], NULL, thread_task, (void *)i);
        if (result != 0) {
            printf ("can not create thread\n");
            exit (1);
        }
    }

    for (i=0; i<5; ++i) {
        pthread_join (threads[i], NULL);
    }
}
