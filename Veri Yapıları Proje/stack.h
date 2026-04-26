#ifndef STACK_H
#define STACK_H

typedef struct {
    int items[100];
    int top;
} Stack;

void initStack(Stack* s);
void push(Stack* s, int value);
int pop(Stack* s);
int isStackEmpty(Stack* s);

#endif