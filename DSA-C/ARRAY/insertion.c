//array insertion
#include <stdio.h>

// Function to insert element at a specific position
void insertElement(int arr[], int n, int x, int pos) {
    // Shift elements to the right which are on the right side of pos
    for (int i = n ; i >= pos; i--) {
        arr[i + 1] = arr[i];
    }

    arr[pos] = x;
}

int main() {
    int arr[100], size, newValue, insertIndex;

    // Input the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Input array elements
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; ++i) {
        scanf("%d", &arr[i]);
    }

    // Input the index and value to insert
    printf("Enter the index at which you want to insert the new value: ");
    scanf("%d", &insertIndex);
    printf("Enter the new value to insert: ");
    scanf("%d", &newValue);

    // Check if index is valid
    if (insertIndex < 0 || insertIndex > size) {
        printf("Invalid index.\n");
        return 1;
    }

    // Call insertElement function
    insertElement(arr, size, newValue, insertIndex);

    // Increment the size of the array
    size++;

    // Print the updated array
    printf("Array after insertion:\n");
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
