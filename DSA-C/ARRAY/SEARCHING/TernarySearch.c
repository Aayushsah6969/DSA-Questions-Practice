#include <stdio.h>

// Function to perform ternary search
int ternarySearch(int arr[], int left, int right, int key) {
    if (right >= left) {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;

        if (arr[mid1] == key)
            return mid1;

        if (arr[mid2] == key)
            return mid2;

        if (key < arr[mid1])
            return ternarySearch(arr, left, mid1 - 1, key);

        if (key > arr[mid2])
            return ternarySearch(arr, mid2 + 1, right, key);

        return ternarySearch(arr, mid1 + 1, mid2 - 1, key);
    }
    return -1; // Return -1 if key is not found
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 5;
    int index = ternarySearch(arr, 0, n - 1, key);

    if (index != -1)
        printf("Element %d found at index %d\n", key, index);
    else
        printf("Element %d not found in the array\n", key);

    return 0;
}
