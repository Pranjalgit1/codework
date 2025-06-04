#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int id;
    int age;
    float marks;
};

int main() {
    struct Student students[100];
    int n, i;
    
    // Get number of students
    printf("Enter number of students: ");
    scanf("%d", &n);
    getchar();  // Clear buffer
    
    // Input student details
    for(i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i+1);
        
        printf("Enter name: ");
        gets(students[i].name);
        
        printf("Enter ID: ");
        scanf("%d", &students[i].id);
        getchar();  // Clear buffer
        
        printf("Enter age: ");
        scanf("%d", &students[i].age);
        getchar();  // Clear buffer
        
        printf("Enter marks: ");
        scanf("%f", &students[i].marks);
        getchar();  // Clear buffer
    }
    
    // Display eligible voters
    printf("\nStudents eligible to vote (Age >= 18):\n");
    printf("----------------------------------------\n");
    printf("Name\t\tID\tAge\tMarks\n");
    printf("----------------------------------------\n");
    
    for(i = 0; i < n; i++) {
        if(students[i].age >= 18) {
            printf("%-15s\t%d\t%d\t%.2f\n", 
                   students[i].name, 
                   students[i].id, 
                   students[i].age, 
                   students[i].marks);
        }
    }
    
    return 0;
} 