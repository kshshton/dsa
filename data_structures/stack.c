#include <stdio.h>

# define MAX 5


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

int main() {
    push(10);                  // [10]
    push(20);                  // [10, 20]
    push(30);                  // [10, 20, 30]
    display();
    pop();                     // [10, 20]
    printf("%d\n", peek());    // 20
    display();
    pop();                     // [10]
    pop();                     // []
    pop();                     // Stack underflow!

    return 0;
}
