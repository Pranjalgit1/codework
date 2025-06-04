#include <stdio.h>
#include <string.h>

struct Employee {
    char name[50];
    int id;
    float basic_salary;
};

int main() {
    struct Employee emp[100];  // Fixed size array for 100 employees
    int n, i;
    float ta, da, total;
    
    // Get number of employees
    printf("Enter number of employees (max 100): ");
    scanf("%d", &n);
    getchar();
    
    // Input employee data
    for (i = 0; i < n; i++) {
        printf("\nEnter details for Employee %d:\n", i + 1);
        
        printf("Name: ");
        gets(emp[i].name);
        
        printf("ID: ");
        scanf("%d", &emp[i].id);
        
        printf("Basic Salary: ");
        scanf("%f", &emp[i].basic_salary);
        getchar();
    }
    
    // Display employee data
    printf("\nEmployee Details:\n");
    printf("--------------------------------------------------------\n");
    printf("Name\t\tID\tBasic\tTA\tDA\tTotal\n");
    printf("--------------------------------------------------------\n");
    
    for (i = 0; i < n; i++) {
        // Calculate TA and DA
        ta = emp[i].basic_salary * 0.22;  // 22% of basic salary
        da = emp[i].basic_salary * 0.15;  // 15% of basic salary
        total = emp[i].basic_salary + ta + da;
        
        printf("%-15s\t%d\t%.2f\t%.2f\t%.2f\t%.2f\n",
               emp[i].name,
               emp[i].id,
               emp[i].basic_salary,
               ta,
               da,
               total);
    }
    printf("--------------------------------------------------------\n");
    
    return 0;
} 