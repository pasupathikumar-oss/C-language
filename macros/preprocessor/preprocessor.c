/* ============================================================================
   PREPROCESSOR DIRECTIVES IN C - Complete Guide with Examples
   
   Preprocessor runs BEFORE compilation. It processes directives starting with #
   Common use cases: Including headers, defining constants, conditional compilation
============================================================================ */

#include <stdio.h>
#include <stdlib.h>

/* ============================================================================
   1. #include - Including Header Files
============================================================================ */

/* #include <stdio.h>        - System header (angle brackets) - search in standard paths
   #include "myheader.h"     - Local header (quotes) - search in current directory first */


/* ============================================================================
   2. #define - Defining Constants and Macros (No type safety, simple text replacement)
============================================================================ */

#define PI 3.14159              /* Object-like macro - constant replacement */
#define MAX_SIZE 100            /* Used for array sizes in production code */
#define GET_MAX(a, b) ((a) > (b) ? (a) : (b))  /* Function-like macro - takes arguments */
#define SQUARE(x) ((x) * (x))   /* Common in production for inline performance-critical code */
#define PRINT_DEBUG(x) printf("DEBUG: %d\n", x)  /* Used in logging frameworks */

/* Production example: Thread-safe logging macro */
#define LOG_ERROR(fmt, ...) \
    do { \
        fprintf(stderr, "[ERROR] " fmt "\n", ##__VA_ARGS__); \
        fflush(stderr); \
    } while(0)

/* ============================================================================
   3. Predefined Macros - Available automatically
============================================================================ */

/* __LINE__    - Current line number
   __FILE__    - Current filename
   __DATE__    - Compilation date
   __TIME__    - Compilation time
   __STDC__    - Defined if compiler is standard-compliant
   __VA_ARGS__ - Variable arguments in macros (used in production logging) */


/* ============================================================================
   4. #ifdef, #ifndef, #if, #else, #endif - Conditional Compilation
============================================================================ */

/* Used in production for: Platform-specific code, debug builds, feature toggles */

#define DEBUG_MODE 1
#define PLATFORM_LINUX 1

#ifdef DEBUG_MODE
    #define DEBUG_PRINT(x) printf("DEBUG: %s = %d\n", #x, x)
#else
    #define DEBUG_PRINT(x)  /* No-op in release builds */
#endif

#if defined(PLATFORM_LINUX)
    #define NEWLINE "\n"
#elif defined(PLATFORM_WINDOWS)
    #define NEWLINE "\r\n"
#else
    #define NEWLINE "\n"
#endif


/* ============================================================================
   5. Stringification (#) and Token Pasting (##) - Advanced Macro Techniques
============================================================================ */

/* # converts macro argument to string
   ## concatenates tokens */

#define STRINGIFY(x) #x         /* "x" becomes "hello" */
#define CONCAT(a, b) a##b       /* a, b becomes ab (useful for variable names) */
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))  /* Common production macro */

/* Production example: Generic data structure */
#define DEFINE_STACK(type) \
    typedef struct { \
        type* data; \
        int size; \
        int capacity; \
    } type##_stack;

DEFINE_STACK(int)      /* Creates int_stack */
DEFINE_STACK(double)   /* Creates double_stack */


/* ============================================================================
   6. #error, #warning - Compilation Feedback
============================================================================ */

#if !defined(BUFFER_SIZE)
    #define BUFFER_SIZE 256
#endif

#if BUFFER_SIZE < 100
    #error "BUFFER_SIZE must be at least 100"
#endif


/* ============================================================================
   PRACTICAL PRODUCTION EXAMPLES
============================================================================ */

/* Example 1: Safe memory allocation macro (used in Linux kernel, real projects) */
#define MALLOC_SAFE(ptr, type, count) \
    do { \
        ptr = (type*)malloc(sizeof(type) * count); \
        if (!ptr) { \
            fprintf(stderr, "Memory allocation failed at %s:%d\n", __FILE__, __LINE__); \
            exit(EXIT_FAILURE); \
        } \
    } while(0)

