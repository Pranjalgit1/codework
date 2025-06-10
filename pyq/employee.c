#include <stdio.h>
#include <string.h>

struct Employee {
    char employee_name[50];
    int employee_id;
    float employee_salary;
    int employee_year;
};

// Function to sort employees by experience
void sortByExperience(struct Employee emp[], int n) {
    struct Employee temp;
    
    // Bubble sort in descending order
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(emp[j].employee_year < emp[j+1].employee_year) {
                // Swap employees
                temp = emp[j];
                emp[j] = emp[j+1];
                emp[j+1] = temp;
            }
        }
    }
}

// Function to print all employee details
void printEmployees(struct Employee emp[], int n) {
    printf("\nEmployee Details (Sorted by Experience):\n");
    printf("Name\t\tID\tSalary\t\tExperience\n");
    printf("------------------------------------------------\n");
    
    for(int i = 0; i < n; i++) {
        printf("%s\t\t%d\t%.2f\t\t%d years\n", 
               emp[i].employee_name,
               emp[i].employee_id,
               emp[i].employee_salary,
               emp[i].employee_year);
    }
}

int main() {
    int n;
    printf("Enter number of employees: ");
    scanf("%d", &n);
    
    struct Employee emp[n];
    
    // Input employee details
    for(int i = 0; i < n; i++) {
        printf("\nEnter details for employee %d:\n", i+1);
        printf("Name: ");
        scanf("%s", emp[i].employee_name);
        printf("ID: ");
        scanf("%d", &emp[i].employee_id);
        printf("Salary: ");
        scanf("%f", &emp[i].employee_salary);
        printf("Years of Experience: ");
        scanf("%d", &emp[i].employee_year);
    }
    
    // Print initial details
    printf("\nInitial Employee Details:");
    printEmployees(emp, n);
    
    // Sort by experience
    sortByExperience(emp, n);  
    
    // Print sorted details
    printf("\nAfter sorting by experience:");
    printEmployees(emp, n);
    
    return 0;
} 