#include <stdio.h>

// Define the employee structure with date fields directly
struct Employee {
    int id;
    char name[50];
    int day;    // Joining day
    int month;  // Joining month
    int year;   // Joining year
};

int main() {
    int n;
    
    // Input number of employees
    printf("Enter number of employees: ");
    scanf("%d", &n);
    getchar();
    // Create array of employees
    struct Employee employees[n];
    
    // Input details for each employee
    for(int i = 0; i < n; i++) {
        printf("\nEnter details for Employee %d:\n", i+1);
        printf("Enter ID: ");
        scanf("%d", &employees[i].id);
        getchar();
        
        printf("Enter Name: ");
        fgets(employees[i].name, sizeof(employees[i].name), stdin);

        printf("Enter Joining Date (DD MM YYYY): ");
        scanf("%d %d %d", &employees[i].day, 
                         &employees[i].month, 
                         &employees[i].year);
    }
    
    // Display all employee details
    printf("\nEmployee Details:\n");
    printf("----------------\n");
    for(int i = 0; i < n; i++) {
        printf("\nEmployee %d:\n", i+1);
        printf("ID: %d\n", employees[i].id);
        printf("Name: %s\n", employees[i].name);
        printf("Joining Date: %02d/%02d/%d\n", 
               employees[i].day,
               employees[i].month,
               employees[i].year);
    }
    
    return 0;
} 