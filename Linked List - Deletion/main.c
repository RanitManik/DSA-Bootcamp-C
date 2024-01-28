#include <stdio.h>
#include <stdlib.h>

// Define the structure for a Node
struct Node {
    int data;
    struct Node *next;
};

// Function prototypes
void displayLinkedList(struct Node *head);

struct Node *deleteNodeAtBeginning(struct Node *head);

struct Node *deleteNodeAtMiddle(struct Node *head, int targetIndex);

struct Node *deleteAfterNode(struct Node *head, struct Node *previousNode);

struct Node *deleteNodeAtEnd(struct Node *head);


// Function to display the linked list
void displayLinkedList(struct Node *head) {
    if (head == NULL) {
        printf("The Linked List is empty.\n");
        return;
    }

    int count = 0;
    struct Node *current = head;

    while (current != NULL) {
        printf("Node at index %d has data: %d\n", count, current->data);
        current = current->next;
        count++;
    }
}

// Function to delete a node at the beginning of the linked list
struct Node *deleteNodeAtBeginning(struct Node *head) {
    if (head == NULL) {
        printf("Cannot delete from an empty list.\n");
        return NULL;
    }

    struct Node *newHead = head->next;
    free(head);
    return newHead;
}

// Function to delete a node at a specified index in the linked list
struct Node *deleteNodeAtMiddle(struct Node *head, int targetIndex) {
    if (head == NULL) {
        printf("Cannot delete from an empty list.\n");
        return NULL;
    }

    struct Node *current = head;
    struct Node *previous = NULL;
    int currentIndex = 0;

    while (current != NULL && currentIndex < targetIndex) {
        previous = current;
        current = current->next;
        currentIndex++;
    }

    if (current == NULL) {
        printf("Invalid index for deletion.\n");
        return head;
    }

    if (previous == NULL) {
        // Deleting the first node
        head = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);
    return head;
}

// Function to delete a node after a specified node in the linked list
struct Node *deleteAfterNode(struct Node *head, struct Node *previousNode) {
    if (head == NULL || previousNode == NULL || previousNode->next == NULL) {
        printf("Invalid operation for deletion.\n");
        return head;
    }

    struct Node *toBeDeleted = previousNode->next;
    previousNode->next = toBeDeleted->next;
    free(toBeDeleted);
    return head;
}

// Function to delete a node at the end of the linked list
struct Node *deleteNodeAtEnd(struct Node *head) {
    if (head == NULL) {
        printf("Cannot delete from an empty list.\n");
        return NULL;
    }

    struct Node *current = head;
    struct Node *previous = NULL;

    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }

    if (previous == NULL) {
        // Deleting the only node
        free(head);
        return NULL;
    }

    previous->next = NULL;
    free(current);
    return head;
}


int main() {
    // Create nodes for the linked list
    struct Node *head = NULL;
    struct Node *second = NULL;
    struct Node *third = NULL;
    struct Node *fourth = NULL;
    struct Node *fifth = NULL;

    // Allocate memory for each node
    head = (struct Node *) malloc(sizeof(struct Node));
    second = (struct Node *) malloc(sizeof(struct Node));
    third = (struct Node *) malloc(sizeof(struct Node));
    fourth = (struct Node *) malloc(sizeof(struct Node));
    fifth = (struct Node *) malloc(sizeof(struct Node));

    // Check if memory allocation is successful
    if (head == NULL || second == NULL || third == NULL || fourth == NULL || fifth == NULL) {
        printf("Dynamic memory allocation failed...\n");
        return EXIT_FAILURE;
    }

    // Initialize data and links between nodes
    head->data = 15;
    head->next = second;

    second->data = 25;
    second->next = third;

    third->data = 45;
    third->next = fourth;

    fourth->data = 65;
    fourth->next = fifth;

    fifth->data = 75;
    fifth->next = NULL;

    // Display the original linked list
    printf("\nPrinting the original Linked List\n");
    displayLinkedList(head);

    // Delete a node at the beginning and display the modified linked list
    head = deleteNodeAtBeginning(head);
    printf("\nPrinting the Linked List after deletion at the beginning\n");
    displayLinkedList(head);

    // Delete a node at a specified index and display the modified linked list
    head = deleteNodeAtMiddle(head, 2);
    printf("\nPrinting the Linked List after deletion at middle\n");
    displayLinkedList(head);

    // Delete a node after a given node and display the modified linked list
    struct Node *nodeAfter = second;  // Choose a node after which deletion will occur
    head = deleteAfterNode(head, nodeAfter);
    printf("\nPrinting the Linked List after deletion after a given node\n");
    displayLinkedList(head);

    // Delete a node at the end and display the modified linked list
    head = deleteNodeAtEnd(head);
    printf("\nPrinting the Linked List after deletion at the end\n");
    displayLinkedList(head);

    // Free the memory for each node
    free(head);
    free(second);
    free(third);
    free(fourth);
    free(fifth);

    return 0;
}
