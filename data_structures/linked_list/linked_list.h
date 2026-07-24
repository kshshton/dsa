#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

/* Function declarations */

void insert_up(Node **head, int value);

void insert_back(Node **head, int value);

int contains(Node *head, int value);

void remove_value(Node **head, int value);

void display(Node *head);

#endif // LINKED_LIST_H
