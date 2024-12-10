#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
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
        printf("\n----------Circular Linked-List----------\n");
        printf("1. Create\n2. Display  \n3. Insert_First \n4. Insert_Last\n5. Insert_Middle\n6. Delete_First \n7. Delete_Last \n8. Delete_Middle \n9. Count \n10. Search \n00. Exit\n");
        printf("\n----------------------------------------\n");
        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: Create(); break;
            case 2: Display(); break;
            case 3: Insert_First(); break;
            case 4: Insert_Last(); break;
            case 5: Insert_Middle(); break;
            case 6: Delete_First(); break;
            case 7: Delete_Last(); break;
            case 8: Delete_Middle(); break;
            case 9: Count(); break;
            case 10: Search(); break;
        }
    } while (choice != 00);
}

void Create() {
    int n;
    char ch;
    printf("\nEnter Element: ");
    scanf("%d", &n);
    start = (struct node *)malloc(sizeof(struct node));
    start->data = n;
    start->next = start;
    temp = start;
    printf("\nWant to add More? y=YES | n=NO: ");
    scanf(" %c", &ch);
    while (ch == 'y' || ch == 'Y') {
        printf("Enter Next Element: ");
        scanf("%d", &n);
        new = (struct node *)malloc(sizeof(struct node));
        new->data = n;
        new->next = start;
        temp->next = new;
        temp = temp->next;
        printf("\nWant to add More? y=YES | n=NO: ");
        scanf(" %c", &ch);
    }
}

void Display() {
    if (start == NULL) {
        printf("\nList Not Exist\n");
    } else {
        temp = start;
        do {
            printf("%d\t", temp->data);
            temp = temp->next;
        } while (temp != start);
        printf("\n");
    }
}

void Insert_First() {
    int n;
    if (start == NULL) {
        printf("\nList Not Exist\n");
    } else {
        printf("Enter Element: ");
        scanf("%d", &n);
        new = (struct node *)malloc(sizeof(struct node));
        new->data = n;
        new->next = start;
        temp = start;
        while (temp->next != start) {
            temp = temp->next;
        }
        temp->next = new;
        start = new;
    }
}

void Insert_Last() {
    int n;
    if (start == NULL) {
        printf("\nList Not Exist\n");
    } else {
        printf("Enter Element: ");
        scanf("%d", &n);
        new = (struct node *)malloc(sizeof(struct node));
        new->data = n;
        new->next = start;
        temp = start;
        while (temp->next != start) {
            temp = temp->next;
        }
        temp->next = new;
    }
}

void Insert_Middle() {
    int n, pos, i = 1;
    if (start == NULL) {
        printf("\nList Not Exist\n");
    } else {
        printf("Enter Element: ");
        scanf("%d", &n);
        new = (struct node *)malloc(sizeof(struct node));
        new->data = n;
        new->next = NULL;
        printf("Enter Position: ");
        scanf("%d", &pos);
        temp = start;
        while (i < pos - 1 && temp->next != start) {
            temp = temp->next;
            i++;
        }
        new->next = temp->next;
        temp->next = new;
    }
}

void Delete_First() {
    if (start == NULL) {
        printf("\nList Not Exist\n");
    } else {
        temp = start;
        while (temp->next != start) {
            temp = temp->next;
        }
        temp = start;
        start = start->next;
        next = temp;
        while (next->next != temp) {
            next = next->next;
        }
        next->next = start;
        printf("Deleted Node: %d", temp->data);
        free(temp);
    }
}

void Delete_Last() {
    if (start == NULL) {
        printf("\nList Not Exist\n");
    } else {
        temp = start;
        while (temp->next->next != start) {
            temp = temp->next;
        }
        next = temp->next;
        temp->next = start;
        printf("Deleted Node: %d", next->data);
        free(next);
    }
}

void Delete_Middle() {
    int pos, i = 1;
    if (start == NULL) {
        printf("\nList Not Exist\n");
    } else {
        printf("Enter Position: ");
        scanf("%d", &pos);
        temp = start;
        while (i < pos - 1 && temp->next != start) {
            temp = temp->next;
            i++;
        }
        next = temp->next;
        temp->next = next->next;
        printf("Deleted Node: %d", next->data);
        free(next);
    }
}

void Count() {
    int count = 0;
    if (start != NULL) {
        temp = start;
        do {
            count++;
            temp = temp->next;
        } while (temp != start);
    }
    printf("Total Nodes = %d\n", count);
}

void Search() {
    int s, f = 0;
    if (start == NULL) {
        printf("List Not Exist\n");
    } else {
        printf("Enter Element to search: ");
        scanf("%d", &s);
        temp = start;
        do {
            if (temp->data == s) {
                f = 1;
                break;
            }
            temp = temp->next;
        } while (temp != start);
    }
    if (f == 1) {
        printf("\n!!!Target Found!!!\n");
    } else {
        printf("\n!!!Target NOT Found!!!\n");
    }
}
