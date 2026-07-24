#include "list.h"

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
