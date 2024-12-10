#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;               // The value in the node
    struct Node* left;      // Pointer to the left child
    struct Node* right;     // Pointer to the right child
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to print the tree in order
void printTree(struct Node* root) {
    if (root != NULL) {
        printTree(root->left);    // Visit left subtree
        printf("%d ", root->data);// Print node data
        printTree(root->right);   // Visit right subtree
    }
}

int main() {
    // Create the root node
    struct Node* root = createNode(1);

    // Create child nodes
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    // Print the tree
    printf("Tree: ");
    printTree(root);
    printf("\n");

    return 0;
}
