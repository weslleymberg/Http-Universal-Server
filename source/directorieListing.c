#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include "directorielisting.h"

int main()
{
    char *parser, i;

    parser = (char *) list_dict("/home");
    for (i=0; i < 10; i++){
        printf("%i", parser[i]);
    }
}

char *list_dict(char directorie)
{
    DIR *dir;
    struct dirent *ent;
    char *list, *first;
    int i = 0, lenght = 0;

    dir = opendir(atos(directorie));

    if (dir != NULL) 
    {
        while ((ent = readdir(dir)) != NULL)
        {

        }
        return first;
    }
}
