#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "door_struct.h"

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

void initialize_doors(struct door* doors);

int main() {
#if BUILD == 1
    struct door doors[DOORS_COUNT];
    initialize_doors(doors);
#else
    printf("n/a");
#endif

    return 0;
}

void initialize_doors(struct door* doors) {
    srand(time(0));

    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
    int as;
    for (int i = 0; i < DOORS_COUNT; i++) {
        for (int j = 0; j < DOORS_COUNT - 1; j++) {
            if (doors[j].id > doors[j + 1].id) {
                as = doors[j].id;
                doors[j].id = doors[j + 1].id;
                doors[j + 1].id = as;
            }
        }
    }
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].status = 0;
    }
    for (int i = 0; i < DOORS_COUNT; i++) {
        printf("%d, %d\n", doors[i].id, doors[i].status);
    }
}
