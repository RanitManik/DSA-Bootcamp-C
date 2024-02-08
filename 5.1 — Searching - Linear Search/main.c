#include <stdio.h>

int LinearSearch(int array[], int target, int size) {
    for (int i = 0; i < size; i++) {
        if (array[i] == target) {
            return i; // Return the index if the target is found
        }
    }
    // If the loop completes without finding the target, return -1
    return -1;
}

int main() {
    int array[] = {2, 4, 5, 6, 7, 8, 9, 10, 12};
    int length = sizeof(array) / sizeof(int); // shorthand to calculate size of an array
    int target = 5;
    int result = LinearSearch(array, target, length);
    if (result != -1) {
        printf("The target %d is found at index %d.\n", target, result);
    } else {
        printf("The target %d is not found in the array.\n", target);
    }
    return 0;
}
