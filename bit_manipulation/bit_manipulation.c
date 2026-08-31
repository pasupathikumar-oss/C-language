#include <stdio.h>

int main() {
    // all bit manipulation operations are performed on unsigned integers
    unsigned int a = 5; // binary: 0000 0101   
    printf("a: %u\n", a);

    //set a bit 
    a |= (1 << 2); // set the third bit (0-indexed) to 1
    printf("a after setting bit 2: %u\n", a);

    //clear a bit
    a &= ~(1 << 0); // clear the first bit (0-indexed)
    printf("a after clearing bit 0: %u\n", a);

    //toggle a bit
    a ^= (1 << 1); // toggle the second bit (0-indexed)
    printf("a after toggling bit 1: %u\n", a);

    //check if a bit is set
    if (a & (1 << 2)) {
        printf("Bit 2 is set\n");
    } else {
        printf("Bit 2 is not set\n");
    }

    return 0;
}