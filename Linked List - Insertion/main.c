#include <stdio.h>
#include <stdlib.h>

// Define the structure for a Node
struct Node;

// Function prototypes
void displayLinkedList(struct Node *ptr);

struct Node *insertNodeAtBeginning(struct Node *head, int data);

struct Node *insertNodeAtMiddle(struct Node *head, int data, int insertIndex);

struct Node *insertAfterNode(struct Node *head, int data, struct Node *previousNode);

struct Node *insertNodeAtEnd(struct Node *head, int data);

// Node structure
struct Node {
    int data;
    struct Node *next;
};

// Function to display the linked list
void displayLinkedList(struct Node *ptr) {
    int count = 0;

    while (ptr != NULL) {
        printf("The data of Node at index %d is : %d\n", count, ptr->data);
        ptr = ptr->next;
        count++;
    }
}

// Function to insert a new node at the beginning of the linked list
struct Node *insertNodeAtBeginning(struct Node *head, int data) {
    struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    head = ptr;
    return head;
}

// Function to insert a new node at a specified index in the linked list
struct Node *insertNodeAtMiddle(struct Node *head, int data, int insertIndex) {
    struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;

    // Check if insertion is at the beginning
    if (insertIndex == 0) {
        ptr->next = head;
        return ptr;
    }

    struct Node *headCopy = head;
    int i = 0;

    // Traverse to the node before the specified index
    while (i < insertIndex - 1 && headCopy != NULL) {
        headCopy = headCopy->next;
        i++;
    }

    // Check if the specified index is valid
    if (headCopy == NULL) {
        printf("Invalid insertIndex\n");
        free(ptr);
        return head;
    }

    // Perform the insertion
    ptr->next = headCopy->next;
    headCopy->next = ptr;

    return head;
}

// Function to insert a new node after a specified node in the linked list
struct Node *insertAfterNode(struct Node *head, int data, struct Node *previousNode) {
    struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));

    // Initialize the new node
    ptr->data = data;
    ptr->next = previousNode->next;

    // Update the next pointer of the previous node
    previousNode->next = ptr;

    return head;
}

// Function to insert a new node at the end of the linked list
struct Node *insertNodeAtEnd(struct Node *head, int data) {
    struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node *ptrCopy = head;

    // Traverse to the end of the linked list
    while (ptrCopy->next != NULL) {
        ptrCopy = ptrCopy->next;
    }

    // Perform the insertion at the end
    ptrCopy->next = ptr;
    ptr->next = NULL;

    return head;
}


int main() {
    // Create nodes for the linked list
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fifth;

    // Allocate memory for each node
    head = (struct Node *) malloc(sizeof(struct Node));
    second = (struct Node *) malloc(sizeof(struct Node));
    third = (struct Node *) malloc(sizeof(struct Node));
    fourth = (struct Node *) malloc(sizeof(struct Node));
    fifth = (struct Node *) malloc(sizeof(struct Node));

    // Check if memory allocation is successful
    if (head == NULL || second == NULL || third == NULL || fourth == NULL || fifth == NULL) {
        printf("Dynamic memory allocation Failed...");
        return 1;
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
    printf("\nPrinting The original Linked List\n");
    displayLinkedList(head);

    // Insert a new node at the beginning and display the modified linked list
    struct Node *newHead = insertNodeAtBeginning(head, 5);
    printf("\nPrinting The Linked List after insertion at Beginning\n");
    displayLinkedList(newHead);

    // Insert a new node at a specified index and display the modified linked list
    newHead = insertNodeAtMiddle(newHead, 35, 3);
    printf("\nPrinting The Linked List after insertion at Middle\n");
    displayLinkedList(newHead);

    // Insert a new node after a given node
    newHead = insertAfterNode(newHead, 55, third);
    printf("\nPrinting The Linked List after insertion after a given node\n");
    displayLinkedList(newHead);

    // Insert a new node at the end and display the modified linked list
    newHead = insertNodeAtEnd(newHead, 85);
    printf("\nPrinting The Linked List after insertion at End\n");
    displayLinkedList(newHead);


    // Free the memory for each node
    free(head);
    free(second);
    free(third);
    free(fourth);
    free(fifth);
    free(newHead);

    return 0;
}
