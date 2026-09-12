/*
 * SINGLE LINKED LIST - Explanation and Operations
 * 
 * A Singly Linked List is a linear data structure where:
 * - Each node contains data and a pointer to the next node
 * - The last node points to NULL
 * - We can traverse only in one direction (forward)
 * 
 * Advantages:
 * - Dynamic memory allocation
 * - Efficient insertion/deletion at beginning
 * - No memory wastage
 * 
 * Disadvantages:
 * - Cannot traverse backward
 * - Extra memory for pointers
 * - Cannot random access to elements
 */

#include <stdio.h>
#include <stdlib.h>

// Node structure for single linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function prototypes
Node* createNode(int data);
Node* insertAtBeginning(Node* head, int data);
Node* insertAtEnd(Node* head, int data);
Node* insertAtPosition(Node* head, int data, int position);
Node* deleteFromBeginning(Node* head);
Node* deleteFromEnd(Node* head);
Node* deleteFromPosition(Node* head, int position);
void display(Node* head);
void displayReverse(Node* head);
int search(Node* head, int key);
void freeList(Node* head);

// Create a new node with given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert node at the beginning
Node* insertAtBeginning(Node* head, int data) {
    Node* newNode = createNode(data);
    if (newNode == NULL) return head;
    newNode->next = head;
    return newNode;
}

// Insert node at the end
Node* insertAtEnd(Node* head, int data) {
    Node* newNode = createNode(data);
    if (newNode == NULL) return head;
    
    if (head == NULL) {
        return newNode;
    }
    
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Insert node at specific position (1-indexed)
Node* insertAtPosition(Node* head, int data, int position) {
    if (position < 1) {
        printf("Invalid position!\n");
        return head;
    }
    
    if (position == 1) {
        return insertAtBeginning(head, data);
    }
    
    Node* newNode = createNode(data);
    if (newNode == NULL) return head;
    
    Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Position out of bounds!\n");
        free(newNode);
        return head;
    }
    
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

// Delete node from beginning
Node* deleteFromBeginning(Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return NULL;
    }
    
    Node* temp = head;
    head = head->next;
    printf("Deleted: %d\n", temp->data);
    free(temp);
    return head;
}

// Delete node from end
Node* deleteFromEnd(Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return NULL;
    }
    
    if (head->next == NULL) {
        printf("Deleted: %d\n", head->data);
        free(head);
        return NULL;
    }
    
    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    
    printf("Deleted: %d\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
    return head;
}

// Delete node from specific position (1-indexed)
Node* deleteFromPosition(Node* head, int position) {
    if (head == NULL || position < 1) {
        printf("Invalid position or empty list!\n");
        return head;
    }
    
    if (position == 1) {
        return deleteFromBeginning(head);
    }
    
    Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    
    if (temp == NULL || temp->next == NULL) {
        printf("Position out of bounds!\n");
        return head;
    }
    
    Node* nodeToDelete = temp->next;
    printf("Deleted: %d\n", nodeToDelete->data);
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
    return head;
}

// Display the linked list
void display(Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    printf("List: ");
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Display the linked list in reverse using recursion
void displayReverse(Node* head) {
    if (head == NULL) {
        return;
    }
    displayReverse(head->next);
    printf("%d -> ", head->data);
}

// Search for an element in the linked list
int search(Node* head, int key) {
    Node* temp = head;
    int position = 1;
    
    while (temp != NULL) {
        if (temp->data == key) {
            return position;
        }
        temp = temp->next;
        position++;
    }
    
    return -1; // Not found
}

// Free all nodes in the linked list
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Main function to demonstrate all operations
int main() {
    Node* head = NULL;
    
    printf("=== SINGLE LINKED LIST OPERATIONS ===\n\n");
    
    // Insert at end
    printf("--- Inserting elements at end ---\n");
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);
    display(head);
    
    // Insert at beginning
    printf("\n--- Inserting 5 at beginning ---\n");
    head = insertAtBeginning(head, 5);
    display(head);
    
    // Insert at position
    printf("\n--- Inserting 25 at position 4 ---\n");
    head = insertAtPosition(head, 25, 4);
    display(head);
    
    // Search
    printf("\n--- Searching for elements ---\n");
    int pos = search(head, 25);
    if (pos != -1) {
        printf("Element 25 found at position: %d\n", pos);
    } else {
        printf("Element 25 not found!\n");
    }
    
    // Delete from beginning
    printf("\n--- Deleting from beginning ---\n");
    head = deleteFromBeginning(head);
    display(head);
    
    // Delete from end
    printf("\n--- Deleting from end ---\n");
    head = deleteFromEnd(head);
    display(head);
    
    // Delete from position
    printf("\n--- Deleting from position 2 ---\n");
    head = deleteFromPosition(head, 2);
    display(head);
    
    // Display in reverse
    printf("\n--- Display in reverse ---\n");
    printf("Reverse: ");
    displayReverse(head);
    printf("NULL\n");
    
    // Free the list
    freeList(head);
    printf("\n--- List freed from memory ---\n");
    
    return 0;
}
