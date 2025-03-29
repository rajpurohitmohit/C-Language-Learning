#include <stdio.h>

int main() {
    int userChoice;

    printf("Welcome to the Quiz MCQ Exam\n\n");

    printf("Q1: Enter the number of 'r's present in the word 'strawberry'\n");
    printf("1. One\n");
    printf("2. Two\n");
    printf("3. Three\n");
    printf("4. Four\n");

    printf("Enter Choice: ");
    scanf("%d", &userChoice);

    switch (userChoice) {
        case 1:
            printf("Incorrect. The correct answer is 3.\n");
            break;
        case 2:
            printf("Incorrect. The correct answer is 3.\n");
            break;
        case 3:
            printf("Correct! There are three 'r's in the word 'strawberry'.\n");
            break;
        case 4:
            printf("Incorrect. The correct answer is 3.\n");
            break;
        default:
            printf("Invalid choice. Please enter a number between 1 and 4.\n");
    }

    printf("\n");


    printf("Q2: What is the capital of India?\n");
    printf("1. Mumbai\n");
    printf("2. New Delhi\n");
    printf("3. Kolkata\n");
    printf("4. Chennai\n");

    printf("Enter Choice: ");
    scanf("%d", &userChoice);

    switch (userChoice) {
        case 1:
            printf("Incorrect. The correct answer is 2.\n");
            break;
        case 2:
            printf("Correct! The capital of India is New Delhi.\n");
            break;
        case 3:
            printf("Incorrect. The correct answer is 2.\n");
            break;
        case 4:
            printf("Incorrect. The correct answer is 2.\n");
            break;
        default:
            printf("Invalid choice. Please enter a number between 1 and 4.\n");
    }

    printf("\n");


    printf("Q3: How many vowels are there in the English alphabet?\n");
    printf("1. Five\n");
    printf("2. Six\n");
    printf("3. Seven\n");
    printf("4. Eight\n");

    printf("Enter Choice: ");
    scanf("%d", &userChoice);

    switch (userChoice) {
        case 1:
            printf("Correct! There are five vowels in the English alphabet.\n");
            break;
        case 2:
            printf("Incorrect. The correct answer is 1.\n");
            break;
        case 3:
            printf("Incorrect. The correct answer is 1.\n");
            break;
        case 4:
            printf("Incorrect. The correct answer is 1.\n");
            break;
        default:
            printf("Invalid choice. Please enter a number between 1 and 4.\n");
    }


    return 0;
}