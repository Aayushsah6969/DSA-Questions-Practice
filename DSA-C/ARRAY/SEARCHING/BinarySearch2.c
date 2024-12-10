//binary search => only works with sorted array...
#include <stdio.h>

int search(int arr[], int low, int high, int key){
    while(low<=high){
    int mid = (high+low)/2;
        if(arr[mid]==key){
            return mid;
        }else if(key>arr[mid]){
            low = mid+1;
        }else{
            high = mid -1;
        }
    }
    return -1;
}

int main() {
    int size,i, key;
printf("Enter array size: ");
scanf("%d", &size);
int arr[size];
for( i=0; i<size; i++ ){
    printf("Enter value at %d: ",i);
    scanf("%d", &arr[i]);
}
printf("Your 1D array is: \n");
for(i=0; i<size; i++){
    printf("%d\t", arr[i]);
}
printf("\nEnter the key u want to search: ");
scanf("%d", &key);
int index = search(arr, 0, size-1, key);
if(index != -1){
    printf("we found the key at index: %d",index);
}else{
    printf("Key not found!!");
}
    return 0;
}