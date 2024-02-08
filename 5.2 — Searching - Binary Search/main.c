#include <stdio.h>

int BinarySearch(int array[], int target, int size) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = (high + low) / 2; // Calculate mid inside the loop

        if (array[mid] == target) {
            return mid; // Return index if target is found
        } else if (array[mid] < target) {
            low = mid + 1; // Update low to search in the right half
        } else {
            high = mid - 1; // Update high to search in the left half
        }
    }

    // If the loop completes without finding the target, return -1
    return -1;
}

int main() {
    int array[] = {2, 4, 5, 6, 7, 8, 9, 10, 12};
    int length = sizeof(array) / sizeof(int);
    int target = 5;
    int result = BinarySearch(array, target, length);
    if (result != -1) {
        printf("The target %d is found at index %d.\n", target, result);
    } else {
        printf("The target %d is not found in the array.\n", target);
    }
    return 0;
}
