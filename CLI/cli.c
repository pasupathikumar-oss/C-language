#include <stdio.h>

int main (int argc, char *argv[]){ // argc is the number of command line arguments, argv is an array of strings (char pointers) representing the command line arguments
    printf("Hello World!\n");
    printf("argc: %d\n", argc); // print the number of command line arguments
    printf("argv[0]: %s\n", argv[0]); // print the first command line argument (the name of the program)
    return 0;
}