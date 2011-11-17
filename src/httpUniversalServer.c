#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libwebapp/http_messages.h>
#include "directorieListing.h"
#include "dinamicArray.h"

void write_file(char*);

int main(int argc, char *argv[])
    {
        int sockfd, connection, addrlen;
        char *buffer;
        struct sockaddr_in server_address;
        DinamicArray *files, *aux;
        HTTPRequest* http_request;

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
                listen(sockfd, 2);
                addrlen = sizeof(struct sockaddr_in);
                while (1)
                {
                    if ((connection = accept(sockfd, (struct sockaddr *) &server_address, &addrlen)) > 0 )
                        printf(">>> Client %i is requesting...\n", inet_ntoa(server_address.sin_addr));
                    buffer = (char *) malloc(1000);
                    recv(connection, buffer, 1000, 0);
                    printf("===========================<REQUISITION>=================================\n");
                    printf("%s", buffer);
                    printf("===========================</REQUISITION>================================\n\n");
                    send(connection, "<title>My Socket</title><p><h1>My Index</h1></p>", 48, 0);
                    http_request = parse_http_request(buffer);
                    files = list_dict(http_request->path);
                    for (aux = files->next_element; aux != NULL; aux = aux->next_element)
                    {
						send(connection, "<p><a href=\"", 12, 0);
						send(connection, aux->element, strlen(aux->element), 0);
						send(connection, "\">", 2, 0);
						send(connection, aux->element, strlen(aux->element), 0);
						send(connection, "</a></p>", 8, 0);
                    }
                    close(connection);
                }
                    close(sockfd);
            }
        exit(0);
    }
