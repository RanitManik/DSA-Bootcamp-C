#include <stdio.h>
#include <stdlib.h>

// Define the structure for a Stack node
struct Stack {
    int data;
    struct Stack *next;
};

// Function prototypes
void displayList(struct Stack *head);

int isEmpty(struct Stack *head);

int isFull(struct Stack *head);

struct Stack *push(struct Stack *head, int value);

struct Stack *pop(struct Stack *head);

void peek(struct Stack *head, int peekPosition);

void displayPeekedStack(struct Stack *ptr);

void StackTop(struct Stack *ptr);

void StackBottom(struct Stack *ptr);

void freeStack(struct Stack *head);

// Function to display the elements of the stack as a list
void displayList(struct Stack *head) {
    printf("\nPrinting the data of the stack as a list\n");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to check if the stack is empty
int isEmpty(struct Stack *head) {
    return (head == NULL);
}

// Function to check if the stack is full
int isFull(struct Stack *head) {
    struct Stack *ptr = (struct Stack *) malloc(sizeof(struct Stack));
    int full = (ptr == NULL);
    free(ptr);
    return full;
}

// Function to display the top element of the stack
void StackTop(struct Stack *ptr) {
    if (ptr != NULL) {
        printf("\nThe StackTop is %d\n", ptr->data);
    } else {
        printf("\nThe stack is empty.\n");
    }
}

// Function to display the bottom element of the stack
void StackBottom(struct Stack *ptr) {
    while (ptr != NULL && ptr->next != NULL) {
        ptr = ptr->next;
    }

    if (ptr != NULL) {
        printf("\nThe StackBottom is %d\n", ptr->data);
    } else {
        printf("\nThe stack is empty.\n");
    }
}

// Function to push a new element onto the stack
struct Stack *push(struct Stack *head, int value) {
    if (isFull(head)) {
        printf("Stack Overflow!\n");
    } else {
        struct Stack *ptr = (struct Stack *) malloc(sizeof(struct Stack));
        ptr->data = value;
        ptr->next = head;
        head = ptr;
    }
    return head;
}

// Function to pop an element from the stack
struct Stack *pop(struct Stack *head) {
    if (!isEmpty(head)) {
        struct Stack *temp = head;
        // head and temp pointers initially share the same memory address
        // But modifying temp won't affect head in main

        head = head->next;
        free(temp);
    } else {
        printf("Stack Underflow! Can't pop an empty stack.\n");
    }

    return head;
}

// Function to peek at a specific position in the stack
void peek(struct Stack *head, int peekPosition) {
    struct Stack *ptr = head;
    for (int i = 0; i < peekPosition - 1 && ptr != NULL; i++) {
        ptr = ptr->next;
    }
    if (ptr != NULL) {
        printf("The data at position %d is %d\n", peekPosition, ptr->data);
    }
}

// Function to display all elements of the stack through peeking
void displayPeekedStack(struct Stack *ptr) {
    for (int i = 1; ptr != NULL; i++) {
        peek(ptr, i);
    }
}

// Function to free the allocated memory for the entire stack
void freeStack(struct Stack *head) {
    while (head != NULL) {
        struct Stack *temp = head;
        head = head->next;
        free(temp);
    }
}

// Main function
int main() {
    // Initialize stack nodes
    struct Stack *top = NULL;

    // Push a new element onto the stack
    top = push(top, 42);
    top = push(top, 245);
    top = push(top, 52);
    top = push(top, 422);
    top = push(top, 45);
    top = push(top, 752);

    // Display the stack
    displayList(top);

    // Pop an element from the stack
    top = pop(top);
    displayList(top);

    // Push another element onto the stack
    top = push(top, 12);
    displayList(top);

    // Display the StackBottom and StackTop
    StackBottom(top);
    StackTop(top);

    // Peek at a specific position in the stack
    peek(top, 2);

    // Display all elements of the stack through peeking
    displayPeekedStack(top);

    // Free allocated memory
    freeStack(top);

    return 0;
}