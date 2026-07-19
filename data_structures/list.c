#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int *data;
    int size;
    int capacity;
} List;

List *create_list(void) {
    List *list = malloc(sizeof(List));
    
    if (list == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    list->capacity = 4;
    list->size = 0;
    list->data = malloc(sizeof(int) * list->capacity);
    
    if (list->data == NULL) {
        free(list);
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    return list;
}

void purge_list(List *list) {
    free(list->data);
    free(list);
}

int get(const List *list, int idx, int *value) {
    if (idx < 0 || idx >= list->size) {
        fprintf(stderr, "Invalid argument!\n");
        return -1;
    }

    *value = list->data[idx];
    return 0;
}

int set(List *list, int idx, int value) {
    if (idx < 0 || idx >= list->size) {
        fprintf(stderr, "Invalid argument!\n");
        return -1;
    }

    list->data[idx] = value;
    return 0;
}

int double_capacity(List *list) {
    int new_capacity = list->capacity * 2;
    int* new_data = realloc(list->data, sizeof(int) * new_capacity);

    if (new_data == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    list->capacity = new_capacity;
    list->data = new_data;
    return 0;
}

int append(List *list, int value) {
    if (list->capacity == list->size) {
        double_capacity(list);
    }

    list->data[list->size] = value;
    list->size++;
    return 0;
}

int insert(List *list, int idx, int value) {
    if (idx < 0) {
        fprintf(stderr, "Invalid argument!\n");
        return -1;
    }

    if (idx > list->size) idx = list->size;

    if (list->capacity == list->size) {
        double_capacity(list);
    }

    list->size++;

    for (int i = list->size - 1; i > idx; i--) {
        list->data[i] = list->data[i - 1];
    }

    list->data[idx] = value;
    return 0;
}

int pop(List *list) {
    if (list->size == 0) return -1;
    list->size--;
    return 0;
}

int remove_at(List *list, int idx) {
    if (idx < 0 || idx >= list->size) {
        fprintf(stderr, "Invalid argument!\n");
        return -1;
    }
    
    for (int i = idx; i < list->size - 1; i++) {
        list->data[i] = list->data[i + 1];
    }

    list->size--;
    return 0;
}

int main() {
    List *list = create_list();
    append(list, 1);    // [1]
    append(list, 2);    // [1, 2]
    insert(list, 5, 3); // [1, 2, 3]
    set(list, 1, 10);   // [1, 10, 3]
    remove_at(list, 0); // [10, 3]
    pop(list);          // [10]

    for (int i = 0; i < list->size; i++) {
        printf("index = %d, value = %d, size = %d, capacity = %d\n", i, list->data[i], list->size, list->capacity);
    }

    purge_list(list);
    return 0;
}
