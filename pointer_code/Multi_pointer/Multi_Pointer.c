/*  | Pointer type | To get value |
    | ------------ | ------------ |
    | `int *`      | `*p`         |
    | `int **`     | `**p`        |
    | `int ***`    | `***p`       |
    | `int ****`   | `****p`      |
    | `int *****`  | `*****p`     |
*/

#include <stdio.h>

int main() {
    int var = 10;
    // Pointer to int
    int *ptr1 = &var;
    // Pointer to pointer (double pointer)
    int **ptr2 = &ptr1;  
    // Accessing values using all three
    printf("var: %d\n", var);          
    printf("*ptr1: %d\n", *ptr1);
    printf("**ptr2: %d\n", **ptr2);
    return 0;
}