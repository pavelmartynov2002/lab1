#include <stdio.h>
#include <assert.h>
#include "stack.h"

static void test_initStack() {
    printf("TEST: initStack\n");
    Stack s;
    initStack(&s);
    assert(s.top == NULL);
    printf("  => initStack OK\n");
    destroyStack(&s);
}

static void test_push() {
    printf("TEST: push\n");
    Stack s;
    initStack(&s);

    push(&s, 10);
    push(&s, 20);
    assert(s.top->data == 20);
    assert(s.top->next->data == 10);

    printf("  => push OK\n");
    destroyStack(&s);
}

static void test_pop() {
    printf("TEST: pop\n");
    Stack s;
    initStack(&s);

    push(&s, 1);
    push(&s, 2);
    pop(&s); // removes 2
    assert(s.top->data == 1);

    pop(&s); // removes 1
    assert(s.top == NULL);

    printf("  => pop OK\n");
    destroyStack(&s);
}

static void test_searchByValue() {
    printf("TEST: searchByValue\n");
    Stack s;
    initStack(&s);

    push(&s, 100);
    push(&s, 200);
    push(&s, 300);

    Node* found = searchByValue(&s, 200);
    assert(found != NULL && found->data == 200);

    Node* notFound = searchByValue(&s, 999);
    assert(notFound == NULL);

    printf("  => searchByValue OK\n");
    destroyStack(&s);
}

static void test_searchByIndex() {
    printf("TEST: searchByIndex\n");
    Stack s;
    initStack(&s);

    push(&s, 100);
    push(&s, 200);
    push(&s, 300);

    // Top - 300 (index 0)
    Node* idx0 = searchByIndex(&s, 0);
    assert(idx0->data == 300);

    Node* idx1 = searchByIndex(&s, 1);
    assert(idx1->data == 200);

    Node* idx2 = searchByIndex(&s, 2);
    assert(idx2->data == 100);

    Node* idxFail = searchByIndex(&s, 3);
    assert(idxFail == NULL);

    printf("  => searchByIndex OK\n");
    destroyStack(&s);
}

static void test_getTop() {
    printf("TEST: getTop\n");
    Stack s;
    initStack(&s);

    push(&s, 5);
    push(&s, 10);
    Node* topNode = getTop(&s);
    assert(topNode->data == 10);

    printf("  => getTop OK\n");
    destroyStack(&s);
}

static void test_traverseStack() {
    printf("TEST: traverseStack\n");
    Stack s;
    initStack(&s);

    // Мы не будем здесь тестировать вывод, но убедимся, что функция не "падает"
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    traverseStack(&s);

    printf("  => traverseStack OK\n");
    destroyStack(&s);
}

static void test_isEmpty() {
    printf("TEST: isEmpty\n");
    Stack s;
    initStack(&s);

    assert(isEmpty(&s) == true);

    push(&s, 999);
    assert(isEmpty(&s) == false);

    printf("  => isEmpty OK\n");
    destroyStack(&s);
}

int main() {
    // Запускаем все тестовые функции по очереди
    test_initStack();
    test_push();
    test_pop();
    test_searchByValue();
    test_searchByIndex();
    test_getTop();
    test_traverseStack();
    test_isEmpty();

    printf("\nВсе тесты успешно пройдены!\n");
    return 0;
}
