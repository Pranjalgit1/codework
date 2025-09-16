#include "stack.h"

int main() {
    Stack stack;
    int choice, value;
    int running = 1; // Loop control variable
    
    // Initialize the stack
    initStack(&stack);
    
    printf("Stack Implementation using Array\n");
    printf("===============================\n");
    
    while (running) {
        printf("\n--- Stack Operations Menu ---\n");
        printf("1. Push\n");
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
                if (push(&stack, value)) {
                    printf("Successfully pushed %d onto the stack\n", value);
                }
                break;
                
            case 2:
                value = pop(&stack);
                if (value != -1) {
                    printf("Popped value: %d\n", value);
                }
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
                    printf("Stack is not empty (has %d elements)\n", getSize(&stack));
                }
                break;
                
            case 7:
                if (isFull(&stack)) {
                    printf("Stack is full (maximum capacity: %d)\n", MAX_SIZE);
                } else {
                    printf("Stack is not full (current size: %d/%d)\n", 
                           getSize(&stack), MAX_SIZE);
                }
                break;
                
            case 8:
                printf("Thank you for using the Stack program!\n");
                printf("Final stack state:\n");
                display(&stack);
                running = 0; // Set running to 0 to exit the loop
                break;
                
            default:
                printf("Invalid choice! Please enter a number between 1-8.\n");
        }
        
        // Add a small separator for better readability
        if (running && choice >= 1 && choice <= 7) {
            printf("Press Enter to continue...");
            getchar(); // Clear the input buffer
            getchar(); // Wait for Enter key
        }
    }
    
    return 0;
}