#include "stack.h"

#define MAX 100

void initStack(Stack* s) {
    s->top = -1;
}

void push(Stack* s, int value) {
    if (s->top < MAX - 1) {
        s->items[++s->top] = value;
    }
}

int pop(Stack* s) {
    if (s->top >= 0) {
        return s->items[s->top--];
    }
    return -1; // hata durumu
}

int isStackEmpty(Stack* s) {
    return s->top == -1;
}