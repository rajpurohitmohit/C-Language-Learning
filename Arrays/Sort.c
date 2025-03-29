// For sorting by using Bubble Sort
#include <stdio.h>

int main() {
    int a[10], i, j, temp, n;

    printf("Enter the number of elements to sort (up to 10):\n");
    scanf("%d", &n);

    if (n > 10) {
        printf("Please enter a maximum of 10 elements.\n");
        return 1;
    }

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }


    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    printf("Sorted elements:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}