#include <stdio.h>
#include <stdlib.h>

int main (){
    // declaring an array
    int arr[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
        printf("%d ", ( *(arr + i))); // using pointer to access the elements of an array
    }
   
    // also cover array with DMA
    int *dynamic_arr = (int *)malloc(5 * sizeof(int));
    if (dynamic_arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    for (int i = 0; i < 5; i++) {
        dynamic_arr[i] = i + 1;
    }
    for (int i = 0; i < 5; i++) {
        printf("%d ", dynamic_arr[i]);
    }
    free(dynamic_arr);

    return 0;
}