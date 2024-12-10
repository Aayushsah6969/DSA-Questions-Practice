//ternary search by dividing the given array into three equal halves...
#include <stdio.h>

int search(int arr[], int left, int right, int key){
    if(right>=left){
        int mid1=(2*left+right)/3;
        int mid2 = (2*right+left)/3;

        if(key==arr[mid1]){
            return mid1;
        }else if(key==arr[mid2]){
            return mid2;
        }else if(key<arr[mid1]){
            return search(arr, left, mid1-1, key);
        }else if(key>arr[mid2]){
            return search(arr, mid2+1, right, key);
        }else{
            return search(arr, mid1+1, mid2-1, key);
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