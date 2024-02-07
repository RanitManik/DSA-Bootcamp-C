#include <stdio.h>
#include <stdlib.h>

struct Queue {
    struct Node *front;
    struct Node *rear;
};

struct Node {
    int data;
    struct Node *next;
};

// Function to create an empty queue
struct Queue *createQueue() {
    struct Queue *q = (struct Queue *) malloc(sizeof(struct Queue));
    if (q == NULL) {
        printf("Queue creation failed: Memory allocation error\n");
        exit(1);
    }
    q->front = q->rear = NULL;
    return q;
}

// Function to check if the queue is empty
int isEmpty(struct Queue *q) {
    return q->front == NULL;
}

// Function to add an element to the rear of the queue
void enqueue(struct Queue *q, int value) {
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Enqueue operation failed: Memory allocation error\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    if (isEmpty(q)) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Function to remove an element from the front of the queue
int dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Dequeue operation failed: Queue is empty\n");
        exit(1);
    }
    struct Node *temp = q->front;
    int value = temp->data;
    q->front = q->front->next;
    free(temp);
    if (q->front == NULL) {
        q->rear = NULL;
    }
    return value;
}

// Function to print the elements of the queue
void printQueue(struct Queue *q) {
    printf("Queue elements: ");
    struct Node *current = q->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to deallocate memory for the queue nodes
void freeQueue(struct Queue *q) {
    struct Node *current = q->front;
    while (current != NULL) {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }
    free(q);
}

int main() {
    struct Queue *q = createQueue();

    // Enqueue elements to the queue
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    // Print the elements of the queue
    printQueue(q);

    // Dequeue elements from the queue and print them
    printf("Dequeued elements: ");
    while (!isEmpty(q)) {
        printf("%d ", dequeue(q));
    }
    printf("\n");

    // Free memory allocated for the queue
    freeQueue(q);

    return 0;
}
