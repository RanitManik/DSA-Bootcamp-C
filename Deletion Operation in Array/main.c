#include <stdio.h>

// Function Prototypes
void inputArray(int size, int array[size]);
void displayArray(int size, int array[size]);
void deleteIndex(int *size, int capacity, int array[*size], int indexDelete);

// Function Definitions

// Function to take inputs of the array
void inputArray(int size, int array[size])
{
    for (int i = 0; i < size; i++)
    {
        printf("Enter value of the array element at index %d: ", i);
        scanf("%d", &array[i]);
    }
}

// Function to display the array
void displayArray(int size, int array[size])
{
    printf("{");
    for (int i = 0; i < size; i++)
    {
        printf(" %d", array[i]);
        if (i != size - 1)
        {
            printf(",");
        }
    }
    printf(" }\n");
}

// Function to delete an element at an index
void deleteIndex(int *size, int capacity, int array[*size], int indexDelete)
{
    if (indexDelete < 0 || indexDelete >= *size)
    {
        printf("Error: Index out of bounds\n");
        return;
    }

    for (int i = indexDelete; i < (*size - 1); i++)
    {
        array[i] = array[i + 1];
    }
    (*size)--;
}

// main function
int main()
{
    int size, capacity, indexDelete;

    printf("Enter the capacity of the array: ");
    scanf("%d", &capacity);

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size > capacity)
    {
        printf("Error: Capacity must be greater than or equal to the size of the array\n");
        return -1;
    }

    int array[size];

    printf("\nEnter the elements of the array now...\n");
    inputArray(size, array);

    printf("\nThe original array is: ");
    displayArray(size, array);

    printf("\nEnter the index of the array you want to delete: ");
    scanf("%d", &indexDelete);

    if (indexDelete < 0 || indexDelete >= size)
    {
        printf("Error: Index of deletion element must be between 0 and %d\n", size - 1);
        return -1;
    }

    deleteIndex(&size, capacity, array, indexDelete);

    printf("\nThe array after deletion of its index at %d is: ", indexDelete);
    displayArray(size, array);

    return 0;
}
