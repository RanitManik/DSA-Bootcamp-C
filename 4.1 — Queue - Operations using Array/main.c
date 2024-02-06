#include <stdio.h>
#include <stdlib.h>

// Queue structure definition
struct Queue {
    int size;  // Size of the queue
    int f;     // Front pointer
    int r;     // Rear pointer
    int *arr;  // Array to store elements
};

// Function to check if the queue is full
int isFull(struct Queue *q) {
    return q->r == q->size - 1;
}

// Function to check if the queue is empty
int isEmpty(struct Queue *q) {
    return q->r == q->f;
}

// Function to add an element to the queue
void enqueue(struct Queue *queue, int value) {
    if (isFull(queue)) {
        printf("This queue is Full\n");
    } else {
        // Increment rear before assignment
        queue->arr[++queue->r] = value;
    }
}

// Function to remove an element from the queue
void dequeue(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("The queue is Empty\n");
    } else {
        // Increment front to dequeue
        ++queue->f;
    }
}

// Function to print the elements in the queue
void printQueue(struct Queue *q) {
    for (int i = q->f + 1; i <= q->r; i++) {
        printf("%d ", q->arr[i]);
    }
}

int main() {
    // Create a queue dynamically
    struct Queue *q = (struct Queue *) malloc(sizeof(struct Queue));
    q->size = 100;
    q->f = q->r = -1;
    q->arr = (int *) malloc(q->size * sizeof(int));

    // Check if the queue is empty
    if (isEmpty(q)) {
        printf("The queue is empty...\n");
    }

    // Enqueue few elements
    for (int i = 0; i < 100; i++) {
        enqueue(q, i);
    }

    // Print the elements in the queue
    printQueue(q);

    // Check if the queue is full
    if (isFull(q)) {
        printf("\nThe queue is Full...\n");
    }

    // Dequeue few elements
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);

    // Print the elements in the queue after dequeue
    printQueue(q);

    // Free the memory allocated for the queue
    free(q->arr);
    free(q);
    return 0;
}
