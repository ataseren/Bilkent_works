


#include <sys/socket.h>
#include <sys/types.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>


#include "tcpshared.h"

int main()
{

        int list_sock;
        int conn_sock;
        struct sockaddr_in server_addr, client_addr;
        int length;
        char buf[1024];
        int *intptr;
        int i;
	int n; 

        list_sock = socket (AF_INET, SOCK_STREAM, 0);

        bzero (&server_addr, sizeof(server_addr));

        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
        server_addr.sin_port = htons(SERVER_PORT);

        bind (list_sock, (struct sockaddr *) &server_addr, sizeof(server_addr));

        listen (list_sock, 5);

	printf ("server started and listening\n");
	
        while (1)
        {
                conn_sock = accept (list_sock,
                          (struct sockaddr *) &client_addr,
                          (socklen_t*) &length);

                printf ("connection request received and connected to client. client port number = %d.\n", client_addr.sin_port);

                for (i=0; i<100; ++i)
                {
                        intptr = (int *) buf;
                        *intptr = i;
                        n = write (conn_sock, buf, sizeof(int));
			if (n == sizeof(int)) {
			    printf ("sent data %d\n", i); 
			}
                }

                * ((int *)buf) = -1;
                write (conn_sock, buf, sizeof(int));

                close (conn_sock);

                printf ("server closed connection to client\n");
		fflush (stdout); 
        }
}

