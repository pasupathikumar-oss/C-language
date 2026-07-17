// visualize at : https://pythontutor.com/c.html#mode=edit

#include<stdio.h>
int main(){
    //variable
    int a=1;
    //(& initializer) pointer is initialized by assigning it the address of a variable
    //(*)to declare a pointer (int *, char *, float * -----> all these are datatypes of pointer)
    int *ptr=&a;
    //(*) is dereference operator used to dereference a pointer -----> use (*ptr) to access the variable's object
    printf("ptr=%d\n",*ptr);
    //(&p) is to print the pointer address  -----> use (&ptr) to access ptr address 
    printf("it is address of 'ptr':%p which is diffrent from the variable's address: %p \n",&ptr,&a);
    //diffrent ways to get the variable address
    printf("%p\n",ptr); // points variable address prints it
    printf("%p\n",*&ptr); // (&ptr) is ptr address ---> (*&ptr)---> dereference the address of variable
    printf("%d\n",**&ptr); // (&ptr) is ptr address ---> (*&ptr)---> dereference the address of variable ---> (**&ptr) dereference 'a' to get 1
    return 0;
}