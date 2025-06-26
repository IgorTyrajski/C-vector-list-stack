#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include <stdio.h>

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
void list_sort_des(IntList *lis); //descending
void list_sort_asc(IntList *lis); //ascending
int  list_get(const IntList *vec, const int index);
void list_set(IntList *lis, const int index, const int value);
void list_erase(IntList *lis, const int index);
void list_clear(IntList *lis);
bool list_empty(IntList *lis);
int list_get_size(const IntList *lis);
void print_list(const IntList* lis);

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
        lis->head=NULL;
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

    if (lis->head==NULL || index<0 || index>=size) return 0;

    IntListElement* elem = lis->head;
    while (i!=index){
        elem=elem->next;
        i++;
    }
    return elem->element;
}
void list_set(IntList *lis, const int index, const int value){
    IntListElement* elem = lis->head;
    int i=0;
    while (i!=index){
        elem=elem->next;
        i++;
    }
    elem->element=value;
}

void list_sort_des(IntList *lis){
    int s=list_get_size(lis);
    while (s>1){
        for (int i=0;i<s-1;i++){
            if (list_get(lis,i)<list_get(lis,i+1)){
                int temp = list_get(lis,i+1);
                list_set(lis,i+1,list_get(lis,i));
                list_set(lis,i,temp);
            }
        }
        s--;
    }

}
void list_sort_asc(IntList *lis){ //do poprawienia aby była efektywniejsza (O(n^3)) -> (O(n^2))
    int s=list_get_size(lis);
    while (s>1){
        for (int i=0;i<s-1;i++){
            if (list_get(lis,i)>list_get(lis,i+1)){
                int temp = list_get(lis,i+1);
                list_set(lis,i+1,list_get(lis,i));
                list_set(lis,i,temp);
            }
        }
        s--;
    }
}

void list_erase(IntList *lis, const int index){
    if (lis->head==NULL || index<0 || index>=list_get_size(lis)) return;
    if (index==0){
        IntListElement* elem = lis->head;
        lis->head=lis->head->next;
        free(elem);
        return;
    }
    IntListElement* elem = lis->head;
    for (int i = 0; i < index - 1; i++) {
        elem = elem->next;
    }

    IntListElement* temp = elem->next;
    elem->next = temp->next;
    free(temp);
}

void list_clear(IntList *lis){
    IntListElement* elem = lis->head;
    while (elem){
        IntListElement* temp=elem;
        elem=elem->next;
        free(temp);
    }
    lis->head=NULL;
}

bool list_empty(IntList *lis){
    return (list_get_size==0);
}

void print_list(const IntList* lis) {
    int size = list_get_size(lis);
    for (int i = 0; i < size; i++) {
        printf("%d ", list_get(lis, i));
    }
    printf("\n");
}
#endif // LIST_H




