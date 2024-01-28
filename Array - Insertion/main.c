#include <stdio.h>

// Function prototypes
void inputArray(int size, int array[size]);
void display(int array[], int size);
void insert(int array[], int *size, int capacity, int indexInsert, int insertValue);

void inputArray(int size, int array[size])
{
    for (int i = 0; i < size; i++)
    {
        printf("Enter the %d index element of the array: ", i);
        scanf("%d", &array[i]);
    }
}

// Function to display an array
void display(int array[], int size)
{
    printf("{ ");

    // Traversal loop
    for (int i = 0; i < size; i++)
    {
        printf("%d", array[i]);
        if (i < size - 1)
        {
            printf(", ");
        }
    }

    printf(" }\n");
}

// Function to insert an element at a specific index
void insert(int array[], int *size, int capacity, int indexInsert, int insertValue)
{
    if (capacity <= *size)
    {
        printf("Sorry! Capacity must be greater than the size of the array. Exiting...\n");
    }
    else
    {
        // Shift elements to make space for the new element
        for (int i = *size - 1; i >= indexInsert; i--)
        {
            array[i + 1] = array[i];
        }

        // Insert the new element
        array[indexInsert] = insertValue;
        (*size)++;
    }
}

int main()
{
    // array properties
    int size, capacity, indexInsert, insertValue;

    printf("Enter an array capacity: ");
    scanf("%d", &capacity);

    printf("Enter an array size: ");
    scanf("%d", &size);

    int array[size];

    printf("Now You will be inputting the elements of the array...\n");
    inputArray(size, array);

    printf("\nThe array before insertion is:\n");
    display(array, size);

    printf("\nEnter the index of the element you want to insert: ");
    scanf("%d", &indexInsert);

    printf("Enter the value of the element you want to insert: ");
    scanf("%d", &insertValue);

    insert(array, &size, capacity, indexInsert, insertValue);

    printf("\nThe array after insertion of %d at index %d is:\n", insertValue, indexInsert);
    display(array, size);

    return 0;
}
