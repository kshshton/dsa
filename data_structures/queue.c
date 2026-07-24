#include <stdio.h>

# define MAX 5


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

void dequeue() {
    if (is_empty()) {
        puts("Empty queue!");
        return;
    }
    
    front++;
    
    if (front > rear) {
        front = rear = -1;
    }
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

int main() {
    enqueue(10);            // [10]         {front: 0;  rear: 0}
    enqueue(20);            // [10, 20]     {front: 0;  rear: 1}
    enqueue(30);            // [10, 20, 30] {front: 0;  rear: 2}
    display();           
    dequeue();              // [20, 30]     {front: 1;  rear: 2}
    dequeue();              // [30]         {front: 2;  rear: 2}
    dequeue();              // []           {front: -1; rear: -1}
    enqueue(10);            // [10]         {front: 0;  rear: 0}
    enqueue(20);            // [10, 20]     {front: 0;  rear: 1}
    enqueue(20);            // [10, 20]     {front: 0;  rear: 2}
    enqueue(20);            // [10, 20]     {front: 0;  rear: 3}
    enqueue(20);            // [10, 20]     {front: 0;  rear: 4}
    enqueue(50);            // [10, 20]     Error: Queue is full!
    enqueue(50);            // [10, 20]     Error: Queue is full!
    display();
    printf("%d\n", peek()); // 10

    return 0;
}
