//to delete value from array
#include <stdio.h>
int find(int size, int arr[], int delvalue){
    int i;
    for(i = 0; i < size; i++){
        if(arr[i] == delvalue){
            return i;
        }
    }
    return -1;
}

void delete(int size, int arr[], int delvalue){
    int delIndex = find(size, arr, delvalue);
    int i;
    if(delIndex == -1){
        printf("Element not found!!");
    }else{
        for(i = delIndex; i < size - 1; i++){
            arr[i] = arr[i + 1];
        }
        size--; // Decrease the size of the array
    }
    printf("Array after deletion:\n");
    for(i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
}

int main() {
    int size, i, arr[100], delvalue;
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
    printf("\nEnter the value you want to delete: ");
    scanf("%d", &delvalue);
    delete(size, arr, delvalue);
    return 0;
}
