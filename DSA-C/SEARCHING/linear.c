#include <stdio.h>

int main() {
    int pos = -1;  // Initialize pos to -1 to indicate value not found
    int value = 67;
    int array[] = {12, 45, 32, 67, 65, 67, 100, 23, 47, 68};
    int n = sizeof(array) / sizeof(array[0]);  // Calculate the number of elements in array

    // Search for value in array
    for (int i = 0; i < n; i++) {
        if (array[i] == value) {
            pos = i;  // Update position if value is found
            break;    // Exit loop since value is found
        }
    }

    // Check if value was found and print result
    if (pos != -1) {
        printf("Value %d found at position: %d\n", value, pos);
    } else {
        printf("Value %d not found in the array.\n", value);
    }

    return 0;
}
