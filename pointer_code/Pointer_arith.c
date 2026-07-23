// pointer arithmatics are diffrent from regular ones, they work with memory rather than values 
// ARITHMATICS:
// 1]. Increment/Decriment 2]. add/sub integer to ptr 3]. sub 2 pointer 4]. compare pointers 5]. compare to NULL 6]. pointer arith. for array 
// New Address = Current Address ± (Number × Size of Data Type)
// sizeof(int) = 4 -----> ptr ->1000
// ptr + 1 -> 1004       ptr - 1 -> 996
// ptr + 2 -> 1008       ptr - 2 -> 992

#include<stdio.h>

int main(){

    // INCREMENT/DECREMENT 
    int a = 2;
    int *ptr =&a;
    printf("ptr = %p\n",ptr);
    printf("a=%d\n",*ptr);

    // increment ptr
    ptr++;
    printf("ptr++ =%p\n",ptr);
    printf("a=%d\n",*ptr);

    // decrement ptr
    ptr--;
    printf("ptr-- =%p\n",ptr);
    printf("a=%d\n",*ptr);
    
    //ADD/SUB INT TO PTR

    int b=3;
    int *ptr2=&b;
    printf("ptr2=%p\n",ptr2);
    printf("value=%d\n",*ptr2);

    //add integer 
    // addess skip by (val integer given * SizeOf(int)+ ptr add.)
    ptr2 = ptr2 + 3;
    printf("Pointer ptr2 after addition: ");
    printf("%p \n", ptr2);

    //sub integer
    //addess skip by (val integer given * SizeOf(int)- ptr add.)
    ptr2 = ptr2 - 3;
    printf("Pointer ptr2 after addition: ");
    printf("%p \n", ptr2);

    //SUB 2 PTR

    //Two pointers can be subtracted only if they point to elements of the same data type
    //The result represents the number of elements between the two memory locations, not the difference in bytes.
    int x = 6; 
    int N = 4;
    int *ptr3, *ptr4;
    ptr3 = &N; 
    ptr4 = &x; 
    printf(" ptr1 = %p, ptr2 = %p\n", ptr3, ptr4);
    x = ptr3 - ptr4;
    printf("Subtraction of ptr1 & ptr2 is %d\n", x);

    // COMPARE OPERATOR (>, >=, <, <=, ==, !=)

    int aa = 10, bb = 20;
    int arr[5];
    int *p = &aa;
    int *q = &aa;
    int *r = &bb;
    int *pp = &arr[1];
    int *qq = &arr[4];


    printf("%d\n", p == q);   // 1 (true)
    printf("%d\n", p != r);   // 1 (true)
    printf("%d\n", pp < qq);   // true
    printf("%d\n", pp <= qq);  // true
    printf("%d\n", qq > pp);   // true
    printf("%d\n", qq >= pp);  // true


    return 0;
}