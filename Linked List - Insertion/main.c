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
    head = insertNodeAtBeginning(head, 5);
    printf("\nPrinting The Linked List after insertion at Beginning\n");
    displayLinkedList(head);

    // Insert a new node at a specified index and display the modified linked list
    head = insertNodeAtMiddle(head, 35, 3);
    printf("\nPrinting The Linked List after insertion at Middle\n");
    displayLinkedList(head);

    // Insert a new node after a given node
    head = insertAfterNode(head, 55, third);
    printf("\nPrinting The Linked List after insertion after a given node\n");
    displayLinkedList(head);

    // Insert a new node at the end and display the modified linked list
    head = insertNodeAtEnd(head, 85);
    printf("\nPrinting The Linked List after insertion at End\n");
    displayLinkedList(head);

    // Free the memory for each node
    free(head);
    free(second);
    free(third);
    free(fourth);
    free(fifth);

    return 0;
}
