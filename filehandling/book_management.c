#include <stdio.h>
#include <string.h>

struct Book {
    char isbn[20];
    char name[100];
    float cost;
};

int main() {
    struct Book books[10];
    int i;
    
    // Input book details
    printf("Enter details for 10 books:\n");
    for(i = 0; i < 10; i++) {
        printf("\nBook %d:\n", i+1);
        
        printf("Enter ISBN: ");
        gets(books[i].isbn);
        
        printf("Enter name: ");
        gets(books[i].name);
        
        printf("Enter cost: ");
        scanf("%f", &books[i].cost);
        getchar();  // Clear buffer
    }
    
    // Display books costing more than 500
    printf("\nBooks costing more than 500:\n");
    printf("----------------------------------------\n");
    printf("ISBN\t\tName\t\t\tCost\n");
    printf("----------------------------------------\n");
    
    for(i = 0; i < 10; i++) {
        if(books[i].cost > 500) {
            printf("%-15s\t%-25s\t%.2f\n", 
                   books[i].isbn, 
                   books[i].name, 
                   books[i].cost);
        }
    }
    
    return 0;
} 