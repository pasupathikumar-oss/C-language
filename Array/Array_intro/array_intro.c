//An array is a linear data structure that stores a fixed-size sequence of elements of 
//the same data type in contiguous memory locations.
// using index like using pointer to access the elements of an array which is,
// The expression: arr[i] is exactly equivalent to: *(arr + i) 

#include <stdio.h>

//array passing to function 
void f1(int arr[3]) {
    printf("Size in f1: %lu bytes\n", sizeof(arr));
}

void f2(int arr[]) {
    printf("Size in f2: %lu bytes\n", sizeof(arr));
}

void f3(int *arr) {
    printf("Size in f3: %lu bytes\n", sizeof(arr));
}


int main() {
    // declaring an array
    int arr[5] = {1, 2, 3, 4, 5};

    // printing the array elements
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    // array size
    int size = sizeof(arr)/sizeof(arr[0]); // size of the bytes used by array / size of the bytes used by one element of the array. 
    printf("%d", size);

    //passing array to function
    f1(arr);
    f2(arr);
    f3(arr);

    return 0;
}