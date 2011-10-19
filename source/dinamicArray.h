#ifndef __DINAMICARREY_H__
#define __DINAMICARREY_H__

typedef struct DinamicArray{
    char[100] element;
    struct DinamicArray *next_element;
}

DinamicArray *create_list();

DinamicArray *append(DinamicArray list, char[100] item);


//char pop(char item); To be implemented...

#endif
