// Student Management System
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50
#define FILE_NAME "students.dat"

// Structure to hold student information
typedef struct {
    int id;
    char name[NAME_LENGTH];
    float grade;
} Student;

// Function prototypes
void addStudent();
void viewStudents();
void deleteStudent();
void saveToFile(Student students[], int count);
int loadFromFile(Student students[]);

int main() {
    int choice;
    while (1) {
        printf("Student Management System\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Delete Student\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                viewStudents();
                break;
            case 3:
                deleteStudent();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}

// Function to add a student
void addStudent() {
    FILE *file = fopen(FILE_NAME, "ab");
    if (file == NULL) {
        perror("Unable to open file");
        return;
    }

    Student student;
    printf("Enter Student ID: ");
    scanf("%d", &student.id);
    printf("Enter Student Name: ");
    scanf(" %[^\n]", student.name);
    printf("Enter Student Grade: ");
    scanf("%f", &student.grade);
    
    fwrite(&student, sizeof(Student), 1, file);
    fclose(file);
    printf("Student added successfully!\n");
}

// Function to view all students
void viewStudents() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        perror("Unable to open file");
        return;
    }

    Student student;
    printf("\nStudent Records:\n");
    printf("ID\tName\t\tGrade\n");
    printf("---------------------------\n");
    while (fread(&student, sizeof(Student), 1, file)) {
        printf("%d\t%s\t%.2f\n", student.id, student.name, student.grade);
    }
    fclose(file);
}

// Function to delete a student by ID
void deleteStudent() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        perror("Unable to open file");
        return;
    }

    Student students[MAX_STUDENTS];
    int count = 0;
    while (fread(&students[count], sizeof(Student), 1, file)) {
        count++;
    }
    fclose(file);

    int id;
    printf("Enter Student ID to delete: ");
    scanf("%d", &id);

    file = fopen(FILE_NAME, "wb");
    if (file == NULL) {
        perror("Unable to open file");
        return;
    }

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (students[i].id != id) {
            fwrite(&students[i], sizeof(Student), 1, file);
        } else {
            found = 1;
        }
    }
    fclose(file);

    if (found) {
        printf("Student with ID %d deleted successfully!\n", id);
    } else {
        printf("Student with ID %d not found!\n", id);
    }
}