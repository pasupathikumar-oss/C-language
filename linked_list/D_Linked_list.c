#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
// Each node contains:
// - data: stores the integer value
// - next: pointer to the next node
// - prev: pointer to the previous node
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Function to create a new node
// Parameters: data - the value to store in the node
// Returns: pointer to the newly created node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
// Parameters: head - pointer to the current head of the list, data - value to insert
// Returns: pointer to the new head
Node* insertAtBeginning(Node* head, int data) {
    Node* newNode = createNode(data);
    if (newNode == NULL) return head;
    
    if (head == NULL) {
        return newNode;
    }
    
    newNode->next = head;
    head->prev = newNode;
    return newNode;
}

// Function to insert a node at the end of the list
// Parameters: head - pointer to the head of the list, data - value to insert
// Returns: pointer to the head
Node* insertAtEnd(Node* head, int data) {
    Node* newNode = createNode(data);
    if (newNode == NULL) return head;
    
    if (head == NULL) {
        return newNode;
    }
    
    // Traverse to the last node
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    // Link the new node
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

// Function to insert a node at a specific position (1-based indexing)
// Parameters: head - pointer to the head, data - value to insert, position - 1-based position
// Returns: pointer to the head
Node* insertAtPosition(Node* head, int data, int position) {
    if (position < 1) {
        printf("Invalid position!\n");
        return head;
    }
    
    if (position == 1) {
        return insertAtBeginning(head, data);
    }
    
    Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Position out of range!\n");
        return head;
    }
    
    Node* newNode = createNode(data);
    if (newNode == NULL) return head;
    
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    return head;
}

// Function to delete a node from the beginning
// Parameters: head - pointer to the head
// Returns: pointer to the new head
Node* deleteFromBeginning(Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return NULL;
    }
    
    Node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
    return head;
}

// Function to delete a node from the end
// Parameters: head - pointer to the head
// Returns: pointer to the head
Node* deleteFromEnd(Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return NULL;
    }
    
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    
    // Traverse to the last node
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    // Unlink the last node
    temp->prev->next = NULL;
    free(temp);
    return head;
}

// Function to delete a node at a specific position (1-based indexing)
// Parameters: head - pointer to the head, position - 1-based position
// Returns: pointer to the head
Node* deleteAtPosition(Node* head, int position) {
    if (head == NULL || position < 1) {
        printf("Invalid operation!\n");
        return head;
    }
    
    if (position == 1) {
        return deleteFromBeginning(head);
    }
    
    Node* temp = head;
    for (int i = 1; i < position && temp != NULL; i++) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Position out of range!\n");
        return head;
    }
    
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);
    return head;
}

// Function to display the list in forward direction
// Parameters: head - pointer to the head
void displayForward(Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    printf("Forward: ");
    Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to display the list in backward direction
// Parameters: head - pointer to the head
void displayBackward(Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    // Find the last node
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    printf("Backward: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

// Function to search for a value in the list
// Parameters: head - pointer to the head, value - value to search
// Returns: 1 if found, 0 if not found
int search(Node* head, int value) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == value) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

// Function to get the count of nodes in the list
// Parameters: head - pointer to the head
// Returns: number of nodes
int getCount(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Function to free all allocated memory
// Parameters: head - pointer to the head
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Main function demonstrating all operations
int main() {
    Node* head = NULL;
    int choice, data, position;
    
    while (1) {
        printf("\n========== DOUBLY LINKED LIST OPERATIONS ==========\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete at Position\n");
        printf("7. Display Forward\n");
        printf("8. Display Backward\n");
        printf("9. Search\n");
        printf("10. Get Count\n");
        printf("11. Exit\n");
        printf("===================================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                printf("Inserted %d at beginning.\n", data);
                break;
                
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                printf("Inserted %d at end.\n", data);
                break;
                
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position (1-based): ");
                scanf("%d", &position);
                head = insertAtPosition(head, data, position);
                printf("Inserted %d at position %d.\n", data, position);
                break;
                
            case 4:
                head = deleteFromBeginning(head);
                printf("Deleted from beginning.\n");
                break;
                
            case 5:
                head = deleteFromEnd(head);
                printf("Deleted from end.\n");
                break;
                
            case 6:
                printf("Enter position to delete (1-based): ");
                scanf("%d", &position);
                head = deleteAtPosition(head, position);
                printf("Deleted at position %d.\n", position);
                break;
                
            case 7:
                displayForward(head);
                break;
                
            case 8:
                displayBackward(head);
                break;
                
            case 9:
                printf("Enter value to search: ");
                scanf("%d", &data);
                if (search(head, data)) {
                    printf("Value %d found in the list.\n", data);
                } else {
                    printf("Value %d not found in the list.\n", data);
                }
                break;
                
            case 10:
                printf("Count of nodes: %d\n", getCount(head));
                break;
                
            case 11:
                freeList(head);
                printf("Exiting program. Memory freed.\n");
                exit(0);
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}
