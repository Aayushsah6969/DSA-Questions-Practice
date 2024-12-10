//binary searching
#include <stdio.h>

int search(int arr[], int low, int high, int key){
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]==key){
            return mid;
        }else if(key>arr[mid]){
            low = mid+1;
        }else{
            high = mid -1;
        }
    }
    return 0;
}

int main() {
int arr[]={1,56,76,34,88,94,34,66};
int n = sizeof(arr)/sizeof(arr[0]);
printf("%d",n);
// printf("%d",n);
int key = 94;
int index = search(arr, 0, n-1, key);

 if(index != 0){
    printf("Key found at index %d ",index);
 }else{
    printf("Key not found!!");
 }
    return 0;
}