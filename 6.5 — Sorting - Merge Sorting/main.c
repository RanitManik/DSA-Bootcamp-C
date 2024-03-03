#include <stdio.h>

// Function to merge two sorted sub-arrays arr[low..mid] and arr[mid+1..high]
void merge(int A[], int low, int mid, int high) {
    int i, j, k;
    int B[100]; // Temporary array to store merged sub-arrays

    i = low;     // Starting index of the first subarray
    j = mid + 1; // Starting index of the second subarray
    k = low;     // Starting index of the merged array

    // Merge the two sub-arrays into the temporary array B
    while ((i <= mid) && (j <= high)) {
        if (A[i] < A[j]) {
            B[k] = A[i];
            i++;
        } else {
            B[k] = A[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of the first subarray, if any
    while (i <= mid) {
        B[k] = A[i];
        i++;
        k++;
    }

    // Copy the remaining elements of the second subarray, if any
    while (j <= high) {
        B[k] = A[j];
        j++;
        k++;
    }

    // Copy the merged elements back to the original array A
    for (i = low; i <= high; i++) {
        A[i] = B[i];
    }
}

// Function to perform merge sort on the array A
void mergeSort(int A[], int low, int high) {
    int mid;

    // Check if there are more than one element in the array
    if (low < high) {
        mid = (low + high) / 2; // Calculate the middle index

        // Recursively sort the first and second halves
        mergeSort(A, low, mid);
        mergeSort(A, mid + 1, high);

        // Merge the sorted halves
        merge(A, low, mid, high);
    }
}

int main() {
    int A[] = {12, 11, 13, 5, 6, 7}; // Example array for testing
    int size = sizeof(A) / sizeof(A[0]);

    // Print the given array
    printf("Given array is \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    // Perform merge sort on the array
    mergeSort(A, 0, size - 1);

    // Print the sorted array
    printf("Sorted array is \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}
