#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

// Function to display the linked list
void displayLinkedList(struct Node *head) {
    struct Node *current = head;
    int i = 0;

    // Iterate through the linked list and print each element
    while (current != NULL) {
        printf("The %d element of the structure is %d\n", i, current->data);
        current = current->next;
        i++;
    }

    printf("\n");
}

// Function to display the linked list in reverse
void displayReverseLinkedList(struct Node *head) {
    struct Node *current = head;
    int i = 0;

    // Move to the last element of the linked list
    while (current->next != NULL) {
        current = current->next;
        i++;
    }

    // Iterate through the linked list in reverse and print each element
    while (current != NULL) {
        printf("The %d element of the structure is %d\n", i, current->data);
        current = current->prev;
        i--;
    }

    printf("\n");
}

int main() {
    // Allocate memory for each node
    struct Node *head = (struct Node *) malloc(sizeof(struct Node));
    struct Node *second = (struct Node *) malloc(sizeof(struct Node));
    struct Node *third = (struct Node *) malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *) malloc(sizeof(struct Node));

    // Initialize data and next pointers for each node
    head->prev = NULL;
    head->data = 15;
    head->next = second;

    second->prev = head;
    second->data = 25;
    second->next = third;

    third->prev = second;
    third->data = 35;
    third->next = fourth;

    fourth->prev = third;
    fourth->data = 45;
    fourth->next = NULL;

    // Display the linked list
    printf("Printing the Linked List before insertion...\n");
    displayLinkedList(head);

    // Display the reverse linked list
    printf("Printing the reversed Linked List before insertion...\n");
    displayReverseLinkedList(head);

    // Free the allocated memory for each node
    free(head);
    free(second);
    free(third);
    free(fourth);

    return 0;
}
