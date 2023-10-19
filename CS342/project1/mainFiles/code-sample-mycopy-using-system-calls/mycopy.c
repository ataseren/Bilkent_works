
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h>

#define INSIZE 10

char infilename[128];
char outfilename[128];

char buf[1024];

int fd1;
int fd2; 

int main()
{
    printf ("enter input file name\n");
    scanf ("%s", infilename); 
    printf ("enter output file\n");
    scanf ("%s", outfilename); 
    
    
    printf ("%s %s\n", infilename, outfilename);
    
    fd1 = open (infilename, O_RDONLY);
    if (fd1 < 0) {
        printf ("error in opening");
        exit (1);
    }
    fd2 = open (outfilename, O_WRONLY | O_CREAT, 0600);
    
    int n, m; 
    while (1) {
        n  = read (fd1, buf, INSIZE);
        if (n > 1) {
            m  = write (fd2, buf, n);
            if (m < 0)
                printf ("write failed\n");
	    
	}  else
	    break; 
    }
    
    close (fd1);
    close (fd2);
    printf ("finished copying\n"); 
}
