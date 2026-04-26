#include <stdio.h>
#include "queue.h"

#define MAX 100

void initQueue(Queue* q) {
    q->front = 0;
    q->rear = 0;
}

void enqueue(Queue* q, int value) {
    if (q->rear < MAX) {
        q->items[q->rear++] = value;
    }
}

int dequeue(Queue* q) {
    if (q->front < q->rear) {
        return q->items[q->front++];
    }
    return -1; // hata durumu
}

int isEmpty(Queue* q) {
    return q->front == q->rear;
}