#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function to find the maximum element in the array
int maximum(int A[], int n) {
    int max = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (max < A[i]) {
            max = A[i];
        }
    }
    return max;
}

// Function to perform counting sort on the array
void countSort(int A[], int n) {
    // Find the maximum element in the array
    int max = maximum(A, n);

    // Create a count array to store the frequency of each element
    int *count = (int *) malloc((max + 1) * sizeof(int));

    // Initialize the count array elements to zero
    for (int i = 0; i <= max; i++) {
        count[i] = 0;
    }

    // Increment the count for each element in the array
    for (int i = 0; i < n; i++) {
        count[A[i]]++;
    }

    // Reconstruct the sorted array using the count array
    int i = 0;
    for (int j = 0; j <= max; j++) {
        while (count[j] > 0) {
            A[i++] = j;
            count[j]--;
        }
    }

    // Free the dynamically allocated memory
    free(count);
}

// Function to print the elements of an array
void printArray(int A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main() {
    // Example usage of counting sort
    int A[] = {4, 32, 5, 2, 6, 1, 4, 1};
    int n = sizeof(A) / sizeof(A[0]);

    printf("Original Array: ");
    printArray(A, n);

    countSort(A, n);

    printf("Sorted Array: ");
    printArray(A, n);

    return 0;
}
