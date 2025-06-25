#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

typedef struct IntListElement IntListElement;


struct IntListElement{
    IntListElement *next; //next  element in the list (if NULL then its last)
    int element;
};

typedef struct {
    IntListElement* head;
} IntList;


void list_init(IntList *lis);
void list_push_back(IntList *lis, const int value);
void list_pop_back(IntList *lis);
void list_pop_front(IntList *lis);
void list_push_front(IntList *vec, const int value);
//void vector_sort_des(IntVector *vec); //descending
void list_sort_asc(IntList *lis); //ascending
int  list_get(const IntList *vec, const int index);
//void  vector_erase(IntVector *vec, const int index);
//void vector_clear(IntVector *vec);
//bool vector_empty(IntList *vec);
int list_get_size(const IntList *lis);

void list_init(IntList *lis){
    lis->head=NULL;
}

void list_push_back(IntList *lis, const int value){
    IntListElement* new_elem = (IntListElement*)malloc(sizeof(IntListElement));
    new_elem->element=value;
    new_elem->next=NULL;
    if (lis->head==NULL){
        lis->head=new_elem;
    } else{
        IntListElement* elem = lis->head;
        while (elem->next!=NULL) elem=elem->next;
        elem->next=new_elem;
    }

}

void list_pop_back(IntList *lis){
    if (lis->head==NULL) return; //0 elements
    if (lis->head->next==NULL) { //1 element
        free(lis->head);
        lis->head==NULL;
    }
    IntListElement* elem = lis->head;
    while (elem->next->next!=NULL) elem=elem->next;
    free(elem->next);
    elem->next=NULL;
}

void list_pop_front(IntList *lis){
    if (lis->head==NULL) return;
    lis->head=lis->head->next;
    free(lis->head);
}

void list_push_front(IntList *lis, const int value){
    IntListElement* new_elem = (IntListElement*)malloc(sizeof(IntListElement));
    new_elem->element=value;
    new_elem->next=lis->head;
    lis->head=new_elem;
}

int list_get_size(const IntList *lis){
    int size=0;
    IntListElement* elem = lis->head;
    while (elem!=NULL) {
        size++;
        elem=elem->next;
    }
    return size;
}

int  list_get(const IntList *lis, const int index){
    int i=0;
    int size=list_get_size(lis);

    if (lis->head==NULL || index<0 || index>=size-1) return 0;

    IntListElement* elem = lis->head;
    while (i!=index){
        elem=elem->next;
        i++;
    }
    return elem->element;
}

void list_sort_asc(IntList *lis){ //do zrobienia
    int s=list_get_size(lis);
    
}


#endif // LIST_H




