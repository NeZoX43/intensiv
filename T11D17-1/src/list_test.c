
#include "list.h"

#include <assert.h>
#include <stdio.h>

#define SUCCESS 0
#define FAIL 1

int test_add_door() {
    struct door doors[3];
    struct node* root = init(&doors[0]);

    add_door(root, &doors[1]);
    add_door(root, &doors[2]);

    assert(root->next->door == &doors[2]);
    assert(root->next->next->door == &doors[1]);
    assert(root->next->next->next == NULL);

    destroy(root);
    return SUCCESS;
}

int test_remove_door() {
    struct door doors[3];
    struct node* root = init(&doors[0]);
    struct node* door1_node = add_door(root, &doors[1]);
    struct node* door2_node = add_door(root, &doors[2]);

    root = remove_door(door1_node, root);
    assert(root->next == door2_node);
    assert(root->next->next == NULL);

    destroy(root);
    return SUCCESS;
}

int main() {
    int result = SUCCESS;
    result |= test_add_door();
    if (result == SUCCESS) {
        printf("First add door test passed.\n");
    } else {
        printf("First add door test failed.\n");
    }

    result |= test_remove_door();
    if (result == SUCCESS) {
        printf("Second remove door test passed.\n");
    } else {
        printf("Second remove door test failed.\n");
    }

    return result;
}
