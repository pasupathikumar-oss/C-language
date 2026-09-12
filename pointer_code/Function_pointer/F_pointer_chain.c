#include <stdio.h>

void fun2() {
    printf("Hello from fun2\n");
}

void (*fun1())() {
    printf("Hello from fun1\n");
    return fun2;
}

int main() {
    void (*p)() = fun1();

    p();   // calls fun2

    return 0;
}
