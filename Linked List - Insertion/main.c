#include <stdio.h>
#include <stdlib.h>

struct Node;
void displayLinkedList(struct Node *ptr);
struct Node *insertNodeAtBeginning(struct Node *head, int data);

struct Node
{
    int data;
    struct Node *next;
};

void displayLinkedList(struct Node *ptr)
{
    int count = 1;

    while (ptr->next != NULL)
    {
        printf("The element at Node %d is : %d\n", count, ptr->data);
        ptr = ptr->next;
        count++;
    }
}

struct Node *insertNodeAtBeginning(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;

    return ptr;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fifth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    fifth = (struct Node *)malloc(sizeof(struct Node));

    if (head == NULL || second == NULL || third == NULL || fourth == NULL || fifth == NULL)
    {
        printf("Dynamic memory allocation Failed...");
        return -1;
    }

    head->data = 15;
    head->next = second;

    second->data = 25;
    second->next = third;

    third->data = 35;
    third->next = fourth;

    fourth->data = 45;
    fourth->next = fifth;

    fifth->data = 55;
    fifth->next = NULL;

    printf("printing The original Linked List...\n");
    displayLinkedList(head);


    head = insertNodeAtBeginning(head, 5);
    printf("\nprinting The Linked List after insertion at Beginning\n");
    displayLinkedList(head);

    free(head);
    free(second);
    free(third);
    free(fourth);
    free(fifth);

    return 0;
}