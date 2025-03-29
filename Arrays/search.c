// //  For first creating an array then searching an element in an Array
// #include <stdio.h>

// int main() {
//     int a[10], i, temp, n, search, found = 0;

//     printf("Enter the number of elements to sort:");
//     scanf("%d", &n);

//     if (n > 10) {
//         printf("Enter a maximum of 10 elements.");
//         return 1;
//     }

//     printf("Enter the elements:");
//     for (i = 0; i < n; i++) {
//         scanf("%d", &a[i]);
//     }

//     printf("Enter the element to search for:");
//     scanf("%d", &search);

//     for (i = 0; i < n; i++) {
//         if (a[i] == search) {
//             found = 1;
//             break;
//         }
//     }

//     if (found) {
//         printf("Element %d found at position %d.", search, i + 1);
//     } else {
//         printf("Element %d not found in the array.", search);
//     }

//     return 0;
// }


#include <stdio.h>

int main() {
    int arr[100], n, i, search, found = 0;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &search);

    for (i = 0; i < n; i++) {
        if (arr[i] == search) {
            found = 1;
            printf("Element %d found at position %d\n", search, i + 1);
            break;
        }
    }

    if (!found) {
        printf("Element %d not found in the array\n", search);
    }

    return 0;
}