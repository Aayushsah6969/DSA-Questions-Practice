#include <stdio.h>
#include <math.h>

// Function to perform jump search
int jumpSearch(int arr[], int n, int key) {
    // Calculate the jump size
    int step = sqrt(n);

    // Initialize variables for current and previous steps
    int prev = 0;
    int curr = step;

    // Jumping ahead to find the block where the key may be present
    while (arr[curr] < key && curr < n) {
        prev = curr;
        curr += step;
    }

    // Perform linear search in the current block
    for (int i = prev; i <= curr && i < n; i++) {
        if (arr[i] == key)
            return i; // Element found
    }

    return -1; // Element not found
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 11;

    int index = jumpSearch(arr, n, key);

    if (index != -1)
        printf("Element %d found at index %d\n", key, index);
    else
        printf("Element %d not found in the array\n", key);

    return 0;
}
