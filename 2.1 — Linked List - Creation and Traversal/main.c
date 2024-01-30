#include <stdio.h>
#include <stdlib.h>

// Define the structure for a Node in a linked list
struct Node
{
    int data;
    struct Node *next;
};

// Function to traverse and print elements in the linked list
void LinkedListTraversal(struct Node *ptr)
{
    int count = 1;

    // Traverse the linked list until the end is reached
    while (ptr != NULL)
    {
        // Print the data of the current node along with its position
        printf("Node %d is: %d\n", count, ptr->data);

        // Move to the next node in the linked list
        ptr = ptr->next;

        // Increment the count for the next element
        count++;
    }
}

int main()
{
    // Declare pointers for the head and individual nodes of the linked list
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for each node in the linked list
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Check if memory allocation is successful
    if (head == NULL || second == NULL || third == NULL)
    {
        printf("Dynamic memory allocation failed. Exiting the program...");
        return -1;
    };

    // Initialize data and next pointers for each node
    head->data = 7;
    head->next = second;

    second->data = 75;
    second->next = third;

    third->data = 50;
    third->next = fourth;

    fourth->data = 43;
    fourth->next = NULL;

    // Call the function to traverse and print elements in the linked list
    LinkedListTraversal(head);

    // Free allocated memory for each node
    free(head);
    free(second);
    free(third);
    free(fourth);

    return 0;
}
