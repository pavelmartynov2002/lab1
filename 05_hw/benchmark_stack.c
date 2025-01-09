#include <stdio.h>
#include <time.h>
#include "stack.h"

void benchmarkPushPop() {
    Stack stack;
    initStack(&stack);

    clock_t start = clock();
    for (int i = 0; i < 1000000; ++i) {
        push(&stack, i);
    }
    for (int i = 0; i < 1000000; ++i) {
        pop(&stack);
    }
    clock_t end = clock();
    printf("Push and Pop 1,000,000 elements: %lf seconds\n",
        (double)(end - start) / CLOCKS_PER_SEC);

    destroyStack(&stack);
}

int main() {
    benchmarkPushPop();
    return 0;
}
