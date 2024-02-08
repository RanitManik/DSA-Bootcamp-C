#include <stdio.h>

// Function to display the elements of an array
void displayArray(int array[], int size) {
    printf("\nThe array is:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Function to perform Selection Sort
void SelectionSort(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int max_index = i;
        for (int j = i + 1; j < size; j++) {
            if (array[j] < array[max_index]) {
                max_index = j;
            }
        }
        // Swap the maximum element with the current element
        int temp = array[i];
        array[i] = array[max_index];
        array[max_index] = temp;
    }
}

int main() {
    // Array to be sorted
    int array[] = {2, 5, 78, 1, 48, 45, 47, 62};
    int size = sizeof(array) / sizeof(int);

    // Display the original array
    displayArray(array, size);

    // Perform Selection Sort
    SelectionSort(array, size);

    // Display the array after sorting
    displayArray(array, size);

    return 0;
}
