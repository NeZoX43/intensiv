
#include "stack.h"

#include <stdlib.h>

struct stack* init(int capacity) {
    struct stack* s = (struct stack*)malloc(sizeof(struct stack));
    s->data = (int*)malloc(capacity * sizeof(int));
    s->top = -1;
    s->capacity = capacity;
    return s;
}

int push(struct stack* s, int value) {
    if (s->top == s->capacity - 1) {
        return 0;
    }
    s->top++;
    s->data[s->top] = value;
    return 1;
}

int pop(struct stack* s) {
    if (s->top == -1) {
        return 0;
    }
    int value = s->data[s->top];
    s->top--;
    return value;
}

void destroy(struct stack* s) {
    free(s->data);
    free(s);
}