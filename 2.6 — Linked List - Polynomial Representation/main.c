#include <stdio.h>
#include <stdlib.h>

struct node {
    float coeff;
    int expo;
    struct node* link;
};

struct node* insert(struct node* head, float co, int ex) {
    struct node* temp;
    struct node* newP = (struct node*)malloc(sizeof(struct node));
    newP->coeff = co;
    newP->expo = ex;
    newP->link = NULL;

    if (head == NULL || ex > head->expo) {
        newP->link = head;
        head = newP;
    } else {
        temp = head;
        while (temp->link != NULL && temp->link->expo >= ex) {
            temp = temp->link;
        }
        newP->link = temp->link;
        temp->link = newP;
    }

    return head;
}

int main() {
    struct node* head = NULL;
    int n;
    
    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        float co;
        int ex;
        
        printf("Enter coefficient for term %d: ", i + 1);
        scanf("%f", &co);
        
        printf("Enter exponent for term %d: ", i + 1);
        scanf("%d", &ex);

        head = insert(head, co, ex);
    }

    // Print the resulting polynomial
    struct node* current = head;
    while (current != NULL) {
        printf("Coefficient: %.2f, Exponent: %d\n", current->coeff, current->expo);
        current = current->link;
    }

    return 0;
}