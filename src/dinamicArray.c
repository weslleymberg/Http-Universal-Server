#include <stdlib.h>
#include <string.h>
#include "dinamicArray.h"

DinamicArray *create_array(void)
{
    DinamicArray *new = (DinamicArray *) malloc(sizeof(DinamicArray));
    new->next_element = NULL;
    return new;
}

void append(DinamicArray *list, char *item)
{
    DinamicArray *new, *aux;

    new = create_array();
    new->element = (char *) malloc(strlen(item));
    strncpy(new->element, item, strlen(item));

    aux = list;
    while (aux->next_element != NULL)
    {
        aux = aux->next_element;
    }

    aux->next_element = new;
}
