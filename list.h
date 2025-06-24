#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

typedef struct IntListElement IntListElement;

struct IntListElement{
    IntListElement *prev; //previous element in the list (if NULL then its the first)
    IntListElement *next; //next  element in the list (if NULL then its last)
    int element;
};

void list_init(IntListElement *lis);
//void vector_push_back(IntVector *vec, const int value);
//void vector_pop_back(IntVector *vec);
//void vector_sort_des(IntVector *vec); //descending
//void vector_sort_asc(IntVector *vec); //ascending
//int  vector_get(const IntVector *vec, const int index);
//void  vector_erase(IntVector *vec, const int index);
//void vector_free(IntVector *vec);
//void vector_clear(IntVector *vec);
//bool vector_empty(IntVector *vec);
//int vector_get_size(const IntVector *vec);

void list_init(IntListElement *lis){
    lis->next=NULL;
    lis->prev=NULL;
}

#endif // LIST_H




