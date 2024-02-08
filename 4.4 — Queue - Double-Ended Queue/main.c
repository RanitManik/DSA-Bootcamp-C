#include <stdio.h>
#include <stdlib.h>

// Deque structure definition
struct Deque {
    int size;  // Size of the deque
    int front; // Front pointer
    int rear;  // Rear pointer
    int *arr;  // Array to store elements
};

// Function to check if the deque is full
int isFull(struct Deque *deque) {
    return (deque->rear == deque->size - 1 && deque->front == 0) || (deque->rear + 1 == deque->front);
}

// Function to check if the deque is empty
int isEmpty(struct Deque *deque) {
    return deque->front == -1;
}

// Function to add an element to the front of the deque
void insertFront(struct Deque *deque, int value) {
    if (isFull(deque)) {
        printf("The deque is Full\n");
    } else {
        if (deque->front == -1) {
            deque->front = deque->rear = 0;
        } else if (deque->front == 0) {
            deque->front = deque->size - 1;
        } else {
            deque->front--;
        }
        deque->arr[deque->front] = value;
    }
}

// Function to add an element to the rear of the deque
void insertRear(struct Deque *deque, int value) {
    if (isFull(deque)) {
        printf("The deque is Full\n");
    } else {
        if (deque->front == -1) {
            deque->front = deque->rear = 0;
        } else if (deque->rear == deque->size - 1) {
            deque->rear = 0;
        } else {
            deque->rear++;
        }
        deque->arr[deque->rear] = value;
    }
}

// Function to remove an element from the front of the deque
void deleteFront(struct Deque *deque) {
    if (isEmpty(deque)) {
        printf("The deque is Empty\n");
    } else {
        if (deque->front == deque->rear) {
            deque->front = deque->rear = -1;
        } else if (deque->front == deque->size - 1) {
            deque->front = 0;
        } else {
            deque->front++;
        }
    }
}

// Function to remove an element from the rear of the deque
void deleteRear(struct Deque *deque) {
    if (isEmpty(deque)) {
        printf("The deque is Empty\n");
    } else {
        if (deque->front == deque->rear) {
            deque->front = deque->rear = -1;
        } else if (deque->rear == 0) {
            deque->rear = deque->size - 1;
        } else {
            deque->rear--;
        }
    }
}

// Function to print the elements in the deque
void printDeque(struct Deque *deque) {
    if (isEmpty(deque)) {
        printf("The deque is empty\n");
    } else {
        printf("Deque elements: ");
        int i = deque->front;
        do {
            printf("%d ", deque->arr[i]);
            i = (i + 1) % deque->size;
        } while (i != (deque->rear + 1) % deque->size);
        printf("\n");
    }
}

int main() {
    // Create a deque dynamically
    struct Deque *deque = (struct Deque *) malloc(sizeof(struct Deque));
    deque->size = 100;
    deque->front = deque->rear = -1;
    deque->arr = (int *) malloc(deque->size * sizeof(int));

    // Check if the deque is empty
    if (isEmpty(deque)) {
        printf("The deque is empty\n");
    }

    // Insert elements at the front and rear of the deque
    insertFront(deque, 1);
    insertRear(deque, 2);
    insertFront(deque, 3);
    insertRear(deque, 4);

    // Print the elements in the deque
    printDeque(deque);

    // Delete elements from the front and rear of the deque
    deleteFront(deque);
    deleteRear(deque);

    // Print the elements in the deque after deletion
    printDeque(deque);

    // Free the memory allocated for the deque
    free(deque->arr);
    free(deque);
    return 0;
}
