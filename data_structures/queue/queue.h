#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>

/* Default queue capacity. Can be overridden with -DMAX=<size> */
#ifndef MAX
#define MAX 5
#endif

/* Global queue variables */

extern int queue[];
extern int front;
extern int rear;

/* Function declarations */

int is_empty(void);

int is_full(void);

void enqueue(int value);

int dequeue(void);

int peek(void);

void display(void);

#endif // QUEUE_H
