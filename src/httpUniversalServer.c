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
        char *buffer, *msg, *line, *method, *path;
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
                server_address.sin_port = htons(atoi("5000"));
                printf(">>> Bind Succesfull\n");
                bind(sockfd, (struct sockaddr *) &server_address, sizeof(server_address));
                printf(">>> Listening on port %s\n", argv[1]);
                listen(sockfd, 2);
                addrlen = sizeof(struct sockaddr_in);
                while (1)
                {
                    if ((connection = accept(sockfd, (struct sockaddr *) &server_address, &addrlen)) > 0 )
                        printf(">>> Client %i is requesting...\n", inet_ntoa(server_address.sin_addr));
                    buffer = (char *) malloc(sizeof(char));
                    recv(connection, buffer, 1000, 0);
                    printf("===========================<REQUISITION>=================================\n");
                    printf("%s", buffer);
                    //write_file(buffer);
                    printf("===========================</REQUISITION>================================\n\n");
                    msg = "<title>My Socket</title><p><h1>My Index</h1></p>";
                    send(connection, msg, strlen(msg), 0);
                    //http_request = parse_http_request(buffer);
                    //printf("%s\n", http_request->path);
                    files = list_dict(NULL);
                    for (aux = files->next_element; aux != NULL; aux = aux->next_element)
                    {
                        sprintf(msg, "<p><a href=./%s>%s</a></p>", aux->element, aux->element);
                        send(connection, msg, strlen(msg), 0);
                    }
                    close(connection);
                }
                    close(sockfd);
            }
        exit(0);
    }

void write_file(char * buffer) 
{ 
    FILE *file; 
    file = fopen("file.txt","a+"); /* apend file (add text to 
                                      a file or create a file if it does not exist.*/ 
    fprintf(file,"%s", buffer); /*writes*/ 
    fclose(file); /*done!*/ 
}
