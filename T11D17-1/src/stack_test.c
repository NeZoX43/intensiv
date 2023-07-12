
#include "stack.h"

#include <stdio.h>

#define SUCCESS 0
#define FAIL 1

int test_push() {
    struct stack* s = init(5);
    push(s, 1);
    push(s, 2);
    push(s, 3);

    if (pop(s) != 3 || pop(s) != 2 || pop(s) != 1) {
        destroy(s);
        return FAIL;
    }

    destroy(s);
    return SUCCESS;
}

int test_pop() {
    struct stack* s = init(5);
    push(s, 1);
    push(s, 2);
    push(s, 3);

    if (pop(s) != 3 || pop(s) != 2 || pop(s) != 1) {
        destroy(s);
        return FAIL;
    }

    if (pop(s) != 0) {
        destroy(s);
        return FAIL;
    }

    destroy(s);
    return SUCCESS;
}

int main() {
    int push_result = test_push();
    int pop_result = test_pop();

    if (push_result == SUCCESS && pop_result == SUCCESS) {
        printf("SUCCESS\n");
        return SUCCESS;
    } else {
        printf("FAIL\n");
        return FAIL;
    }
}