#ifndef STACK_H
#define STACK_H

#include <stdio.h>

#define MAX 5

/* Global stack variables */

extern int stack[MAX];
extern int top;

/* Function declarations */

int is_empty(void);

int is_full(void);

void push(int value);

void pop(void);

int peek(void);

void display(void);

#endif // STACK_H
