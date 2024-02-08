#include <stdio.h>

void displayArray(int array[], int size) {
    printf("\nThe array is:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void BubbleSort(int array[], int size) {
    // No of passes
    for (int i = 0; i < size - 1; i++) {
        // Flag to check if any swap is made in this pass
        int swapped = 0;
        // Comparisons in each pass
        for (int j = 0; j < size - 1 - i; j++) {
            if (array[j] > array[j + 1]) {
                // Swap elements if they are in the wrong order
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swapped = 1; // Set swap flag
            }
        }
        // If no swap occurred in this pass, array is sorted
        if (swapped == 0)
            break;
    }
}

int main() {
    int array[] = {150, 2, 53, 46, 75, 26, 74, 58, 10, 95};
    int size = sizeof(array) / sizeof(int);

    // Printing the array before sorting
    displayArray(array, size);

    // Sorting the array
    BubbleSort(array, size);

    // Printing the array after sorting
    displayArray(array, size);

    return 0;
}
