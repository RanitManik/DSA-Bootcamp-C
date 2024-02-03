#include<stdio.h>
#include<stdlib.h>

struct Stack {
    int size;
    int top;
    int *arr;
};

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

void push(struct Stack *s, int value) {
    if (s->size - 1 > s->top) {
        s->top++;
        s->arr[s->top] = value;
        return;
    }
    printf("Stack Overflow...");
}

void pop(struct Stack *s) {
    if (s->top > -1) {
        s->top--;
        return;
    }
    printf("Stack Underflow...");
}

void peak(struct Stack *s, int peakIndex) {
    if (s->top != -1) {
        printf("\nvalue of stack at index %d is %d\n", peakIndex, s->arr[peakIndex]);
        return;
    }
    printf("empty Stack");
}

int main() {
    struct Stack *stack1 = (struct Stack *) malloc(sizeof(struct Stack));
    stack1->size = 15;
    stack1->top = -1;
    stack1->arr = (int *) malloc(stack1->size * sizeof(int));

    for (int i = 0; i < (stack1->size) - 2; i++) {
        stack1->top++;
        stack1->arr[i] = i;
    }

    printf("\nDisplay the stack before any operation\n");
    displayStack(stack1);

    push(stack1, 13);
    printf("\nDisplay the stack after push operation\n");
    displayStack(stack1);

    pop(stack1);
    pop(stack1);
    printf("\nDisplay the stack after pop operation\n");
    displayStack(stack1);

    peak(stack1, 5);

    free(stack1->arr);
    free(stack1);
    return 0;
}