#include <stdio.h>
#include <assert.h>
#include "stack.h"

// ������� ��� ������������ initStack
void testInitStack() {
    Stack stack;
    initStack(&stack);
    assert(isEmpty(&stack) == true);
    printf("testInitStack passed.\n");
}

// ������� ��� ������������ push
void testPush() {
    Stack stack;
    initStack(&stack);
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    assert(stack.top->data == 30);
    assert(stack.top->next->data == 20);
    assert(stack.top->next->next->data == 10);
    printf("testPush passed.\n");
}

// ������� ��� ������������ pop
void testPop() {
    Stack stack;
    initStack(&stack);
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    pop(&stack);
    assert(stack.top->data == 20);
    pop(&stack);
    assert(stack.top->data == 10);
    pop(&stack);
    assert(isEmpty(&stack) == true);
    printf("testPop passed.\n");
}

void testSearchByValue() {
    Stack stack;
    initStack(&stack);
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    Node* result = searchByValue(&stack, 20);
    assert(result != NULL && result->data == 20);
    result = searchByValue(&stack, 40);
    assert(result == NULL);
    printf("testSearchByValue passed.\n");
}

// ������� ��� ������������ searchByIndex
void testSearchByIndex() {
    Stack stack;
    initStack(&stack);
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    Node* result = searchByIndex(&stack, 1);
    assert(result != NULL && result->data == 20);
    result = searchByIndex(&stack, 3);
    assert(result == NULL);
    printf("testSearchByIndex passed.\n");
}

// ������� ��� ������������ isEmpty
void testIsEmpty() {
    Stack stack;
    initStack(&stack);
    assert(isEmpty(&stack) == true);
    push(&stack, 10);
    assert(isEmpty(&stack) == false);
    pop(&stack);
    assert(isEmpty(&stack) == true);
    printf("testIsEmpty passed.\n");
}

// ������� ��� ������������ traverseStack
void testTraverseStack() {
    Stack stack;
    initStack(&stack);
    printf("Expected: Stack is empty.\n");
    traverseStack(&stack);
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    printf("Expected: Stack elements: 30 20 10\n");
    traverseStack(&stack);
    printf("testTraverseStack passed.\n");
}

// ������� ��� ������������ destroyStack
void testDestroyStack() {
    Stack stack;
    initStack(&stack);
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    destroyStack(&stack);
    assert(isEmpty(&stack) == true);
    printf("testDestroyStack passed.\n");
}

// �������� ������� ��� ������� ���� ������
int main() {
    testInitStack();
    testPush();
    testPop();
    testSearchByValue();
    testSearchByIndex();
    testIsEmpty();
    testTraverseStack();
    testDestroyStack();
    printf("All tests passed successfully!\n");
    return 0;
}
