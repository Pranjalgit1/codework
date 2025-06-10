#include <stdio.h>
#include <string.h>

struct Employee {
    char employee_name[50];
    int employee_id;
    float employee_basic_salary;
    char employee_gender;
};

int main() {
    FILE *fp;
    struct Employee emp;
    float da, hra, gross_salary;
    int i;
    
    // Open file for writing
    fp = fopen("INPUT_DATA.txt", "w");
    
    if(fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    
    // Input and write employee details
    printf("Enter details of 10 employees:\n");
    for(i = 0; i < 10; i++) {
        printf("\nEmployee %d:\n", i+1);
        printf("Name: ");
        scanf(" %[^\n]s", emp.employee_name);
        printf("ID: ");
        scanf("%d", &emp.employee_id);
        printf("Basic Salary: ");
        scanf("%f", &emp.employee_basic_salary);
        printf("Gender (M/F): ");
        scanf(" %c", &emp.employee_gender);
        
        // Write to file
        fprintf(fp, "%s %d %.2f %c\n", 
                emp.employee_name, 
                emp.employee_id, 
                emp.employee_basic_salary, 
                emp.employee_gender);
    }
    
    // Close file
    fclose(fp);
    
    // Open file for reading
    fp = fopen("INPUT_DATA.txt", "r");
    
    if(fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    
    // Read and display employee details with gross salary
    printf("\n\nEmployee Details with Gross Salary:\n");
    printf("Name\t\tID\tBasic Salary\tDA\t\tHRA\t\tGross Salary\n");
    printf("----------------------------------------------------------------\n");
    
    while(fscanf(fp, "%s %d %f %c", 
                 emp.employee_name, 
                 &emp.employee_id, 
                 &emp.employee_basic_salary, 
                 &emp.employee_gender) != EOF) {
        
        // Calculate DA and HRA
        da = 0.30 * emp.employee_basic_salary;
        hra = 0.20 * emp.employee_basic_salary;
        
        // Calculate gross salary
        gross_salary = emp.employee_basic_salary + da + hra;
        
        // Display details
        printf("%s\t%d\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n",
               emp.employee_name,
               emp.employee_id,
               emp.employee_basic_salary,
               da,
               hra,
               gross_salary);
    }
    
    // Close file
    fclose(fp);
    
    return 0;
} 