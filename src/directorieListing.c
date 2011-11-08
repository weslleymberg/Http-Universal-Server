#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <regex.h>
#include "dinamicArray.h"
#include "directorieListing.h"

DinamicArray *list_dict(char diretorie[])
{
    DIR *dir;
    regex_t regex;
    int match;
    struct dirent *ent;
    DinamicArray *diretories_list;
    int i = 0, lenght = 0;

    regcomp(&regex, "^[^.].*$", 0);
    diretories_list = create_array();
    (diretorie == NULL) ? (dir = opendir("./")) : (dir = opendir(diretorie));

    if (dir != NULL)
    {
        while ((ent = readdir(dir)) != NULL)
        {
            if (!(regexec(&regex, ent->d_name, 0, NULL, 0)))
                append(diretories_list, ent->d_name);
        }
        return diretories_list;
    }
}