/* Example 2: Assert macro (used in debugging) */
#define ASSERT(condition) \
    if (!(condition)) { \
        fprintf(stderr, "Assertion failed: %s at %s:%d\n", #condition, __FILE__, __LINE__); \
        exit(EXIT_FAILURE); \
    }

/* Example 3: Container of (Linux kernel style - get structure from member pointer) */
#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

/* Example 4: MIN/MAX macros (use parentheses to avoid operator precedence issues) */
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))


/* ============================================================================
   FUNCTION DEMONSTRATIONS
============================================================================ */

int main() {
    printf("===== PREPROCESSOR CONCEPTS DEMO =====\n\n");

    /* 1. Constants via #define */
    printf("1. CONSTANTS:\n");
    printf("   PI = %.5f\n", PI);
    printf("   MAX_SIZE = %d\n", MAX_SIZE);
    printf("\n");

    /* 2. Function-like macros */
    printf("2. FUNCTION-LIKE MACROS:\n");
    int x = 5, y = 10;
    printf("   GET_MAX(%d, %d) = %d\n", x, y, GET_MAX(x, y));
    printf("   SQUARE(%d) = %d\n", x, SQUARE(x));
    printf("\n");

    /* 3. Predefined macros */
    printf("3. PREDEFINED MACROS:\n");
    printf("   File: %s\n", __FILE__);
    printf("   Line: %d\n", __LINE__);
    printf("   Date: %s\n", __DATE__);
    printf("   Time: %s\n", __TIME__);
    printf("\n");

    /* 4. Stringification example */
    printf("4. STRINGIFICATION (#):\n");
    printf("   STRINGIFY(hello) = %s\n", STRINGIFY(hello));
    printf("   STRINGIFY(123) = %s\n", STRINGIFY(123));
    printf("\n");

    /* 5. Conditional compilation demonstration */
    printf("5. CONDITIONAL COMPILATION:\n");
    #ifdef DEBUG_MODE
        printf("   DEBUG_MODE is enabled\n");
        DEBUG_PRINT(x);
    #endif
    printf("   NEWLINE character platform: %s\n", 
           strcmp(NEWLINE, "\n") == 0 ? "UNIX/LINUX" : "WINDOWS");
    printf("\n");

    /* 6. Array size macro (production utility) */
    printf("6. ARRAY_SIZE MACRO:\n");
    int arr[] = {1, 2, 3, 4, 5};
    printf("   Array size: %zu elements\n", ARRAY_SIZE(arr));
    printf("\n");

    /* 7. Safe macros demonstration */
    printf("7. PRODUCTION-LEVEL MACROS:\n");
    int* buffer = NULL;
    MALLOC_SAFE(buffer, int, 10);
    printf("   Allocated 10 integers safely\n");
    free(buffer);
    printf("\n");

    /* 8. MIN/MAX with parentheses */
    printf("8. MIN/MAX MACROS:\n");
    printf("   MIN(5, 10) = %d\n", MIN(5, 10));
    printf("   MAX(5, 10) = %d\n", MAX(5, 10));
    
    return 0;
}

/* ============================================================================
   KEY INTERVIEW POINTS:
   
   ✓ Preprocessor runs BEFORE compilation (text substitution)
   ✓ #define creates compile-time constants (no runtime overhead)
   ✓ Macros with arguments use () for safety against precedence issues
   ✓ Use do { ... } while(0) for multi-statement macros (exception safety)
   ✓ Stringification (#) and token pasting (##) for meta-programming
   ✓ Conditional compilation for platform/build-specific code
   ✓ Predefined macros (__LINE__, __FILE__, __DATE__) for debugging
   ✓ Production use cases: Logging, memory allocation, assertions, performance
   ✓ Disadvantages: No type safety, difficult to debug, can cause namespace pollution
   ✓ Modern C prefers inline functions/const over macros when possible
   
   PRODUCTION PATTERNS:
   - Logging frameworks use ## __VA_ARGS__ for variadic macros
   - Linux kernel uses container_of for intrusive data structures
   - Embedded systems use conditional compilation for memory optimization
   - Debug builds enable assertions via preprocessor flags
============================================================================ */
