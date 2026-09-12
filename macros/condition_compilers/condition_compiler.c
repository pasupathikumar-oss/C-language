#include<stdio.h>

#define DEBUG 1
#define VERSION 2

int main (){
    // #ifdef: Checks if a macro is defined
    #ifdef DEBUG
        printf("Debug mode is ON\n");
    #endif
    
    // #if/#elif/#else: Conditional compilation based on constant expressions
    #if VERSION == 1
        printf("Version 1\n");
    #elif VERSION == 2
        printf("Version 2\n");
    #else
        printf("Unknown version\n");
    #endif
    
    // #ifndef: Checks if a macro is NOT defined
    #ifndef PRODUCTION
        printf("Not in production\n");
    #endif
    
    // defined(): Operator to check if macro exists (used in #if expressions)
    #if defined(DEBUG) && VERSION > 1
        printf("Debug enabled and version greater than 1\n");
    #endif
    
    // #if 0: Block of code that won't be compiled
    #if 0
        printf("This code is excluded from compilation\n");
    #endif
    
    // #if 1: Block of code that will always be compiled
    #if 1
        printf("This code is always included\n");
    #endif
    
    return 0;
}