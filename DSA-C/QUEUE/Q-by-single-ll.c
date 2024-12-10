#include<stdio.h>
#include<stdlib.h>

// Node structure for the queue
struct queueNode {
    int data;
    struct queueNode *next;
};

// Structure for the queue
struct Queue {
    struct queueNode *front, *rear;
};

// Function prototypes
void enqueue(struct Queue *q, int data);
void dequeue(struct Queue *q);
void display(struct Queue *q);

// Main function
int main() {
    struct Queue q;
    q.front = q.rear = NULL; // Initialize front and rear pointers to NULL
    
    int choice, data;
    
    // Main menu loop
    do {
        printf("\n----------QUEUE----------\n");
        printf("\n 1. Enqueue \n 2. Dequeue \n 3. Display \n 4. Exit");
        printf("\n--------------------------\n");
        printf("\n Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &data);
                enqueue(&q, data);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                display(&q);
                break;
        }
    } while (choice != 4);
    
    return 0;
}

// Function to enqueue (insert) an element into the queue
void enqueue(struct Queue *q, int data) {
    // Create a new node
    struct queueNode *newNode = (struct queueNode*)malloc(sizeof(struct queueNode));
    newNode->data = data;
    newNode->next = NULL;
    
    // If the queue is empty, set the front and rear pointers to the new node
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    
    // Otherwise, add the new node at the end and update the rear pointer
    q->rear->next = newNode;
    q->rear = newNode;
}

// Function to dequeue (remove) an element from the queue
void dequeue(struct Queue *q) {
    // If the queue is empty, print an error message
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    
    // Store the front node and move the front pointer to the next node
    struct queueNode *temp = q->front;
    q->front = q->front->next;
    
    // If the front becomes NULL, update the rear pointer to NULL as well
    if (q->front == NULL) {
        q->rear = NULL;
    }
    
    // Free the memory of the dequeued node and print the dequeued data
    printf("Dequeued: %d\n", temp->data);
    free(temp);
}

// Function to display the elements of the queue
void display(struct Queue *q) {
    // If the queue is empty, print an error message
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    
    // Iterate through the queue and print each element
    struct queueNode *temp = q->front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
