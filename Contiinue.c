// #include <stdio.h>

// int main() {
//     int a[10], i, j, temp, n;

//     printf("Enter the number of elements to sort (up to 10):\n");
//     scanf("%d", &n);

//     if (n > 10) {
//         printf("Please enter a maximum of 10 elements.\n");
//         return 1;
//     }

//     printf("Enter the elements:\n");
//     for (i = 0; i < n; i++) {
//         scanf("%d", &a[i]);
//     }


//     for (i = 0; i < n - 1; i++) {
//         for (j = i + 1; j < n; j++) {
//             if (a[i] > a[j]) {
//                 temp = a[i];
//                 a[i] = a[j];
//                 a[j] = temp;
//             }
//         }
//     }

//     printf("Sorted elements:\n");
//     for (i = 0; i < n; i++) {
//         printf("%d ", a[i]);
//     }
//     printf("\n");

//     return 0;
// }


// #include <stdio.h>

// int main() {
//     int a[c], i, temp, n, search;

//     printf("Enter the number of elements to sort:\n");
//     scanf("%d", &n);

//     if (n > 10) {
//         printf("enter a maximum of 10 elements.\n");
//         return 1;
//     }

//     printf("Enter the elements:\n");
//     for (i = 0; i < n; i++) {
//         scanf("%d", &a[i]);
//     }

//     for (i = 0; i < n - 1; i++) {
//         if (a[i] > a[i + 1]) {
//             temp = a[i];
//             a[i] = a[i + 1];
//             a[i + 1] = temp;
//         }
//     }

//     printf("Array after one pass:\n");
//     for (i = 0; i < n; i++) {
//         printf("%d ", a[i]);
//     }

// for(c=0;c=n;c++){
//     if(array[c] == search){
//         printf("%d is present in lower")


//     }
    
// }
//     return 0;
// }




// #include<stdio.h>


// void fact(int n);
// int main(){
//     if(f<0)
//     return -1;
//     if(n<1)
//     return 1;
//     else;
//     return 0;
// }

// void fact(){
//     int fact, f;
//     printf("Enter the no.");
//     scanf("%d",&f)

    
// }

// #include <stdio.h>

// int fact(int n);

// int main() {
//     int number;
    
//     printf("Enter a number to find its factorial: ");
//     scanf("%d", &number);
    
//     if (number < 0) {
//         printf("Factorial of a negative number doesn't exist.\n");
//     } else {
//         printf("The factorial of %d is %d.\n", number, fact(number));
//     }
    
//     return 0;
// }

// int fact(int n) {
//     int fact = 1;
//     for (int i = 1; i <= n; i++) {
//         fact *= i;
//     }
//     return fact;
// }



// #include <stdio.h>

// // Function to swap two numbers
// void swap(int *a, int *b) {
//     int temp;
//     temp = *a; 
//     *a = *b;   
//     *b = temp; 
// }

// int main() {
//     int num1, num2;

//     printf("Enter two numbers:\n");
//     scanf("%d %d", &num1, &num2);

//     printf("Before swapping: num1 = %d, num2 = %d\n", num1, num2);

//     swap(&num1, &num2);

//     printf("After swapping: num1 = %d, num2 = %d\n", num1, num2);

//     return 0;
// }

// #include<stdio.h>

// int main(){
//     int a[5],i;

//     for (i = 0; i <5 ; i++){
//         scanf("%d", &a[i]);
//     }
//     printf("Correct order: ");
//     for(i =0; i<5; i++){
//         printf("%d, ",a[i]);
//     }
//     printf("\nReverse order:");
//     for(i= 4; i>=0; i--){
//         printf("%d, ", a[i]);
//     }
//     return 0;
// }



#include<stdio.h>

int main() {
    int a[5], i, sum = 0, odd = 0;

    printf("Enter 5 numbers:\n");
    for (i = 0; i < 5; i++) {
        scanf("%d", &a[i]);
    }

    printf("Inputted numbers: ");
    for (i = 0; i < 5; i++) {
        printf("%d ", a[i]);
    }

    
    for (i = 0; i < 5; i++) {
        if (a[i] % 2 == 0) {
            sum += a[i]; 
        } else {
            odd += a[i]; 
        }
    }

    // Print results
    printf("\nThe Sum of Even numbers is: %d", sum);
    printf("\nThe Sum of Odd numbers is: %d", odd);

    return 0;
}


// Write a program to calculate the factorial of third array element
// write a program to print the table of 5th arry element if it is even otherwise print the sum of series till number
