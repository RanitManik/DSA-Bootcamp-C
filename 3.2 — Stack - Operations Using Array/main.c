#include <stdio.h>
#include <stdlib.h>

// Structure to represent a stack
struct Stack {
    int size;
    int top;
    int *arr;
};

// Function prototypes
void displayStack(struct Stack *ptr);

void push(struct Stack *s, int value);

void pop(struct Stack *s);

void peek(struct Stack *s, int peekPosition);

void displayPeekedStack(struct Stack *ptr);

void StackTop(struct Stack *ptr);

void StackBottom(struct Stack *ptr);


// Function to display the elements of the stack
void displayStack(struct Stack *ptr) {
    if (ptr->top != -1) {
        for (int i = 0; i <= ptr->top; i++) {
            printf("%d ", ptr->arr[i]);
        }
        printf("\n");
    } else {
        printf("empty stack...");
    }
}

// Function to push an element onto the stack
void push(struct Stack *s, int value) {
    if (s->size - 1 > s->top) {
        s->top++;
        s->arr[s->top] = value;
        return;
    }
    printf("Stack Overflow...");
}

// Function to pop an element from the stack
void pop(struct Stack *s) {
    if (s->top > -1) {
        s->top--;
        return;
    }
    printf("Stack Underflow...");
}

// Function to peek at an element in the stack
void peek(struct Stack *s, int peekPosition) {
    if (peekPosition > 0 && peekPosition <= s->top + 1) {
        printf("peeking value of stack at position %d is %d\n", peekPosition, s->arr[s->top - (peekPosition - 1)]);
        return;
    }
    printf("\nInvalid position or empty stack");
}

// Function to display each element of the stack using peek
void displayPeekedStack(struct Stack *ptr) {
    if (ptr->top != -1) {
        for (int i = 1; i <= ptr->top + 1; i++) {
            peek(ptr, i);
        }
    } else {
        printf("empty stack...\n");
    }
}

// Function to display the top element of the stack
void StackTop(struct Stack *ptr) {
    if (ptr->top != -1) {
        printf("The StackTop of the stack is %d\n", ptr->arr[ptr->top]);
        return;
    }
    printf("empty stack");
}

// Function to display the bottom element of the stack
void StackBottom(struct Stack *ptr) {
    if (ptr->top != -1) {
        printf("The StackBottom of the stack is %d\n", ptr->arr[0]);
    }
    printf("empty stack");
}

int main() {
    // Initialize the stack
    struct Stack *stack1 = (struct Stack *) malloc(sizeof(struct Stack));
    stack1->size = 15;
    stack1->top = -1;
    stack1->arr = (int *) malloc(stack1->size * sizeof(int));

    // Fill the stack with initial values
    for (int i = 0; i < (stack1->size) - 2; i++) {
        stack1->top++;
        stack1->arr[i] = i;
    }

    // Display the stack before any operation
    printf("\nDisplay the stack before any operation\n");
    displayStack(stack1);
    displayPeekedStack(stack1);
    StackTop(stack1);
    peek(stack1, 8);

    // Push an element onto the stack
    push(stack1, 13);
    printf("\nDisplay the stack after push operation\n");
    displayStack(stack1);
    displayPeekedStack(stack1);
    StackTop(stack1);
    peek(stack1, 8);

    // Pop elements from the stack
    pop(stack1);
    pop(stack1);
    printf("\nDisplay the stack after pop operation\n");
    displayStack(stack1);
    displayPeekedStack(stack1);
    StackTop(stack1);
    peek(stack1, 8);

    // Free allocated memory for the stack
    free(stack1->arr);
    free(stack1);
    return 0;
}
