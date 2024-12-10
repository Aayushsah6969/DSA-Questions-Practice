#include<stdio.h>
#define MAX 5
int queue[MAX];
int rear=-1, front=0;

void insert();
void delete1();
void display();

void main(){
    int choice;
   do{
   printf("\n----------QUEUE----------\n");
    printf("\n 1. Insert \n 2. Delete \n 3. Display \n 4. Exit\n");
    printf("\nEnter Your Choice: ");
    scanf("%d",&choice);
    switch(choice){
        case 1: insert(); break;
        case 2: delete1();break;
        case 3: display();break;
        }
    }while(choice!=4);
}

void insert(){
    int n;
    if(rear==MAX-1){
        printf("Overflow");
    }else{
        printf("Enter element: ");
        scanf("%d",&n);
        rear++;
        queue[rear]=n;
    }
}

void delete1(){
    if(front>rear){
        printf("Queue is empty!");
    }else{
       int  n=queue[front];
        printf("Deleted element: %d", n);
        front++;
    }
}

void display(){
     if(front>rear){
        printf("Queue is empty!");
    }else{
        printf("Elements are: \n");
        for(int i= rear; i>=front; i--){
            printf("%d\t",queue[i]);
        }
    }
}