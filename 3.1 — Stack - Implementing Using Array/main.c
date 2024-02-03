#include <stdio.h>
#include <stdlib.h>

// Define a structure for the stack
struct Stack {
    int size;
    int top;
    int *arr;
};

// Function to check if the stack is empty
void isEmpty(struct Stack *ptr) {
    if (ptr->top == -1) {
        printf("The stack is empty.\n");
        return;
    }
    printf("The stack is not empty.\n");
}

// Function to check if the stack is full
void isFull(struct Stack *ptr) {
    if (ptr->top == (ptr->size - 1)) {
        printf("The stack is full.\n");
        return;
    }
    printf("The stack is not full.\n");
}

int main() {
    // Structure 1
    struct Stack *s = (struct Stack *) malloc(sizeof(struct Stack));
    if (s == NULL) {
        printf("Memory allocation failed\nexiting...");
        return 1;
    }

    // Initialize values for structure 1
    s->size = 100;
    s->top = -1;
    s->arr = (int *) malloc(s->size * sizeof(int));
    if (s->arr == NULL) {
        printf("Memory allocation failed\nexiting...");
        free(s->arr);
        free(s);
        return 1;
    }

    printf("Structure s where s->size = %d, s->top = %d\n", s->size, s->top);
    isFull(s);
    isEmpty(s);

    // Structure 2
    struct Stack *s1 = (struct Stack *) malloc(sizeof(struct Stack));
    if (s1 == NULL) {
        printf("Memory allocation failed\nexiting...");
        free(s->arr);
        free(s);
        return 1;
    }

    // Initialize values for structure 2
    s1->size = 5;
    s1->top = -1;
    s1->arr = (int *) malloc(s1->size * sizeof(int));
    if (s1->arr == NULL) {
        printf("Memory allocation failed\nexiting...");
        free(s1->arr);
        free(s1);
        return 1;
    }

    // Assign values to the array in structure 2
    for (int i = 0; i < s1->size; i++) {
        s1->arr[i] = i;
        s1->top++;
    }

    printf("Structure s1 where s1->size = %d, s1->top = %d\n", s1->size, s1->top);
    isFull(s1);
    isEmpty(s1);

    // Free allocated memory
    free(s->arr);
    free(s);
    free(s1->arr);
    free(s1);
    return 0;
}
