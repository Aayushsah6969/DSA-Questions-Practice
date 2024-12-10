#include <stdio.h>

struct employees {
    char name[50];
    int age;
    char address[100];
};

int main() {
    struct employees emp;

    printf("Enter details of employees: \n");
    printf("Enter name: ");
    scanf("%49[^\n]", emp.name); // Read string with spaces
    getchar(); // Clear the input buffer

    printf("Enter age: ");
    scanf("%d", &emp.age);

    printf("Enter address: ");
    scanf("%99[^\n]", emp.address); // Read string with spaces
    getchar(); // Clear the input buffer

    printf("Details are: Name=%s, Age=%d, Address=%s\n", emp.name, emp.age, emp.address);

    return 0;
}
