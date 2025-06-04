#include <stdio.h>
#include <string.h>

// Define the student structure
struct Student {
    char name[50];
    int roll_no;
    float percentage;
};

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);
    getchar();  // Clear input buffer
    
    struct Student students[n];
    int max_index = 0;  // Index of student with max percentage
    
    // Input details for n students
    for(int i = 0; i < n; i++) {
        printf("\nEnter details for Student %d:\n", i+1);
        
        printf("Enter Name: ");
        gets(students[i].name);
        
        printf("Enter Roll Number: ");
        scanf("%d", &students[i].roll_no);
        getchar();  // Clear input buffer
        
        printf("Enter Percentage: ");
        scanf("%f", &students[i].percentage);
        getchar();  // Clear input buffer
    }
    
    // Find student with highest percentage
    for(int i = 1; i < n; i++) {
        if(students[i].percentage > students[max_index].percentage) {
            max_index = i;
        }
    }
    
    // Display all student details
    printf("\nStudent Details:\n");
    printf("----------------\n");
    for(int i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i+1);
        printf("Name: %s\n", students[i].name);
        printf("Roll Number: %d\n", students[i].roll_no);
        printf("Percentage: %.2f%%\n", students[i].percentage);
    }
    
    // Display student with highest percentage
    printf("\nStudent with highest percentage:\n");
    printf("Roll Number: %d\n", students[max_index].roll_no);
    printf("Name: %s\n", students[max_index].name);
    printf("Percentage: %.2f%%\n", students[max_index].percentage);
    
    // Display names of students with more than 75%
    printf("\nStudents with more than 75%%:\n");
    printf("------------------------\n");
    for(int i = 0; i < n; i++) {
        if(students[i].percentage > 75.0) {
            printf("Name: %s (%.2f)\n", students[i].name, students[i].percentage);
        }
    }
    
    return 0;
} 