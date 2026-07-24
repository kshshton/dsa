#ifndef HASHSET_H
#define HASHSET_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

typedef struct {
    int capacity;   // Number of buckets
    int size;       // Number of stored elements
    Node **buckets; // Array of pointers to linked lists
} HashSet;

/* Function prototypes */

int hash(int value, int capacity);

HashSet *createSet(int capacity);

int contains(HashSet *set, int value);

void add(HashSet *set, int value);

void display(HashSet *set);

#endif // HASHSET_H
