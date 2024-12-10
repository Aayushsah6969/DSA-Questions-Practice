#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *prev;
    int data;
    struct node *next;
}; 
struct node *head=NULL, *temp, *new, *left, *right ;

void Create();
void Display();
void Insert_First();
void Insert_Last();
void Insert_Middle();
void Delete_First();
void Delete_Last();
void Delete_Middle();
void Count();
void Search();

void main(){
    int choice;
    do{
        printf("\n---------Doubly-Linked-List--------\n");
        printf("\n1.Create  \n2.Display  \n3.Insert_First \n4.Insert_Last \n5.Insert_Middle \n6.Delete_First \n7.Delete_Last \n8.Delete_Middle \n9.Count \n10.Search \n00.Exit \n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:Create();break;
            case 2:Display();break;
            case 3:Insert_First();break;
            case 4:Insert_Last();break;
            case 5:Insert_Middle();break;
            case 6:Delete_First();break;
            case 7:Delete_Last();break;
            case 8:Delete_Middle();break;
            case 9:Count();break;
            case 10:Search();break;
        }
    }while(choice!=00);
}

void Count(){
     int count = 0;
    temp = head;
    while(temp!=NULL){
        count++ ;
        temp = temp->next;
    }
    printf("Total Nodes = %d", count);
}

void Search(){
    int s, f=0;
    if(head==NULL){
        printf("List Not Exist\n");
    }else{
        printf("Enter Elelemt to search: ");
        scanf("%d", &s);
        temp = head;
        while(temp!=NULL){
            if(temp->data==s){
                f=1;
                break;
            }
            temp = temp->next;
        }
    }
    if(f==1){
        printf("\n!!!Target Found!!!\n");
    }else{
        printf("\n!!!Target NOT Found!!!\n");
        
    }
}

void Create(){
    int n;
    char ch;
    printf("\nEnter Element: ");
    scanf("%d",&n);
    head=(struct node *)malloc(sizeof(struct node));
    head -> data=n;
    head->next=NULL;
    head->prev=NULL;
    temp=head;
    printf("\nWant to add More? y=YES | n=NO: ");
    scanf(" %c", &ch); // Added space before %c to skip white space characters
    while (ch == 'y' || ch == 'Y') {
        printf("\nEnter Next Element: ");
        scanf("%d", &n);
        new = (struct node *)malloc(sizeof(struct node));
        new->data = n;
        new->next = NULL;
        new->prev=temp;
        temp->next = new;
        temp = temp->next;
        printf("\nWant to add More? y=YES | n=NO: ");
        scanf(" %c", &ch); // Added space before %c to skip white space characters
    }
}

void Display(){
    if (head == NULL) {
        printf("\nList Not Exist\n");
    } else {
        temp = head;
        while (temp != NULL) {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void Insert_First(){
    int n;
     if (head == NULL) {
        printf("\nList Not Exist\n");
    } else {
        printf("Enter Elelemt: ");
        scanf("%d",&n);
        new = (struct node *)malloc(sizeof(struct node));
        new->data=n;
        new->next=NULL;
        new->prev=NULL;
        new->next=head;
        head=new;
    }
}

void Insert_Last(){
    int n;
    if(head == NULL){
        printf("\nList Not Exist\n");
    }else{
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }

        printf("Enter Elelemt: ");
        scanf("%d",&n);
        new = (struct node *)malloc(sizeof(struct node));
        new->data=n;
        new->next=NULL;
        new->prev=temp;   
        temp->next=new;
    }
}

void Insert_Middle(){
     int n, pos, i=0;
    if(head == NULL){
        printf("\nList Not Exist\n");
    }else{
        printf("Enter Element: ");
        scanf("%d",&n);
        new=(struct node *)malloc(sizeof(struct node));
        new->data=n;
        new->next=NULL;
        new->prev=NULL;
        printf("Enter Position: ");
        scanf("%d",&pos);
        right=head;
        while(i<pos-1){
            left=right;
            right=right->next;
            i++;
        }
        left->next=new;
        new->prev=left;
        new->next=right;
        right->prev=new;
    }
}

void Delete_First(){
    if(head == NULL){
        printf("\nList Not Exist\n");
    } else {
        temp = head;
        head=head->next;
        printf("Deleted: %d", temp->data);
        free(temp);
    }
}

void Delete_Last(){
    if(head == NULL){
        printf("\nList Not Exist\n");
    }else{
        temp=head;
        while(temp->next!=NULL){
            left=temp;
            temp=temp->next;
        }
        
        left->next=NULL;
        printf("Deleted: %d", temp->data);
        free(temp);
    }
}

void Delete_Middle(){
    int pos, i=0;
     if(head == NULL){
        printf("\nList Not Exist\n");
    }else{
        printf("Enter Position to DELETE: ");
        scanf("%d",&pos);
        right=head;
        while(i<pos){
            left=right;
            right=right->next;
            i++;
        }
        temp = left;
        left=left->prev;
        printf("Deleted: %d",temp->data);
        free(temp);
        left->next=right;
        right->prev=left;
    }
}