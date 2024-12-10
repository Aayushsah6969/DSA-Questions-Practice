#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;          // Data part of the node, storing an integer value
    struct Node* next; // Pointer to the next node
};

// Function to create a new node
struct Node* newNode(int data) {
    // Allocate memory for a new node
    struct Node* newNodePtr = (struct Node*)malloc(sizeof(struct Node));
    
    // Check if memory allocation is successful
    if (newNodePtr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1); // Exit the program if memory allocation fails
    }
    
    // Set the data of the new node
    newNodePtr->data = data;
    
    // Set the next pointer of the new node to NULL
    newNodePtr->next = NULL;
    
    // Return the newly created node
    return newNodePtr;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node** head, int data) {
    // Create a new node with the given data
    struct Node* newNodePtr = newNode(data);
    
    // Set the next pointer of the new node to the current head
    newNodePtr->next = *head;
    
    // Update the head to point to the new node
    *head = newNodePtr;
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** head, int data) {
    // Create a new node with the given data
    struct Node* newNodePtr = newNode(data);
    
    // If the list is empty, make the new node the head of the list
    if (*head == NULL) {
        *head = newNodePtr;
        return;
    }
    
    // Traverse the list to find the last node
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    
    // Set the next pointer of the last node to the new node
    temp->next = newNodePtr;
}

// Function to display the linked list
void display(struct Node* head) {
    // Traverse the list and print the data of each node
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Main function
int main() {
    // Initialize the head pointer to NULL
    struct Node* head = NULL;
    
    // Insert some nodes at the end of the list
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    
    // Insert a node at the beginning of the list
    insertAtBeginning(&head, 4);
    
    // Display the linked list
    display(head);
    
    // Return 0 to indicate successful execution
    return 0;
}
