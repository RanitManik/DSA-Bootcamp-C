#include <stdio.h>
#include <stdlib.h>

// CircularQueue structure definition
typedef struct {
    int size;  // Maximum size of the queue
    int front; // Index of the front element
    int rear;  // Index of the rear element
    int *arr;  // Array to store elements
} CircularQueue;

// Function to create a new circular queue
CircularQueue *createCircularQueue(int size) {
    CircularQueue *queue = (CircularQueue *) malloc(sizeof(CircularQueue));
    if (queue == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        exit(EXIT_FAILURE);
    }
    queue->size = size;
    queue->front = queue->rear = -1;
    queue->arr = (int *) malloc(size * sizeof(int));
    if (queue->arr == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        exit(EXIT_FAILURE);
    }
    return queue;
}

// Function to check if the circular queue is empty
int isEmpty(CircularQueue *queue) {
    return queue->front == -1;
}

// Function to check if the circular queue is full
int isFull(CircularQueue *queue) {
    return (queue->rear + 1) % queue->size == queue->front;
}

// Function to enqueue an element into the circular queue
void enqueue(CircularQueue *queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full. Enqueue operation failed.\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % queue->size;
    }
    queue->arr[queue->rear] = value;
}

// Function to dequeue an element from the circular queue
int dequeue(CircularQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Dequeue operation failed.\n");
        return -1; // Return a sentinel value indicating failure
    }
    int value = queue->arr[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % queue->size;
    }
    return value;
}

// Function to print the elements in the circular queue
void printQueue(CircularQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    int i = queue->front;
    do {
        printf("%d ", queue->arr[i]);
        i = (i + 1) % queue->size;
    } while (i != (queue->rear + 1) % queue->size);
    printf("\n");
}

// Function to free memory allocated for the circular queue
void freeCircularQueue(CircularQueue *queue) {
    free(queue->arr);
    free(queue);
}

int main() {
    // Create a circular queue of size 10
    CircularQueue *queue = createCircularQueue(10);

    // Enqueue elements
    for (int i = 1; i <= 10; i++) {
        enqueue(queue, i * 10);
    }

    // Print the queue
    printQueue(queue);

    // Dequeue elements
    for (int i = 0; i < 5; i++) {
        dequeue(queue);
    }

    // Print the queue after dequeue
    printQueue(queue);

    // Enqueue more elements
    for (int i = 11; i <= 15; i++) {
        enqueue(queue, i * 10);
    }

    // Print the final queue
    printQueue(queue);

    // Free the memory allocated for the queue
    freeCircularQueue(queue);

    return 0;
}
