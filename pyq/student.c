#include <stdio.h>
#include <string.h>

struct Student {
    char student_name[50];
    int student_roll;
    char student_section;
    int marks[3];
    float average;
};

int main() {
    struct Student students[5];
    FILE *fp;
    float avg;
    
    // Input student details
    printf("Enter details of 5 students:\n");
    for(int i = 0; i < 5; i++) {
        printf("\nStudent %d:\n", i+1);
        printf("Name: ");
        scanf("%s", students[i].student_name);
        printf("Roll Number: ");
        scanf("%d", &students[i].student_roll);
        printf("Section: ");
        scanf(" %c", &students[i].student_section);
        printf("Marks in 3 subjects: ");
        scanf("%d %d %d", 
              &students[i].marks[0],
              &students[i].marks[1],
              &students[i].marks[2]);
    }
    
    // Write to file
    fp = fopen("DATA.txt", "w");    
    if(fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    
    // Write each student's details
    for(int i = 0; i < 5; i++) {
        fprintf(fp, "%s %d %c %d %d %d\n", 
                students[i].student_name,
                students[i].student_roll,
                students[i].student_section,
                students[i].marks[0],
                students[i].marks[1],
                students[i].marks[2]);
    }
    fclose(fp);
    printf("Data written to file successfully!\n");
    
    // Read and display from file
    fp = fopen("DATA.txt", "r");
    if(fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    
    printf("\nStudent Details from File:\n");
    printf("Name\t\tRoll\tSection\tMarks\t\tAverage\n");
    printf("--------------------------------------------------------\n");
    
    // Read and display each student's details
    while(fscanf(fp, "%s %d %c %d %d %d", 
                 students[0].student_name, 
                 &students[0].student_roll, 
                 &students[0].student_section,
                 &students[0].marks[0], 
                 &students[0].marks[1], 
                 &students[0].marks[2]) != EOF) {
        
        // Calculate average
        avg = (students[0].marks[0] + students[0].marks[1] + students[0].marks[2]) / 3.0;
        
        // Display student details
        printf("%s\t\t%d\t%c\t%d %d %d\t%.2f\n",
               students[0].student_name,
               students[0].student_roll,
               students[0].student_section,
               students[0].marks[0],
               students[0].marks[1],
               students[0].marks[2],
               avg);
    }
    
    fclose(fp);
    return 0;
} 