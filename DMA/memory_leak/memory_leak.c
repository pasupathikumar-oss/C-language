#include <stdio.h>
#include <stdlib.h>

/*
 * MEMORY LEAK CONCEPT IN C:
 * 
 * A memory leak occurs when a program allocates memory dynamically (using malloc, calloc, realloc)
 * but fails to deallocate it using free(). This causes memory to remain occupied and inaccessible
 * even after it's no longer needed, leading to memory wastage and potential system issues.
 * 
 * COMMON CAUSES:
 * 1. Forgetting to call free() after using malloc()
 * 2. Losing reference to allocated memory before freeing it
 * 3. Exception or early return without freeing memory
 * 4. Circular references in data structures
 */

// EXAMPLE 1: Simple Memory Leak
void example_leak() {
    int *ptr = (int *)malloc(sizeof(int) * 10);
    *ptr = 5;
    printf("Value: %d\n", *ptr);
    // MEMORY LEAK: forgot to free(ptr);
}

// EXAMPLE 2: Memory Leak with Reassignment
void example_leak_reassign() {
    int *ptr = (int *)malloc(sizeof(int) * 10);
    ptr = (int *)malloc(sizeof(int) * 20);  // First block is leaked!
    free(ptr);
}

// EXAMPLE 3: Correct Memory Management
void example_no_leak() {
    int *ptr = (int *)malloc(sizeof(int) * 10);
    *ptr = 5;
    printf("Value: %d\n", *ptr);
    free(ptr);  // Properly deallocate
    ptr = NULL; // Good practice: set to NULL after freeing
}

// EXAMPLE 4: Memory Leak in Early Return
int example_early_return(int n) {
    char *buffer = (char *)malloc(100);
    if (n < 0) {
        return -1;  // MEMORY LEAK: buffer is not freed
    }
    printf("Buffer allocated\n");
    free(buffer);
    return 0;
}

// EXAMPLE 5: Correct Early Return
int example_correct_early_return(int n) {
    char *buffer = (char *)malloc(100);
    if (n < 0) {
        free(buffer);  // Free before returning
        return -1;
    }
    printf("Buffer allocated\n");
    free(buffer);
    return 0;
}

// EXAMPLE 6: Memory Leak with Structures
struct Node {
    int data;
    struct Node *next;
};

void example_struct_leak() {
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    head->data = 10;
    head->next = (struct Node *)malloc(sizeof(struct Node));
    // MEMORY LEAK: neither head nor head->next is freed
}

// EXAMPLE 7: Correct Structure Cleanup
void example_struct_no_leak() {
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    head->data = 10;
    head->next = (struct Node *)malloc(sizeof(struct Node));
    
    // Properly free linked structures
    free(head->next);
    free(head);
}

int main() {
    printf("=== Memory Leak Examples in C ===\n\n");
    
    printf("Example 1: Simple Leak\n");
    example_leak();  // Memory leak occurs here
    
    printf("\nExample 3: No Leak\n");
    example_no_leak();  // Properly managed
    
    printf("\nExample 5: Correct Early Return\n");
    example_correct_early_return(5);  // Properly managed
    
    printf("\n=== Key Points ===\n");
    printf("1. Always pair malloc with free\n");
    printf("2. Set ptr to NULL after free\n");
    printf("3. Free memory before returning from function\n");
    printf("4. Use tools like valgrind to detect leaks\n");
    
    return 0;
}
