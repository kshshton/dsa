#include "stack.h"

int stack[MAX];
int top = -1;

int is_empty() {
    return top == -1 ? 1: 0;
}

int is_full() {
    return top == MAX - 1 ? 1: 0;
}

void push(int value) {
    if (is_full()) {
        puts("Stack overflow!");
        return;
    }
    
    stack[++top] = value;
}

void pop() {
    if (is_empty()) {
        puts("Stack underflow!");
        return;
    }
    
    top--;
}

int peek() {
    if (is_empty()) {
        puts("Empty stack!");
        return 0;
    }
    
    return stack[top];
}

void display() {
    if (is_empty()) {
        puts("Empty stack!");
        return;
    }
    
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}
