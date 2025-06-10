#include <stdio.h>
#include <string.h>

struct Customer {
    char customer_name[50];
    int account_number;
    float account_balance;
};

// Function to print customers with balance < 5000
void printLowBalance(struct Customer customers[], int n) {
    printf("\nCustomers with balance less than 5000:\n");
    int found = 0;
    
    for(int i = 0; i < n; i++) {
        if(customers[i].account_balance < 5000) {
            printf("Name: %s\n", customers[i].customer_name);
            found = 1;
        }
    }
    
    if(!found) {
        printf("No customers found with balance less than 5000\n");
    }
}

// Function to add 1000 to balance > 10000
void addBonus(struct Customer customers[], int n) {
    printf("\nUpdating balances for customers with balance > 10000:\n");
    int found = 0;
    
    for(int i = 0; i < n; i++) {
        if(customers[i].account_balance > 10000) {
            customers[i].account_balance += 1000;
            found = 1;
        }
    }
    
    if(!found) {
        printf("No customers found with balance more than 10000\n");
    }
}

// Function to print all customer details
void printAllCustomers(struct Customer customers[], int n) {
    printf("\nAll Customer Details:\n");
    printf("Name\t\tAccount Number\tBalance\n");
    printf("----------------------------------------\n");
    
    for(int i = 0; i < n; i++) {
        printf("%s\t\t%d\t\t%.2f\n", 
               customers[i].customer_name, 
               customers[i].account_number, 
               customers[i].account_balance);
    }
}

int main() {
    int n;
    printf("Enter number of customers: ");
    scanf("%d", &n);
    
    struct Customer customers[n];
    
    // Input customer details
    for(int i = 0; i < n; i++) {
        printf("\nEnter details for customer %d:\n", i+1);
        printf("Name: ");
        scanf("%s", customers[i].customer_name);
        printf("Account Number: ");
        scanf("%d", &customers[i].account_number);
        printf("Balance: ");
        scanf("%f", &customers[i].account_balance);
    }
    
    // Print initial details
    printf("\nInitial Customer Details:");
    printAllCustomers(customers, n);
    
    // Print customers with low balance
    printLowBalance(customers, n);
    
    // Add bonus and print updated details
    addBonus(customers, n);
    printf("\nUpdated Customer Details:");
    printAllCustomers(customers, n);
    
    return 0;
} 