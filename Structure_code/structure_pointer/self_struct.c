//A self-referential structure is a structure that contains one or more pointers to the same type of structure
//as one of its members. These pointers allow multiple structure objects to be linked together, 
//making them the foundation of many dynamic data structures.

#include<stdio.h>

typedef struct Node {
    int data1;
    char data2;
    struct Node* link;   //self-referential pointer to the same structure type
} Node;

int main(){
    Node node;
    node.data1 = 10;
    node.data2 = 'A';
    node.link = NULL;
    printf("Data1: %d\n", node.data1);
    printf("Data2: %c\n", node.data2);  

    // callby reference
    Node node2;
    node2.data1 = 20;
    node2.data2 = 'B';
    node.link = &node2; //linking node to node2
    printf("Data1 of linked node: %d\n", node.link->data1); // NOTE: using '->' operator to access members of the linked node
    printf("Data2 of linked node: %c\n", node.link->data2); 
    return 0;
}

