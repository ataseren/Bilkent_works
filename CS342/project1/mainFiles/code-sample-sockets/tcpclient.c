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

        int  sock;
        struct sockaddr_in server_addr;
        int ret;
        char buf[1024];
        int x;
	
        sock = socket (AF_INET, SOCK_STREAM, 0);

        bzero (&server_addr, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(SERVER_PORT);
        inet_pton (AF_INET, SERVER_IP, &server_addr.sin_addr);

        ret = connect (sock,
                       (const struct sockaddr *) &server_addr,
                       sizeof (server_addr));

        if (ret != 0) {
                printf ("connect failed\n");
                exit (0);
        }

	printf ("connection established to server at the local machine.\n");

        x = 0;
        while (x != -1) {
                read (sock, buf , sizeof(int));
                x = *((int *)buf);
                if (x != -1)
                        printf ("int rcvd = %d\n", x);
        }

	printf ("finished receiving data. client terminating\n"); 
        close (sock);

        exit (0);

}


