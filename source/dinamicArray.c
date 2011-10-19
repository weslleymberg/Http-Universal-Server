#include "dinamicArray.c"
#include <stdlib.h>

DinamicArray *create_list(){
    struct DinamicArray new_list;

    new_list = (DinamicArray *) malloc(sizeof(DinamicArray));
    new_list->element = NULL;
    new_list->next_element = NULL;
    return new_list;
}

DinamicArray *append(DinamicArray *list, char[100] item){
    if (list->element == NULL){
        list->element = item;
    }
    else{
        do{
            last_element = list->next_element;
        } while (list->next_element != NULL);
        new_element = last_element->next_element;
        new_element = (DinamicArray *) malloc(sizeof(DinamicArray));
        new_element->element = item;
        new_element->next_element = NULL;
    }
    return new_element;
}
