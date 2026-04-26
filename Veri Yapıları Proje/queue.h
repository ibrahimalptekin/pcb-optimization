#ifndef QUEUE_H
#define QUEUE_H

typedef struct {
    int items[100];
    int front;
    int rear;
} Queue;

void initQueue(Queue* q);
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
int isEmpty(Queue* q);

#endif