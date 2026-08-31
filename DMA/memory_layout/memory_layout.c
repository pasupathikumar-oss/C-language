//memory layout in C are:
// 1. TEXT SEGMENT (CODE) - Read-only, stores executable instructions
// 2. INITIALIZED DATA SEGMENT - Global and static variables that are explicitly initialized
// 3. UNINITIALIZED DATA SEGMENT (BSS) - Global and static variables that are zero-initialized
// 4. HEAP - Dynamically allocated memory (grows upward, malloc/calloc/realloc)
// 5. STACK - Local variables, function parameters, return addresses (grows downward)

#include <stdio.h>
#include <stdlib.h>

// Global initialized variable - goes to DATA segment
int globalVar = 10;

// Global uninitialized variable - goes to BSS segment
int globalUninitVar;

// Static global variable - goes to DATA/BSS segment
static int staticGlobalVar = 20;

int main() {
    // Local variables - go to STACK segment
    int localVar = 5;
    char localArray[100];  // 100 bytes allocated on STACK  // if array in global goes to DATA segment
    
    // Static local variable - goes to DATA segment //Since STATIC is used goes to DATA segment, if STATIC is not used goes to STACK segment
    static int staticLocalVar = 15;
    
    // Dynamic memory allocation - goes to HEAP segment
    int *heapPtr = (int *)malloc(sizeof(int) * 10);
    
    printf("Text Segment (Code): %p\n", (void *)main);
    printf("Global Data (Initialized): %p\n", (void *)&globalVar);
    printf("Global Data (Uninitialized): %p\n", (void *)&globalUninitVar);
    printf("Static Global: %p\n", (void *)&staticGlobalVar);
    printf("Local Variable (Stack): %p\n", (void *)&localVar);
    printf("Heap Memory: %p\n", (void *)heapPtr);
    
    free(heapPtr);
    return 0;
} 
