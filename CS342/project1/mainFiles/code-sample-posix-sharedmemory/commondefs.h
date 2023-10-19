/* -*- linux-c -*- */

#define BUFFER_SIZE 10
  
struct shared_data
{
  int in;
  int out;
  int buffer[BUFFER_SIZE];
};


#define SHAREDMEM_NAME "/somenamehere"
#define SHAREDMEM_SIZE 1024 /* bytes; large enough to hold the shared data */

#define NUM_ITEMS_TOPASS 50
