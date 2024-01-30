#include<stdio.h>
#include<stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node *next;
};

// Function to display the linked list
void displayLinkedList(struct Node *Head) {
    struct Node *ptr = Head;
    int i = 0;

    // Iterate through the linked list and print each element
    do {
        printf("The %d element of the structure is %d\n", i, ptr->data);
        ptr = ptr->next;
        i++;
    } while (ptr != Head);  // Use ptr != Head as the condition

    printf("\n");
}

// Function to display the linked list
struct Node *insertAtFirst(struct Node *Head, int data) {
    struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node *p = Head;
    do {
        p = p->next;
    } while (p->next != Head);

    ptr->next = Head;
    p->next = ptr;
    Head = ptr;  // Update the Head pointer

    return Head;
}


int main() {
    // Allocate memory for each node
    struct Node *head = (struct Node *) malloc(sizeof(struct Node));
    struct Node *second = (struct Node *) malloc(sizeof(struct Node));
    struct Node *third = (struct Node *) malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *) malloc(sizeof(struct Node));

    // Initialize data and next pointers for each node
    head->data = 15;
    head->next = second;

    second->data = 25;
    second->next = third;

    third->data = 35;
    third->next = fourth;

    fourth->data = 45;
    fourth->next = head;

    // Display the linked list
    printf("printing the Linked List before insertion... \n");
    displayLinkedList(head);

    // Insert at first of the linked list
    head = insertAtFirst(head, 5);

    // Display the linked list
    printf("printing the Linked List after insertion...\n");
    displayLinkedList(head);


    // Free the allocated memory for each node
    free(head);
    free(second);
    free(third);
    free(fourth);

    return 0;
}
