#include<stdio.h>
void sort(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main(){
    int size;
    printf("Enter size of your array: ");
    scanf("%d",&size);
    int arr[size];
    printf("Enter data in array: ");
    for( int i =0; i<size; i++){
        printf("Enter element %d: ",i);
        scanf("%d",&arr[i]);
    }
    printf("Your array is: \n");
     for(  int i =0; i<size; i++){
        printf("%d\t",arr[i]);
    }

   // Bubble sort algorithm
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                sort(&arr[j], &arr[j + 1]);
            }
        }
    }
printf("Array after sorting: \n");
 for( int i =0; i<size; i++){
        printf("%d\t",arr[i]);
    }
    return 0;
}