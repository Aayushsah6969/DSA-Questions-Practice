//jump search

#include<stdio.h>
#include<math.h>
int search(int arr[], int n, int key){
int step = sqrt(n);
int prev = 0;
int curr = step;
while(arr[curr]<key && curr<n){
    prev = curr;
    curr = curr + step;
}
for(int i=0; i<=curr && i<n; i++){
    if(arr[i]==key){
        return i;
    }
}
return -1;
}

int main(){

    int arr[]={1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 13;
    int index = search(arr, n, key);

 if (index != -1)
        printf("Element %d found at index %d\n", key, index);
    else
        printf("Element %d not found in the array\n", key);

    return 0;
}