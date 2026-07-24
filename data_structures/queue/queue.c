#include "queue.h"

int queue[MAX];
int front = -1;
int rear = -1;

int is_empty() {
    return front == -1 ? 1: 0;
}

int is_full() {
    return rear == MAX - 1 ? 1: 0;
}

void enqueue(int value) {
    if (is_empty()) front = 0;
    if (is_full()) {
        puts("Queue is full!");
        return;
    }
    queue[++rear] = value;
}

int dequeue() {
    if (is_empty()) {
        puts("Empty queue!");
        return 0;
    }
    
    front++;
    
    if (front > rear) {
        front = rear = -1;
    }
    
    return queue[front];
}

int peek() {
    if (is_empty()) {
        puts("Empty queue!");
        return 0;
    }

    return queue[front];
}

void display() {
    if (is_empty()) {
        puts("Empty queue!");
        return;
    }
    
    for (int i = front; i <= rear; i++) {
        printf("%d\n", queue[i]);
    }
    
    puts("-----------------");
}
