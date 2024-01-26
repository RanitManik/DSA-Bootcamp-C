#include <stdio.h>
#include <stdlib.h> // Include the necessary header file for malloc

struct Node
{
    int data;
    struct Node *next;
};

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;

    // Allocate memory for each Nodes in Linked List
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    // Check if memory allocation was successful
    if (head == NULL || second == NULL || third == NULL)
    {
        printf("Memory allocation failed. Exiting...\n");

        // Free allocated memory before exiting
        free(head);
        free(second);
        free(third);

        return 1; // Return an error code
    }

    // Link Head and first nodes
    head->data = 7;
    head->next = second;

    // Link first and second nodes
    second->data = 11;
    second->next = third;

    // Link second and third nodes
    third->data = 66;
    third->next = NULL;

    // Your code is now correctly allocating memory and linking nodes

    // Don't forget to free the allocated memory when you are done using the linked list
    free(head);
    free(second);
    free(third);

    return 0;
}
