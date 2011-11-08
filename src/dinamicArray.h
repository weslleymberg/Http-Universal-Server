#ifndef __DINAMICARREY_H__
#define __DINAMICARREY_H__

typedef struct DinamicArray{
    char element[100];
    struct DinamicArray *next_element;
} DinamicArray;

DinamicArray *create_array(void);

void append(DinamicArray *list, char *item);

//char pop(char item); To be implemented...

#endif
