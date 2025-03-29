// To take input of marks of a student in three subjects and print them
#include<stdio.h>

int main(){
    int marks[3];
    printf("Enter marks in physics: ");
    scanf("%d", &marks[2]);

    printf("Enter marks in chemistry: ");
    scanf("%d", &marks[1]);

    printf("Enter marks in biology: ");
    scanf("%d", &marks[0]);

    printf("\nMarks in Physics: %d\n Marks in Chemistry: %d\n Marks in Biology: %d\n", marks[2], marks[1], marks[0]);
    return 0;
}
// Above with Loop
// #include<stdio.h>

// int main(){
//     int i;
//     int marks[10];
//     for(i= 0; i<3; i++){
//         printf("Enter the marks in subject ");
//         scanf("%d", &marks[i]);
//     }
//     printf("%d\n",marks[0]);
//     printf("%d\n",marks[1]);
//     printf("%d\n",marks[2]);
//     return 0;
// }