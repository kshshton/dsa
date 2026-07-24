#include "hash_set.h"

int hash(int value, int capacity) {
    if (value < 0)
        value = -value;
        
    return value % capacity;
}

HashSet *createSet(int capacity) {
    HashSet *set = malloc(sizeof(HashSet));

    set->capacity = capacity;
    set->size = 0;
    set->buckets = calloc(capacity, sizeof(Node*));
    
    return set;
}

int contains(HashSet *set, int value) {
    int idx = hash(value, set->capacity);
    Node *curr = set->buckets[idx];
    
    while(curr != NULL) {
        if (curr->value == value)
            return 1;
            
        curr = curr->next;
    }
    
    return 0;
}

void add(HashSet *set, int value) {
    int idx = hash(value, set->capacity);
    Node *curr = set->buckets[idx];
    
    while (curr != NULL) {
        if (curr->value == value) {
            return;
        }
        
        curr = curr->next;
    }
    
    Node *new_node = malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = set->buckets[idx];
    set->buckets[idx] = new_node;
    set->size++;
}

void display(HashSet *set) {
    for (int i = 0; i < set->capacity; i++) {
        Node *curr = set->buckets[i];
        
        while (curr != NULL) {
            printf("%d\n", curr->value);
            curr = curr->next;
        }
    }
}
