#include <stdio.h>
#include <string.h>

// Define the date structure
struct Date {
    int day;
    int month;
    int year;
};

// Define the employee structure
struct Employee {
    char name[50];
    struct Date doj;  // Date of joining as a structure
    float salary;
};

int main() {
    int n;
    float total_salary = 0;
    
    printf("Enter number of employees: ");
    scanf("%d", &n);
    getchar();  // Clear buffer after scanf("%d")
    
    struct Employee employees[n];
    
    // Input details for n employees
    for(int i = 0; i < n; i++) {
        printf("\nEnter details for Employee %d:\n", i+1);
        
        printf("Enter Name: ");
        fgets(employees[i].name, sizeof(employees[i].name), stdin);
        employees[i].name[strcspn(employees[i].name, "\n")] = 0;  // Remove newline
        
        // Input date in single scanf
        printf("Enter Date of Joining (DD MM YYYY): ");
        scanf("%d %d %d", &employees[i].doj.day, 
                         &employees[i].doj.month, 
                         &employees[i].doj.year);
        getchar();  // Clear buffer after scanf
        
        printf("Enter Monthly Salary: ");
        scanf("%f", &employees[i].salary);
        getchar();  // Clear buffer after scanf
        
        // Add to total salary
        total_salary += employees[i].salary;
    }
    
    // Display all employee details
    printf("\nEmployee Details:\n");
    printf("----------------\n");
    for(int i = 0; i < n; i++) {
        printf("\nEmployee %d:\n", i+1);
        printf("Name: %s\n", employees[i].name);
        printf("Date of Joining: %02d/%02d/%d\n", 
               employees[i].doj.day, 
               employees[i].doj.month, 
               employees[i].doj.year);
        printf("Monthly Salary: Rs.%.2f\n", employees[i].salary);
    }
    
    // Display total salary
    printf("\nTotal Monthly Salary Distributed: Rs.%.2f\n", total_salary);
    
    return 0;
} 