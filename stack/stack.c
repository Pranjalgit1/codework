#include "stack.h"

// Initialize the stack
void initStack(Stack* stack) {
    stack->top = -1;
}

// Check if stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Check if stack is full
int isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// Push an element onto the stack
int push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow! Cannot push %d\n", value);
        return 0; // Failure
    }
    stack->data[++stack->top] = value;
    return 1; // Success
}

// Pop an element from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow! Cannot pop from empty stack\n");
        return -1; // Error value
    }
    int value = stack->data[stack->top--];
    return value;
}

// Peek at the top element without removing it
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty! Cannot peek\n");
        return -1; // Error value
    }
    return stack->data[stack->top];
}

// Display the stack contents
void display(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements (top to bottom): ");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}

// Get the current size of the stack
int getSize(Stack* stack) {
    return stack->top + 1;
}
