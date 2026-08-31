#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * DMA (Dynamic Memory Allocation) in C
 * 
 * Key Topics:
 * 1. malloc() - allocates memory, returns uninitialized pointer
 * 2. calloc() - allocates memory, initializes to zero
 * 3. realloc() - resizes previously allocated memory
 * 4. free() - deallocates memory
 * 5. Memory leaks and dangling pointers
 * 6. Pointer arithmetic
 */

// ============ Example 1: Basic malloc() usage ============
void example_malloc() {
    printf("\n=== Example 1: malloc() ===\n");
    
    int *ptr = (int *)malloc(5 * sizeof(int));
    
    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    // Initialize array
    for (int i = 0; i < 5; i++) {
        ptr[i] = i * 10;
    }
    
    // Print values
    for (int i = 0; i < 5; i++) {
        printf("ptr[%d] = %d\n", i, ptr[i]);
    }
    
    free(ptr);
    ptr = NULL;  // Best practice: set to NULL after free
}

// ============ Example 2: calloc() vs malloc() ============
void example_calloc() {
    printf("\n=== Example 2: calloc() ===\n");
    
    // malloc - uninitialized (garbage values)
    int *ptr1 = (int *)malloc(3 * sizeof(int));
    printf("malloc() (uninitialized): %d, %d, %d\n", ptr1[0], ptr1[1], ptr1[2]);
    free(ptr1);
    
    // calloc - initialized to 0
    int *ptr2 = (int *)calloc(3, sizeof(int));
    printf("calloc() (initialized to 0): %d, %d, %d\n", ptr2[0], ptr2[1], ptr2[2]);
    free(ptr2);
}

// ============ Example 3: realloc() - resizing memory ============
void example_realloc() {
    printf("\n=== Example 3: realloc() ===\n");
    
    int *ptr = (int *)malloc(3 * sizeof(int));
    
    if (ptr == NULL) {
        printf("Initial allocation failed!\n");
        return;
    }
    
    // Fill initial array
    for (int i = 0; i < 3; i++) {
        ptr[i] = i;
    }
    printf("Before realloc: ");
    for (int i = 0; i < 3; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");
    
    // Resize to 5 integers
    int *temp = (int *)realloc(ptr, 5 * sizeof(int));
    
    if (temp == NULL) {
        printf("Reallocation failed!\n");
        free(ptr);
        return;
    }
    
    ptr = temp;
    ptr[3] = 3;
    ptr[4] = 4;
    
    printf("After realloc: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");
    
    free(ptr);
    ptr = NULL;
}

// ============ Example 4: String manipulation with DMA ============
void example_string_dma() {
    printf("\n=== Example 4: String with DMA ===\n");
    
    char *str = (char *)malloc(50 * sizeof(char));
    
    if (str == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    strcpy(str, "Hello, Dynamic Memory!");
    printf("String: %s\n", str);
    printf("Length: %lu\n", strlen(str));
    
    free(str);
    str = NULL;
}

// ============ Example 6: Dangling Pointer ============
void example_dangling_pointer() {
    printf("\n=== Example 6: Dangling Pointer (DON'T DO THIS) ===\n");
    
    int *ptr = (int *)malloc(sizeof(int));
    *ptr = 42;
    printf("Value: %d\n", *ptr);
    
    free(ptr);
    // ptr is now dangling - points to freed memory
    // Accessing *ptr here is undefined behavior
    
    ptr = NULL;  // Fix: set to NULL after free
}

// ============ Example 7: Memory Leak Example (DON'T DO THIS) ============
void example_memory_leak() {
    printf("\n=== Example 7: Memory Leak (DON'T DO THIS) ===\n");
    
    int *ptr = (int *)malloc(100 * sizeof(int));
    ptr = NULL;  // Oops! Lost reference, memory leaked
    // Memory is still allocated but unreachable
    
    // Fix: free(ptr) before setting to NULL
}

// ============ Example 8: Struct with DMA ============
typedef struct {
    int id;
    char *name;
    float salary;
} Employee;

void example_struct_dma() {
    printf("\n=== Example 8: Struct with DMA ===\n");
    
    Employee *emp = (Employee *)malloc(sizeof(Employee));
    
    if (emp == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    emp->id = 101;
    emp->name = (char *)malloc(50 * sizeof(char));
    strcpy(emp->name, "John Doe");
    emp->salary = 50000.0;
    
    printf("ID: %d\nName: %s\nSalary: %.2f\n", 
           emp->id, emp->name, emp->salary);
    
    // Free in reverse order
    free(emp->name);
    free(emp);
    emp = NULL;
}

// ============ Example 9: Array of Structs ============
void example_array_of_structs() {
    printf("\n=== Example 9: Array of Structs ===\n");
    
    int n = 2;
    Employee *employees = (Employee *)malloc(n * sizeof(Employee));
    
    if (employees == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    for (int i = 0; i < n; i++) {
        employees[i].id = 100 + i;
        employees[i].name = (char *)malloc(50 * sizeof(char));
        sprintf(employees[i].name, "Employee_%d", i + 1);
        employees[i].salary = 40000.0 + (i * 5000);
    }
    
    for (int i = 0; i < n; i++) {
        printf("ID: %d, Name: %s, Salary: %.2f\n",
               employees[i].id, employees[i].name, employees[i].salary);
    }
    
    // Free all names first
    for (int i = 0; i < n; i++) {
        free(employees[i].name);
    }
    free(employees);
    employees = NULL;
}

// ============ Example 10: Pointer arithmetic ============
void example_pointer_arithmetic() {
    printf("\n=== Example 10: Pointer Arithmetic ===\n");
    
    int *ptr = (int *)malloc(5 * sizeof(int));
    
    for (int i = 0; i < 5; i++) {
        *(ptr + i) = i * 100;  // Pointer arithmetic
    }
    
    printf("Using pointer arithmetic: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(ptr + i));
    }
    printf("\n");
    
    free(ptr);
    ptr = NULL;
}

// ============ Main Function ============
int main() {
    printf("========== DMA EXAMPLES & INTERVIEW TOPICS ==========\n");
    
    example_malloc();
    example_calloc();
    example_realloc();
    example_string_dma();
    example_dangling_pointer();
    example_struct_dma();
    example_array_of_structs();
    example_pointer_arithmetic();
    
    printf("\n========== KEY POINTS FOR INTERVIEWS ==========\n");
    printf("1. Always check if malloc/calloc returned NULL\n");
    printf("2. Set pointer to NULL after free() - prevents use-after-free\n");
    printf("3. malloc() returns uninitialized, calloc() initializes to 0\n");
    printf("4. realloc() can change pointer address - use temp variable\n");
    printf("5. Free in reverse order of allocation\n");
    printf("6. Memory leak = allocated but unreachable memory\n");
    printf("7. Dangling pointer = points to freed/invalid memory\n");
    printf("8. sizeof is important: malloc(n * sizeof(type))\n");
    
    return 0;
}
