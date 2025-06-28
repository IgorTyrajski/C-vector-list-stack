#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} IntVector;

void vector_init(IntVector *vec);
void vector_push_back(IntVector *vec, const int value);
void vector_pop_back(IntVector *vec);
void vector_sort_des(IntVector *vec); //descending
void vector_sort_asc(IntVector *vec); //ascending
int  vector_get(const IntVector *vec, const int index);
void  vector_set(const IntVector *vec, const int index, const int value);
void vector_erase(IntVector *vec, const int index);
void vector_free(IntVector *vec);
void vector_clear(IntVector *vec);
bool vector_empty(IntVector *vec);
int vector_get_size(const IntVector *vec);
void vector_insert(IntVector *vec, const int index, const int value);


void vector_init(IntVector *vec){
    vec->capacity=10;
    vec->size=0;
    vec->data=malloc(vec->capacity * sizeof(int));
}
void vector_push_back(IntVector *vec, const int value){
    if (vec->size==vec->capacity){
        vec->capacity+=10;
        vec->data=realloc(vec->data,vec->capacity*sizeof(int));
    }
    vec->size++;
    vec->data[vec->size-1]=value;
}
void vector_pop_back(IntVector *vec){
    if (vec->size==0) return;
    vec->size--;
    if (vec->size%10<(vec->capacity/10)-1){
        vec->capacity-=10;
        vec->data=realloc(vec->data,vec->capacity*sizeof(int));
    }
}
void vector_sort_asc(IntVector *vec){
    int s=vec->size;
    while (s>1){
        for (int i=0;i<s-1;i++){
            if (vec->data[i]>vec->data[i+1]){
                int temp = vec->data[i+1];
                vec->data[i+1]=vec->data[i];
                vec->data[i]=temp;
            }
        }
        s--;
    }
}
void vector_sort_des(IntVector *vec){
    int s=vec->size;
    while (s>1){
        for (int i=0;i<s-1;i++){
            if (vec->data[i]<vec->data[i+1]){
                int temp = vec->data[i+1];
                vec->data[i+1]=vec->data[i];
                vec->data[i]=temp;
            }
        }
        s--;
    }
}

int  vector_get(const IntVector *vec, const int index){
    if (index>=0 && index<vec->size) return vec->data[index];
    else return 0;
}

void  vector_erase(IntVector *vec, const int index){
    if (vec->size-1>=index && index>=0){
        vec->size--;
        if (vec->size%10<(vec->capacity/10)-1){
            vec->capacity-=10;
            vec->data=realloc(vec->data,vec->capacity*sizeof(int));
        }
        for (int i=index;i<vec->size-1;i++){
            vec->data[i]=vec->data[i+1];
        }
    }
}

void vector_free(IntVector *vec){
    vec->capacity=0;
    vec->size=0;
    free(vec->data);
    vec->data=NULL;
}

void vector_clear(IntVector *vec){
    vec->capacity=10;
    vec->size=0;
    vec->data=realloc(vec->data,vec->capacity*sizeof(int));
}

bool vector_empty(IntVector *vec){
    return vec->size==0;
}

int vector_get_size(const IntVector *vec){
    return vec->size;
}
void vector_insert(IntVector *vec, const int index, const int value){
    if (vec->size>=index && index>=0){
        if (vec->size==vec->capacity){
            vec->capacity+=10;
            vec->data=realloc(vec->data,vec->capacity*sizeof(int));
        }
        vec->size++;
        for (int i=vec->size;i>index;i--){
            vec->data[i]=vec->data[i-1];

        }
        vec->data[index]=value;
    }
}

void  vector_set(const IntVector *vec, const int index, const int value){
    if (index<0 || index>=vector_get_size(vec)) return;
    vec->data[index]=value;
}

#endif // VECTOR_H
