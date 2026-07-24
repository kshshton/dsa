#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} List;

/* Function declarations */

List *create_list(void);

void purge_list(List *list);

int get(const List *list, int idx, int *value);

int set(List *list, int idx, int value);

int double_capacity(List *list);

int append(List *list, int value);

int insert(List *list, int idx, int value);

int pop(List *list);

int remove_at(List *list, int idx);

#endif // LIST_H
