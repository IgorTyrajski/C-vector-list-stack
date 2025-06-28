#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} IntStack;

void stack_init(IntStack *sta);
int stack_size (IntStack *sta);
bool stack_empty(IntStack *sta);
int stack_top(IntStack *sta);
void stack_push(IntStack *sta, const int value);
void stack_pop(IntStack *sta);



void stack_init(IntStack *sta){
    sta->capacity=10;
    sta->size=0;
    sta->data=malloc(sta->capacity*sizeof(int));
}

int stack_size (IntStack *sta){
    return sta->size;
}

bool stack_empty(IntStack *sta){
    return sta->size==0;
}

int stack_top(IntStack *sta){
    if (sta->size==0) return -1;
    return sta->data[sta->size-1];
}

void stack_push(IntStack *sta, const int value){
    if (sta->size==sta->capacity){
        sta->capacity+=10;
        sta->data=realloc(sta->data,sta->capacity*sizeof(int));
    }
    sta->size++;
    sta->data[sta->size-1]=value;
}

void stack_pop(IntStack *sta){
    if (sta->size==0) return;
    sta->size--;
    if (sta->size%10<(sta->capacity/10)-1){
        sta->capacity-=10;
        sta->data=realloc(sta->data,sta->capacity*sizeof(int));
    }
}

#endif // STACK_H
