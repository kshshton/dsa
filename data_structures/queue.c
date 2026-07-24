#include <stdio.h>

# define MAX 5


int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int value) {
    if (front == -1) front = 0;
    queue[++rear] = value;
}

void dequeue() {
    if (front == -1) {
        puts("Empty queue!");
        return;
    }
    
    front++;
    
    if (front > rear) {
        front = rear = -1;
    }
}

int peek() {
    if (front == -1) {
        puts("Empty queue!");
        return 0;
    }

    return queue[front];
}

void display() {
    if (front == -1 || rear == -1) {
        puts("Empty queue!");
        return;
    }
    
    for (int i = front; i <= rear; i++) {
        printf("%d\n", queue[i]);
    }
    
    puts("-----------------");
}

int main() {
    enqueue(10); // [10]
    enqueue(20); // [10, 20]
    enqueue(30); // [10, 20, 30]
    display();
    dequeue();   // [20, 30]
    dequeue();   // [30]
    dequeue();   // []
    enqueue(10); // [10]
    enqueue(20); // [10, 20]
    display();
    printf("%d\n", peek());      // 10

    return 0;
}
