#include "linked_list.h"

void insert_up(Node **head, int value) {
    Node *new_node = malloc(sizeof(Node));

    new_node->value = value;
    new_node->next = *head;
    *head = new_node;
}

void insert_back(Node **head, int value) {
    Node *new_node = malloc(sizeof(Node));

    new_node->value = value;
    new_node->next = NULL;

    Node *curr = *head;
    
    while (curr->next != NULL) {
        curr = curr->next;
    }
    
    curr->next = new_node;
}

int contains(Node *head, int value) {
    Node *curr = head;
    
    while (curr != NULL) {
        if (curr->value == value) return 1;
        curr = curr->next;
    }
    
    return 0;
}

void remove_value(Node **head, int value) {
    Node *curr = *head;
    Node *prev = NULL;
    
    while (curr != NULL) {
        if (curr->value == value) {
            if (prev == NULL)
                *head = curr->next;
            else
                prev->next = curr->next;
            free(curr);
            return;
        }
        
        prev = curr;
        curr = curr->next;
    }
}

void display(Node *head) {
    Node *curr = head;

    while(curr != NULL) {
        printf("%d\n", curr->value);
        curr = curr->next;
    }
    
    if (curr == NULL) puts("NULL");
}
