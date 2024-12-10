#include <stdio.h>
// Linear searching in array
int search(int size, int arr[], int key){
    for(int i=0; i<size; i++){
        if(arr[i]==key){
            return 1;
        }
    }
    return 0;
}
 
int main() {
 int size, i, arr[100], key;
    printf("Enter size of your array: ");
    scanf("%d", &size);
    printf("Enter elements in array: ");
    for(i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }
    printf("Your 1D array is:\n");
    for(i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\nEnter the value you want to search: ");
    scanf("%d", &key);
    int result =  search(size, arr, key);
   if(result == 1){
    printf("Value found!!");
   }else{printf("Value not found!!");}
    return 0;
}