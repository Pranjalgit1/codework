#include <stdio.h>
#include <string.h>

struct Person {
    char person_name[50];
    int person_age;
    char person_gender;
    int person_id;
    char person_working_status[20];
};

int main() {
    struct Person persons[100];
    int i, n;
    
    // Input number of persons
    printf("Enter number of persons (max 100): ");
    scanf("%d", &n);
    
    // Input person details
    for(i = 0; i < n; i++) {
        printf("\nEnter details for Person %d:\n", i+1);
        printf("Name: ");
        gets(persons[i].person_name);
        printf("Age: ");
        getchar();
        scanf("%d", &persons[i].person_age);
        printf("Gender (M/F): ");
        scanf(" %c", &persons[i].person_gender);
        getchar();
        printf("ID: ");
        scanf("%d", &persons[i].person_id);
        getchar();  
        printf("Working Status (working/non-working): ");
        gets(persons[i].person_working_status);
    }
    
    // Display female persons
    printf("\n\nFemale Persons:\n");
    printf("Name\t\tAge\tGender\tID\tStatus\n");
    printf("------------------------------------------------\n");
    for(i = 0; i < n; i++) {
        if(persons[i].person_gender == 'F' || persons[i].person_gender == 'f') {
            printf("%s\t%d\t%c\t%d\t%s\n", 
                   persons[i].person_name,
                   persons[i].person_age,
                   persons[i].person_gender,
                   persons[i].person_id,
                   persons[i].person_working_status);
        }
    }
    
    // Display non-working persons
    printf("\n\nNon-working Persons:\n");
    printf("Name\t\tAge\tGender\tID\tStatus\n");
    printf("------------------------------------------------\n");
    for(i = 0; i < n; i++) {
        if(strcmp(persons[i].person_working_status, "non-working") == 0) {
            printf("%s\t%d\t%c\t%d\t%s\n", 
                   persons[i].person_name,
                   persons[i].person_age,
                   persons[i].person_gender,
                   persons[i].person_id,
                   persons[i].person_working_status);
        }
    }
    
    // Display persons with age between 30-40
    printf("\n\nPersons with age between 30-40:\n");
    printf("Name\t\tAge\tGender\tID\tStatus\n");
    printf("------------------------------------------------\n");
    for(i = 0; i < n; i++) {
        if(persons[i].person_age >= 30 && persons[i].person_age <= 40) {
            printf("%s\t%d\t%c\t%d\t%s\n", 
                   persons[i].person_name,
                   persons[i].person_age,
                   persons[i].person_gender,
                   persons[i].person_id,
                   persons[i].person_working_status);
        }
    }
    
    return 0;
} 