#include <stdio.h>
#include <stdlib.h>

// 1D Dynamic Memory Allocation
// This function demonstrates how to dynamically allocate memory for a 1D array at runtime
void dma_1d_array() {
    printf("=== 1D Array DMA ===\n");
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    
    // Allocate contiguous memory for n integers using malloc
    // Cast to (int *) as malloc returns void pointer
    int *arr = (int *)malloc(n * sizeof(int));
    
    // Check if memory allocation was successful
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    // Input array elements from user
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Display all array elements
    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Deallocate memory to prevent memory leak
    free(arr);
    printf("Memory freed!\n\n");
}

// 2D Dynamic Memory Allocation
void dma_2d_array() {
    printf("=== 2D Array DMA ===\n");
    
    int rows, cols;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);
    
    // Allocate memory for rows
    int **arr = (int **)malloc(rows * sizeof(int *));
    
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    // Allocate memory for columns
    for (int i = 0; i < rows; i++) {
        arr[i] = (int *)malloc(cols * sizeof(int));
        if (arr[i] == NULL) {
            printf("Memory allocation failed!\n");
            return;
        }
    }
    //Get elements from user
    printf("Enter %d x %d elements:\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    //display elements
    printf("2D Array:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    
    // Free memory
    for (int i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);
    printf("Memory freed!\n\n");
}

int main() {
    dma_1d_array();
    dma_2d_array();
    
    return 0;
}
