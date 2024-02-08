#include <stdio.h>

void displayArray(int array[], int size) {
    printf("\nThe array is:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void InsertionSort(int array[], int n) {
    for (int i = 1; i <= n - 1; i++) {
        int key = array[i];
        int j = i - 1;

        // Shift elements greater than key to the right
        while (j >= 0 && array[j] < key) {
            array[j + 1] = array[j];
            j--;
        }

        // Place key in its correct position
        array[j + 1] = key;
    }
}

int main() {
    int array[] = {2, 5, 78, 1, 48, 45, 47, 62};
    int size = sizeof(array) / sizeof(int);

    // Display the original array
    displayArray(array, size);

    // Perform Insertion Sort
    InsertionSort(array, size);

    // Display the array after Insertion Sort
    displayArray(array, size);

    return 0;
}
