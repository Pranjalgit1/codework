#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Stack structure using array implementation
typedef struct {
    int data[MAX_SIZE];    // Array to store stack elements
    int top;               // Index of top element (-1 when empty)
} Stack;

// Core stack operations
void initStack(Stack* stack);
int isEmpty(Stack* stack);
int isFull(Stack* stack);
int push(Stack* stack, int value);
int pop(Stack* stack);
int peek(Stack* stack);
void display(Stack* stack);
int getSize(Stack* stack);

// Alternative: Dynamic stack structure (commented out for now)
/*
typedef struct {
    int* data;
    int top;
    int capacity;
} DynamicStack;

DynamicStack* createStack(int capacity);
void freeStack(DynamicStack* stack);
*/

#endif 