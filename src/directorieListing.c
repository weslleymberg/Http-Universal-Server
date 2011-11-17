#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <regex.h>
#include <string.h>
#include "dinamicArray.h"
#include "directorieListing.h"

DinamicArray *list_dict(char *directorie)
{
    DIR *dir;
    regex_t regex;
    struct dirent *ent;
    DinamicArray *directories_list;

    regcomp(&regex, "^[^.].*$", 0);
    directories_list = create_array();
    ((directorie == NULL) || (strcmp(directorie, "/") == 0)) ? (dir = opendir("./")) : (dir = opendir(directorie));

    if (dir != NULL)
    {
        while ((ent = readdir(dir)) != NULL)
        {
            if (!(regexec(&regex, ent->d_name, 0, NULL, 0)))
                append(directories_list, ent->d_name);
        }
        return directories_list;
    }
    append(directories_list, "Invalid path");
    return directories_list;
}

