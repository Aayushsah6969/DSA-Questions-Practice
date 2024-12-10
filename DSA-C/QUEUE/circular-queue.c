//circular-queue
#include<stdio.h>
#define MAX 5
int cq[MAX];
int rear=-1, front=-1;

void insert();
void delete1();
void display();

void main(){
    int choice;
   do{

   printf("\n----------QUEUE----------\n");
    printf("\n 1. Insert \n 2. Delete \n 3.Display \n 4.Exit\n");
    printf("---------------------------");
    printf("\nEnter Your Choice: ");
    scanf("%d",&choice);
    //printf("---------------------------\n");

    switch(choice){
        case 1: insert(); break;
        case 2: delete1();break;
        case 3: display();break;
        }
    }while(choice!=4);
}
void insert(){
    int n;
    if((rear+1)%MAX==front){
        printf("OVERFLOW\n");
    }else{
        printf("Enter data: ");
        scanf("%d",&n);
        if(rear == -1 && front == -1){
            rear =0;
            front =0;
        }else{
            rear = (rear+1)%MAX;
        }
        cq[rear]=n;
    }
}
void delete1(){
    if(rear == -1 && front == -1){
        printf("\n Queue is EMPTY");
    }else{
      int   n=cq[front];
        if(front == rear){
            front =-1; rear =-1;
        }else{
            front = (front+1)%MAX;
        }
        printf("Deleted Element: %d\n", n);
    }
}
void display(){
    if(rear == -1 && front == -1){
        printf("\n Queue is EMPTY");
    }else{
        printf("Elements are: \n");
        for( int i = front; i!=rear; (i=(i+1)%MAX)){
            printf("%5d\t",cq[i]);
        }
         printf("%5d\t", cq[rear]);  // Print the last element
    }
}