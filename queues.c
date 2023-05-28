#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

void enqueue(struct Queue* queue, int item) {
    if (queue->rear == MAX_SIZE - 1) {
        printf("Queue is full\n");
        return;
    }
    queue->items[++queue->rear] = item;
}

int dequeue(struct Queue* queue) {
    if (queue->front == queue->rear) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue->items[++queue->front];
}

int main() {
    struct Queue queue;
    queue.front = -1;
    queue.rear = -1;

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    printf("%d dequeued from the queue\n", dequeue(&queue));
    printf("%d dequeued from the queue\n", dequeue(&queue));
    printf("%d dequeued from the queue\n", dequeue(&queue));
    printf("%d dequeued from the queue\n", dequeue(&queue));

    return 0;
}

