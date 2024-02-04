#include <stdio.h>
#include <stdlib.h>

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
        return '\0'; // Return null character if stack is empty
    }
}

// Function to check if the stack is empty
int isEmpty(struct Stack *ptr) {
    return ptr->top == -1;
}

// Function to check if parentheses match
int match(char open, char close) {
    return (open == '(' && close == ')') || (open == '{' && close == '}') || (open == '[' && close == ']');
}

// Function to check for balanced parentheses in an expression
int parenthesisMatching(char *exp) {
    struct Stack *sp = (struct Stack *) malloc(sizeof(struct Stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *) malloc(sp->size * sizeof(char));
    char popped_ch;

    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(sp, exp[i]);
        } else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (isEmpty(sp)) {
                free(sp->arr);
                free(sp);
                return 0; // Unbalanced expression
            } else {
                popped_ch = pop(sp);
                if (!match(popped_ch, exp[i])) {
                    free(sp->arr);
                    free(sp);
                    return 0; // Mismatched parentheses
                }
            }
        }
    }

    int result = isEmpty(sp);

    // Free the allocated memory for the stack
    free(sp->arr);
    free(sp);

    return result;
}

// Function to print whether an expression is balanced or unbalanced
void isBalanced(char *arr) {
    if (parenthesisMatching(arr)) {
        printf("The expression is a Balanced Expression\n");
    } else {
        printf("The expression is an Unbalanced Expression\n");
    }
}

int main() {
    char *expression1 = "2/75*48(";
    char *expression2 = "(3*5) [+ 7 - (2/4)";
    char *expression3 = "[(a + b) }* c - (d / e)";
    char *expression4 = "{{[[((1 + 2) * {[3 / 4]} - 5]})]}";

    isBalanced(expression1);
    isBalanced(expression2);
    isBalanced(expression3);
    isBalanced(expression4);

    return 0;
}
