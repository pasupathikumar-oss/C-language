// function pointer 
#include<stdio.h>

/*
// function pointer 
int add(int a, int b) {
    return a + b;
}

int main(){
    int (*fptr)(int, int);
    fptr = &add;
    printf("%d\n", fptr(10, 5));
    return 0;
} 
*/



/*
// function pointer as argument (callback)
int add(int a, int b) {
    return a + b;
}

// A simple subtraction function
int subtract(int a, int b) {
    return a - b;
}

void calc(int a, int b, int (*op)(int, int)) {
    printf("%d\n", op(a, b));
}

int main() {
  
    // Passing different 
    // functions to 'calc'
    calc(10, 5, add);
  	calc(10, 5, subtract);
    return 0;
}
*/



