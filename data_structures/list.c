#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int* data;
    int size;
    int capacity;
} List;

List* create_list() {
    List* list = malloc(sizeof(List));

    list->capacity = 4;
    list->size = 0;
    list->data = malloc(sizeof(int) * list->capacity);

    return list;
}

int get(List* list, int idx) {
    if (idx < 0 || idx > list->size - 1) {
        fprintf(stderr, "Invalid argument!\n");
        return 1;
    }

    return list->data[idx];
}

void set(List* list, int idx, int value) {
    if (idx < 0 || idx > list->size - 1) {
        fprintf(stderr, "Invalid argument!\n");
    }

    list->data[idx] = value;
}

void double_capacity(List* list) {
    list->capacity *= 2;
    int* new_data = realloc(list->data, sizeof(int) * list->capacity);

    if (new_data == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    list->data = new_data;
}

void append(List* list, int value) {
    if (list->capacity == list->size) {
        double_capacity(list);
    }

    list->data[list->size] = value;
    list->size++;
}

void insert(List* list, int idx, int value) {
    if (idx < 0) fprintf(stderr, "Invalid argument!\n");

    if (idx > list->size) idx = list->size;

    if (list->capacity == list->size) {
        double_capacity(list);
    }

    list->size++;

    for (int i = idx; i < list->size; i++) {
        int temp = list->data[idx];
        list->data[i++] = temp;
    }

    list->data[idx] = value;
}

void pop(List* list) {
    list->size--;
}

void remove_at(List* list, int idx) {
    for (int i = idx; i < list->size - 1; i++) {
        list->data[i] = list->data[i + 1];
    }

    list->size--;
}

int main() {
    List* list = create_list();
    append(list, 1);    // [1]
    append(list, 2);    // [1, 2]
    insert(list, 5, 3); // [1, 2, 3]
    set(list, 1, 10);   // [1, 10, 3]
    remove_at(list, 0); // [10, 3]
    pop(list);          // [10]
    printf("%d\n", get(list, 0));

    for (int i = 0; i < list->size; i++) {
        printf("index = %d, value = %d, size = %d, capacity = %d\n", i, list->data[i], list->size, list->capacity);
    }

    return 0;
}
