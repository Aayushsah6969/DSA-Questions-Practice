#include<stdio.h>
#include<stdlib.h>

struct stack{
    int data;
    struct stack *next;
};
struct stack *top=NULL, *new, *temp;

void push();
void display();
void pop();

void main(){
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
        }
    } while (choice != 4); // Continue the loop until the user selects 4 to exit.
}

void push(){
    int n;
    printf("Enter Element: ");
    scanf("%d",&n);
    new = (struct stack *)malloc(sizeof(struct stack));
    new -> data = n;
    new->next=top;
    top=new;
    
}

void display(){
    if(top==NULL){
        printf("STACK EMPTY!!!");
    }else{
        temp = top;
        while(temp!=NULL){
            printf("%d\t",temp->data);
            temp=temp->next;
        }
    }
}

void pop(){
    
    if(top == NULL){
        printf("Empty stack\n");
    }else{
        temp=top;
        top= top->next;
        printf("Deleted: %d",temp->data);
        free(temp);
    }
}