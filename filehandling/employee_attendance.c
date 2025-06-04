#include <stdio.h>
#include <string.h>

struct Employee {
    char name[50];
    int id;
    int days_present;
    int days_absent;
};

int main() {
    struct Employee employees[100];
    int n, i, min_absent = 999;
    
    // Get number of employees
    printf("Enter number of employees: ");
    scanf("%d", &n);
    
    // Clear input buffer
    getchar();
    
    // Input employee details
    for(i = 0; i < n; i++) {
        printf("\nEmployee %d:\n", i+1);
        
        printf("Enter name: ");
        gets(employees[i].name);
        
        printf("Enter ID: ");
        scanf("%d", &employees[i].id);
        
        printf("Enter days present: ");
        scanf("%d", &employees[i].days_present);
        
        printf("Enter days absent: ");
        scanf("%d", &employees[i].days_absent);
        
        // Update minimum absent days
        if(employees[i].days_absent < min_absent) {
            min_absent = employees[i].days_absent;
        }
        
        // Clear input buffer
        getchar();
    }
    
    // Display employees with minimum absences
    printf("\nEmployees with minimum absences (%d days):\n", min_absent);
    printf("----------------------------------------\n");
    printf("Name\t\tID\tPresent\tAbsent\n");
    printf("----------------------------------------\n");
    
    for(i = 0; i < n; i++) {
        if(employees[i].days_absent == min_absent) {
            printf("%s\t%d\t%d\t%d\n", 
                   employees[i].name, 
                   employees[i].id, 
                   employees[i].days_present, 
                   employees[i].days_absent);
        }
    }
    
    return 0;
} 