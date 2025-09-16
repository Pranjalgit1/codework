#include<stdio.h>


#define MAX_SIZE 100

// Structure to represent a stack
typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

// Function to initialize stack
void initStack(Stack* stack) {
    stack->top = -1;
}

// Function to check if stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Function to check if stack is full
int isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// Function to push an element onto the stack
int push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow! Cannot push %d\n", value);
        return 0; // Failure
    }
    stack->data[++stack->top] = value;
    printf("Pushed %d onto the stack\n", value);
    return 1; // Success
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow! Cannot pop from empty stack\n");
        return -1; // Error value
    }
    int value = stack->data[stack->top--];
    printf("Popped %d from the stack\n", value);
    return value;
}

// Function to peek at the top element without removing it
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty! Cannot peek\n");
        return -1; // Error value
    }
    return stack->data[stack->top];
}

// Function to display the stack
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

// Function to get the current size of the stack
int getSize(Stack* stack) {
    return stack->top + 1;
}

int main() {
    Stack stack;
    int choice, value;
    int running = 1; // Loop control variable
    
    // Initialize the stack
    initStack(&stack);
    
    printf("Stack Implementation using Array\n");
    printf("===============================\n");
    
    while (running) {
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Get Size\n");
        printf("6. Check if Empty\n");
        printf("7. Check if Full\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
                
            case 2:
                pop(&stack);
                break;
                
            case 3:
                value = peek(&stack);
                if (value != -1) {
                    printf("Top element: %d\n", value);
                }
                break;
                
            case 4:
                display(&stack);
                break;
                
            case 5:
                printf("Current stack size: %d\n", getSize(&stack));
                break;
                
            case 6:
                if (isEmpty(&stack)) {
                    printf("Stack is empty\n");
                } else {
                    printf("Stack is not empty\n");
                }
                break;
                
            case 7:
                if (isFull(&stack)) {
                    printf("Stack is full\n");
                } else {
                    printf("Stack is not full\n");
                }
                break;
                
            case 8:
                printf("Exiting...\n");
                running = 0; // Set running to 0 to exit the loop
                break;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}