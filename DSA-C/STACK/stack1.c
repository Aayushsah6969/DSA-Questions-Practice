#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10

// This program implements a stack using an array in C.
// A stack is a linear data structure that follows the LIFO (Last In, First Out) principle.
// The stack has a fixed size defined by MAXSIZE.
// The operations supported are push (to add an element), pop (to remove an element), and display (to show all elements).

int stack[MAXSIZE], top = -1;  // Declare the stack and initialize the top pointer to -1, indicating an empty stack.

void push();    // Function prototype for push operation.
void pop();     // Function prototype for pop operation.
void display(); // Function prototype for display operation.

void main() {
    int choice;
    // Main menu loop: Displays the menu, takes user input, and performs the selected operation.
    do {
        printf("\n----------STACK----------\n");
        printf("\n 1. Push \n 2. Pop \n 3. Display \n 4. Exit");
        printf("\n--------------------------\n");
        printf("\n Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: push(); break;    // Call push function if user selects 1.
            case 2: pop(); break;     // Call pop function if user selects 2.
            case 3: display(); break; // Call display function if user selects 3.
            case 4: exit(0);          // Exit the program if user selects 4.
            default: printf("\n Invalid choice"); // Print error message for invalid choice.
        }
    } while (choice != 4); // Continue the loop until the user selects 4 to exit.
}

// Push function: Adds an element to the top of the stack.
void push() {
    int n;
    if (top == MAXSIZE - 1) {
        // Check if the stack is full.
        printf("\nStack Overflow\n");
    } else {
        // If not full, prompt the user for an element to push.
        printf("\nEnter Element: \n");
        scanf("%d", &n);
        top++;             // Increment the top pointer.
        stack[top] = n;    // Add the element to the stack.
    }
}

// Display function: Shows all elements in the stack from top to bottom.
void display() {
    int i;
    if (top == -1) {
        // Check if the stack is empty.
        printf("\nStack is empty!\n");
    } else {
        // If not empty, print all elements.
        printf("\nElements are: \n");
        for (i = top; i >= 0; i--) {
            printf("\n %d", stack[i]);
        }
    }
}

// Pop function: Removes the top element from the stack.
void pop() {
    int n;
    if (top == -1) {
        // Check if the stack is empty.
        printf("\nStack is empty!\n");
    } else {
        // If not empty, remove the top element and decrement the top pointer.
        n = stack[top];
        top--;
        printf("Popped Out: %d\n", n); // Print the popped element.
    }
}
