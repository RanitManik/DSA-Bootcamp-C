#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Stack {
    int size;
    int top;
    char *arr;
};

// Function to push an element onto the stack
void push(struct Stack *s, char value) {
    if (s->top < s->size - 1) {
        s->top++;
        s->arr[s->top] = value;
    } else {
        printf("Stack Overflow...\n");
    }
}

// Function to pop an element from the stack
char pop(struct Stack *s) {
    if (s->top > -1) {
        return s->arr[s->top--];
    } else {
        printf("Stack Underflow...\n");
        return '\0'; // Return null character if the stack is empty
    }
}

// Check if a character is an operator
int isOperator(char a) {
    return a == '+' || a == '-' || a == '*' || a == '/';
}

// Get precedence of an operator
int precedence(char a) {
    if (a == '+' || a == '-') {
        return 1;
    } else if (a == '*' || a == '/') {
        return 2;
    } else {
        return 0;
    }
}

// Convert infix expression to postfix
char *infixToPostfix(char *infix) {
    struct Stack *sp = (struct Stack *) malloc(sizeof(struct Stack));
    sp->top = -1;
    sp->size = 100;
    sp->arr = (char *) malloc(sp->size * sizeof(char));
    char *postfix = (char *) malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0; // Track infix traversal
    int j = 0; // Track postfix traversal

    // Process each character in the infix expression
    while (infix[i] != '\0') {
        // If the character is an operand, add it to the postfix expression
        if (!isOperator(infix[i])) {
            postfix[j] = infix[i];
            i++;
            j++;
        } else if (sp->top == -1 || precedence(infix[i]) > precedence(sp->arr[sp->top])) {
            // If the stack is empty or current operator has higher precedence, push it onto the stack
            push(sp, infix[i]);
            i++;
        } else {
            // Pop operators from the stack and add to postfix until higher precedence is found
            postfix[j] = pop(sp);
            j++;
        }
    }

    // Pop remaining operators from the stack and add to postfix
    while (sp->top > -1) {
        postfix[j] = pop(sp);
        j++;
    }

    // Null-terminate the postfix expression
    postfix[j] = '\0';

    // Free allocated memory for the stack
    free(sp->arr);
    free(sp);

    return postfix;
}

int main() {
    char *infix = "a+b-c*d/e";
    char *postfix = infixToPostfix(infix);
    printf("Infix Expression: %s\n", infix);
    printf("Postfix Expression: %s\n", postfix);

    // Free allocated memory for the postfix expression
    free(postfix);

    return 0;
}
