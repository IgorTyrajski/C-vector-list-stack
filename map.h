#ifndef MAP_H
#define MAP_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    char* keys;
    int* values;
    int size;
    int capacity;
} CharIntMap;

void map_init(CharIntMap* map);
int map_get(CharIntMap* map, const char key);
void map_set(CharIntMap* map, const char key, const int value);
int map_get_size(CharIntMap* map);
void map_remove(CharIntMap *map, const char key);
bool map_contains(CharIntMap *map, const char key);

void map_init(CharIntMap* map){
    map->size=0;
    map->capacity=10;
    map->keys=malloc(map->capacity*sizeof(char));
    map->values=malloc(map->capacity*sizeof(int));
}

int map_get(CharIntMap* map, const char key){
    if (!map_contains(map,key)) return -1;
    for (int i=0;i<map->size;i++){
        if (map->keys[i]==key) return map->values[i];
    }
    return -1;
}

void map_set(CharIntMap* map, const char key, const int value){
    if (map_contains(map,key)){
        for (int i=0;i<map->size;i++){
            if (map->keys[i]==key) map->values[i]=value;
        }
    }
    else{
        if (map->size==map->capacity){
        map->capacity+=10;
        map->keys=realloc(map->keys,map->capacity*sizeof(char));
        map->values=realloc(map->values,map->capacity*sizeof(int));
        }
        map->size++;
        map->keys[map->size-1]=key;
        map->values[map->size-1]=value;
    }

}

int map_get_size(CharIntMap* map) {
    return map->size;
}

void map_remove(CharIntMap *map, const char key){
    if (!map_contains(map,key)) return;
    else{
        int index=0;
        for (int i=0;i<map->size;i++){
            if (map->keys[i]==key){
                index=i;
                break;
            }
        }

        map->size--;
        if (map->size%10<(map->capacity/10)-1){
            map->capacity-=10;
            map->keys=realloc(map->keys,map->capacity*sizeof(char));
            map->values=realloc(map->values,map->capacity*sizeof(int));
        }
        for (int i=index;i<map->size;i++){
            map->keys[i]=map->keys[i+1];
            map->values[i]=map->values[i+1];
        }
    }
}

bool map_contains(CharIntMap *map, const char key){
    if (map->size==0) return false;
    for (int i=0;i<map->size;i++){
            if (map->keys[i]==key) return true;
        }
    return false;
}


void print_map(CharIntMap *map) { //dodatkowa funckcja na potzeby prezentacji
    printf("Current map contents (%d entries):\n", map_get_size(map));
    for (int i = 0; i < map->size; i++) {
        printf("  %c: %d\n", map->keys[i], map->values[i]);
    }
    printf("-----------------------------\n");
}
#endif // MAP_H