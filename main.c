#include <stdio.h>
#include "vector.h"
#include "list.h"

int main() {
    const int c=2; //1 - testing vector, 2 = list, 3 - stack
    switch (c){
    case 1:{
        IntVector vec;

        // Inicjalizacja
        vector_init(&vec);
        printf("Vector initialized. Size: %d, Capacity: %d\n", vec.size, vec.capacity);

        // Dodawanie elementów
        for (int i = 0; i < 15; i++) {
            vector_push_back(&vec, i * 10);
        }
        printf("After push_back 15 elements:\n");
        for (int i = 0; i < vector_get_size(&vec); i++) {
            printf("%d ", vector_get(&vec, i));
        }
        printf("\nSize: %d, Capacity: %d\n", vec.size, vec.capacity);

        // Wstawianie elementów (TEST INSERT)
        vector_insert(&vec, 0, 999);                  // Na początek
        vector_insert(&vec, vec.size / 2, 555);       // Do środka
        vector_insert(&vec, vec.size, 777);           // Na koniec

        printf("After vector_insert (start, middle, end):\n");
        for (int i = 0; i < vector_get_size(&vec); i++) {
            printf("%d ", vector_get(&vec, i));
        }
        printf("\nSize: %d, Capacity: %d\n", vec.size, vec.capacity);

        // Usuwanie ostatniego elementu
        vector_pop_back(&vec);
        printf("After pop_back:\n");
        for (int i = 0; i < vector_get_size(&vec); i++) {
            printf("%d ", vector_get(&vec, i));
        }
        printf("\nSize: %d, Capacity: %d\n", vec.size, vec.capacity);

        // Usuwanie elementu o indeksie 5
        vector_erase(&vec, 5);
        printf("After erase element at index 5:\n");
        for (int i = 0; i < vector_get_size(&vec); i++) {
            printf("%d ", vector_get(&vec, i));
        }
        printf("\nSize: %d, Capacity: %d\n", vec.size, vec.capacity);

        // Test sortowania rosnącego
        vector_push_back(&vec, 25);
        vector_push_back(&vec, 5);
        printf("Before ascending sort:\n");
        for (int i = 0; i < vector_get_size(&vec); i++) {
            printf("%d ", vector_get(&vec, i));
        }
        printf("\n");
        vector_sort_asc(&vec);
        printf("After ascending sort:\n");
        for (int i = 0; i < vector_get_size(&vec); i++) {
            printf("%d ", vector_get(&vec, i));
        }
        printf("\n");

        // Test sortowania malejącego
        vector_sort_des(&vec);
        printf("After descending sort:\n");
        for (int i = 0; i < vector_get_size(&vec); i++) {
            printf("%d ", vector_get(&vec, i));
        }
        printf("\n");

        // Test vector_empty
        printf("Is vector empty? %s\n", vector_empty(&vec) ? "Yes" : "No");

        // Czyszczenie vectora (reset, ale nie free)
        vector_clear(&vec);
        printf("After vector_clear:\n");
        printf("Size: %d, Capacity: %d\n", vec.size, vec.capacity);

        // Zwolnienie pamięci
        vector_free(&vec);
        printf("After vector_free:\n");
        printf("Size: %d, Capacity: %d, data pointer: %p\n", vec.size, vec.capacity, (void*)vec.data);

        break;
    }
    case 2:{
        IntList myList;
    list_init(&myList);
    printf("List initialized. Empty? %s\n", list_empty(&myList) ? "Yes" : "No");

    // Test push_back
    for (int i = 1; i <= 5; i++) {
        list_push_back(&myList, i * 10);
    }
    printf("After push_back 5 elements: ");
    print_list(&myList);

    // Test push_front
    list_push_front(&myList, 99);
    printf("After push_front 99: ");
    print_list(&myList);

    // Test pop_back
    list_pop_back(&myList);
    printf("After pop_back: ");
    print_list(&myList);

    // Test pop_front
    list_pop_front(&myList);
    printf("After pop_front: ");
    print_list(&myList);

    // Test get & set
    printf("Element at index 2: %d\n", list_get(&myList, 2));
    list_set(&myList, 2, 777);
    printf("After set index 2 to 777: ");
    print_list(&myList);

    // Test erase
    list_erase(&myList, 1);
    printf("After erase index 1: ");
    print_list(&myList);

    // Test sort ascending
    list_push_back(&myList, 3);
    list_push_back(&myList, 42);
    list_sort_asc(&myList);
    printf("After sort ascending: ");
    print_list(&myList);

    // Test sort descending
    list_sort_des(&myList);
    printf("After sort descending: ");
    print_list(&myList);

    // Test clear
    list_clear(&myList);
    printf("After clear. Empty? %s\n", list_empty(&myList) ? "Yes" : "No");
        break;
    }
    case 3:{

        break;
    }
    }



    return 0;
}
