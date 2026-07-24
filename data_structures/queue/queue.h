#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>

#define MAX 5

/* Global queue variables */

extern int queue[MAX];
extern int front;
extern int rear;

/* Function declarations */

int is_empty(void);

int is_full(void);

void enqueue(int value);

void dequeue(void);

int peek(void);

void display(void);

#endif // QUEUE_H
