#include <stdio.h> //array transversal
int main() {
 int arr[5]={1,2,3,4,5};
 printf("%d\n",arr[2]);
 printf("%d\n", sizeof(arr));
 printf("%d\n", sizeof(arr[0]));
 for(int i=0; i<5; i++){
    printf("%d\t", arr[i]);
 }
    return 0;
}