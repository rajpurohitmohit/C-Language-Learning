//  Syntax of a structure
#include <stdio.h>

#define SIZE 5

// Define a structure with arrays as members
struct StudentData {
    int rollNumbers[SIZE];
    char names[SIZE][50];
    float marks[SIZE];
};

int main() {
    struct StudentData students;

    // Input data for students
    for (int i = 0; i < SIZE; i++){
        printf("Enter data for student %d:\n", i + 1);
        printf("Roll Number: ");
        scanf("%d", &students.rollNumbers[i]);
        printf("Name: ");
        scanf(" %[^\n]", students.names[i]); // Use space to ignore leftover newline
        printf("Marks: ");
        scanf("%f", &students.marks[i]);
    }

    // Display data
    printf("\nStudent Data:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll Number: %d\n", students.rollNumbers[i]);
        printf("Name: %s\n", students.names[i]);
        printf("Marks: %.2f\n", students.marks[i]);
    }

    return 0;
}