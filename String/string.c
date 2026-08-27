//A string in C is a sequence of characters stored in a character array and terminated by the null character '\0'.

#include <stdio.h>
#include <string.h>
int main() {
    
    // declaring and initializing a string
    char str[] = "Geeks";

    // printing the string
    printf("The string is: %s\n", str);
    // accessing a individual character in the string
    printf("%c\n", str[0]);
    //updating a character in the string
    str[0] = 'g';
    printf("The updated string is: %s\n", str);
    // getting the length of the string
    printf("%ld", strlen(str));
    

    char strr[20] = "Geeks";

    // Pointer variable which stores
    // the starting address of
    // the character array str
    char* ptr = strr;

    // While loop will run till 
    // the character value is not
    // equal to null character
    while (*ptr != '\0') {
        printf("%c", *ptr);
        ptr++;
    }

    //string literal
    //A string literal is a sequence of characters enclosed in double quotes, 
    //such as "Hello World". It is automatically stored as a null-terminated string in memory.
    
    return 0;
}