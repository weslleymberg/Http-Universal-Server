#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
    {
        int sockfd, connection, addrlen;
        char buffer[100000];
        struct sockaddr_in server_address;

        if(argc != 2)
            {
                perror("Error: Invalid Arguments!\nUsage must be: ./httpUniversalServer <desired-port>\n");
                exit(1);
            }

        if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) > 0)
            {
                server_address.sin_family = AF_INET;
                server_address.sin_addr.s_addr = INADDR_ANY;
                server_address.sin_port = htons(atoi(argv[1]));
                printf(">>> Bind Succesfull\n");
                bind(sockfd, (struct sockaddr *) &server_address, sizeof(server_address));
                printf(">>> Listening on port %s\n", argv[1]);
                listen(sockfd, 1); 
                addrlen = sizeof(struct sockaddr_in);
                if ((connection = accept(sockfd, (struct sockaddr *) &server_address, &addrlen)) > 0 )
                    printf(">>> Client %i is connected...\n", inet_ntoa(server_address.sin_addr));
                recv(connection, buffer, sizeof(buffer), 0);
                printf("===========================<HEAD>=================================\n");
                printf("%s", buffer);
                printf("===========================</HEAD>================================\n");
                send(connection, "Hello World - Connection Succesfull!", 36, 0);
                close(connection);
                close(sockfd);
            }
        exit(0);
    }
