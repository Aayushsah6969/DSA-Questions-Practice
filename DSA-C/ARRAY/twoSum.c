#include<stdio.h>

int main(){
    int arr[]={2, 7, 8, 9, 10, 11};
    int target = 9;
    int n = sizeof(arr)/sizeof(arr[0]);
    find(arr, target, n);
}

int find(int arr[], int target, int n){
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n-1; j++){
            if(arr[i]+arr[j]==target){
                printf("%d + %d = %d\n", arr[i], arr[j], target);
                return 0;
            }
        }
    }
}