// To take marks of three students in three subjects in an array
#include<stdio.h>

int main(){
    int i,j;
    int marks[3][3];

    for(i=0;i<=2;i++){
        printf("Enter the marks of student %d\n", i+1);
        for(j=0;j<=2;j++){
            printf("Enter the Marks obtained in subject %d: ", j+1);
            scanf("%d",&marks[i][j]);
        }
    }



    for(i=0;i<=2;i++){
        printf("The marks of student %d\n", i+1);
        for(j=0;j<=2;j++){
            printf("Marks obtained in subject %d is: %d\n",j+1,marks[i][j]);
        }
    }

    printf("Marks in subject - %d\n", marks[0][0]);
    printf("Marks in subject - %d\n", marks[0][1]);
    printf("Marks in subject - %d\n", marks[0][2]);
    printf("Marks in subject - %d\n", marks[1][0]);
    printf("Marks in subject - %d\n", marks[1][1]);
    printf("Marks in subject - %d\n", marks[1][2]);
    printf("Marks in subject - %d\n", marks[2][0]);
    printf("Marks in subject - %d\n", marks[2][1]);
    printf("Marks in subject - %d\n", marks[2][2]);

    return 0;
}