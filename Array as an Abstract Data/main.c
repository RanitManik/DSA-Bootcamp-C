#include <stdio.h>
#include <stdlib.h>

struct myArray
{
    int totalSize, usedSize;
    int *ptr;
};

// function to create array
void createArray(struct myArray *a, int total_size, int used_size)
{
    // (*a).totalSize = total_size;
    // (*a).usedSize = used_size;
    // (*a).ptr = (int *)malloc(total_size * sizeof(int));

    a->totalSize = total_size;
    a->usedSize = used_size;
    a->ptr = (int *)malloc(total_size * sizeof(int));
}

// function to scan the elements of the array
void setVal(struct myArray *a)
{
    int n;
    printf("We are running setval now...");
    printf("\n");
    for (int i = 0; i < a->usedSize; i++)
    {
        printf("Enter the elements of %d th element ==> ", i);
        scanf("%d", &n);
        (a->ptr)[i] = n;
    }
}

// function to show all the elements of the array
void show(struct myArray *a)
{
    printf("We are running show now...");
    printf("\n");
    for (int i = 0; i < a->usedSize; i++)
    {
        printf("%d\n", (a->ptr)[i]);
    }
}

// main function
int main()
{
    struct myArray marks;
    createArray(&marks, 10, 2);
    setVal(&marks);
    show(&marks);
    return 0;
}