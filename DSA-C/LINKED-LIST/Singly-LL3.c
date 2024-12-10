//singly linked list operations demnstration...
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *add;
};
struct node *start = NULL, *temp, *new, *prev, *next;

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

void main() {
    int choice;
    do {
        printf("\n----------Linked-List----------\n");
        printf("1. Create\n2. Display  \n3. Insert_First \n4. Insert_Last\n5. Insert_Middle\n6. Delete_First \n7. Delete_Last \n8. Delete_Middle \n9. Count \n10. Search \n00. Exit\n");
        printf("\n-------------------------------\n");
        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: Create();break;
            case 2: Display(); break;
            case 3: Insert_First(); break;
            case 4: Insert_Last(); break;
            case 5: Insert_Middle();break;
            case 6: Delete_First(); break;
            case 7: Delete_Last(); break;
            case 8: Delete_Middle(); break;
            case 9: Count(); break;
            case 10: Search();break;
                
        }
    } while (choice != 00);
    
}

void Count(){
    int count = 0;
    temp = start;
    while(temp!=NULL){
        count++ ;
        temp = temp->add;
    }
    printf("Total Nodes = %d", count);
}

void Search(){
    int s, f=0;
    if(start==NULL){
        printf("List Not Exist\n");
    }else{
        printf("Enter Elelemt to search: ");
        scanf("%d", &s);
        temp = start;
        while(temp!=NULL){
            if(temp->data==s){
                f=1;
                break;
            }
            temp = temp->add;
        }
    }
    if(f==1){
        printf("\n!!!Target Found!!!\n");
    }else{
        printf("\n!!!Target NOT Found!!!\n");
        
    }
}

void Create() {
    int n;
    char ch;
    printf("\nEnter Element: ");
    scanf("%d", &n);
    start = (struct node *)malloc(sizeof(struct node));
    start->data = n;
    start->add = NULL;
    temp = start;
    printf("\nWant to add More? y=YES | n=NO: ");
    scanf(" %c", &ch); // Added space before %c to skip white space characters
    while (ch == 'y' || ch == 'Y') {
        printf("Enter Next Element: ");
        scanf("%d", &n);
        new = (struct node *)malloc(sizeof(struct node));
        new->data = n;
        new->add = NULL;
        temp->add = new;
        temp = temp->add;
        printf("\nWant to add More? y=YES | n=NO: ");
        scanf(" %c", &ch); // Added space before %c to skip white space characters
    }
}

void Display() {
    if (start == NULL) {
        printf("\nList Not Exist\n");
    } else {
        temp = start;
        while (temp != NULL) {
            printf("%d\t", temp->data);
            temp = temp->add;
        }
        printf("\n");
    }
}

void Insert_First(){ int n;
    if(start == NULL){
        printf("\nList Not Exist\n");
    } else {
        printf("Enter Elelemt: ");
        scanf("%d", &n);
        new = (struct node *)malloc(sizeof(struct node));
        new -> data =n;
        // new->add=NULL;
        new->add=start;
        start = new;
    }
}

void Insert_Last(){
    int n;
    if(start == NULL){
        printf("\nList Not Exist\n");
    } else {
          printf("Enter Elelemt: ");
        scanf("%d", &n);
        new = (struct node *)malloc(sizeof(struct node));
        new -> data =n;
        new->add=NULL;
        temp = start;
        while(temp->add!=NULL){
            temp = temp->add;
        }
        temp->add=new;
    }
}

void Insert_Middle(){
    int n, pos, i=1;
    if(start == NULL){
        printf("\nList Not Exist\n");
    } else {
        printf("Enter Elelemt: ");
        scanf("%d", &n);
        new = (struct node *)malloc(sizeof(struct node));
        new -> data =n;
        new->add=NULL;
        printf("Enter Position: ");
        scanf("%d", &pos);
        next = start;
        while(i<pos){
            prev = next;
            next = next -> add;
            i++;
        }
        prev -> add = new;
        new ->add =next;
    }
}

void Delete_First(){
   if(start == NULL){
        printf("\nList Not Exist\n");
    } else {
        temp = start;
        start = start->add;
        printf("Deleted Node: %d", temp->data);
        free(temp);
    }
}

void Delete_Last(){
    if(start == NULL){
        printf("\nList Not Exist\n");
    } else {
        temp = start;
        while(temp->add!=NULL){
            prev = temp;
            temp = temp->add;
        }
        prev->add=NULL;
        printf("Deleted Node: %d", temp->data);
        free(temp);
    }
}

void Delete_Middle(){
    int pos, i=0;
    if(start == NULL){
        printf("\nList Not Exist\n");
    } else {
        printf("Enter Position: ");
        scanf("%d",&pos);
        temp = start;
        while(i<pos){
            prev = temp;
            temp=temp->add;
            i++;
        }
        next = temp->add;
        prev->add=next;
        printf("Deleted Node: %d", temp->data);
        free(temp);
    }
}