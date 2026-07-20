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
    //size of pointer
    printf("%zu\n", sizeof(ptr));// (%zu) to get size (if PC is 64Bit)--->size is 8 (if PC is 32Bit)--->size is 4


    //NULL Pointer
    //A NULL Pointers is a pointer that does not point to any valid memory location.
    //It is created by assigning the value NULL to a pointer variable.
    int *ptr_NULL = NULL;


    //VOID pointer (or) Generic pointer
    //Special type of pointer that can store the address of any data type
    //Before accessing the value stored at a void pointer, it must be explicitly typecast to the appropriate pointer type.

    int aa = 10;
    void* ptr_void = &aa;
    printf("void pointer output: %d",*(int*)ptr_void);


    //WILD Pointer
    //The wild pointer is a pointer that has been declared but not initialized with a valid memory address.

        // int *ptr_wild;
        // *ptr_wild =10; // this cause an error in code bacause ptr_wild point to a garbage value
    

    //DANGLING Pointer
    //A dangling pointer is a pointer that refers to a memory location that has already been deallocated or freed.
    int *b= (int*)malloc(sizeof(int)); //a memory is assigned to int ptr 'b'
    free(b); //memory is freed
    //currently the 'b' is pointing to a memory that is freed which cause unexpected behavior
    b=NULL; 
    // Dangling pointers are created in other cases too 1]. Accessing variable from one func in other without proper storage class, 
    //2]. When variable goes out of scope it cause dangling pointer issue
    
    
    //CONSTANT Pointer
    // the memory address stored inside the pointer is constant and cannot be modified once it is defined. 
    //It will always point to the same memory address.
    int c = 90;
    int bb = 50;
    // Creating a constant pointer
    int* const ptr = &c;
    // Trying to reassign it to b
    ptr = &bb; //This action fails. 
    return 0;
}