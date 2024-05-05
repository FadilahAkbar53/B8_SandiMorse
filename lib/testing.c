//
// Created by ASUS on 5/5/2024.
//

#include "Stack.h"
#include "Queue.h"
#include "LinkedList.h"

void testQueue(){
    list queue;
    queue.head = NULL;
    queue.tail = NULL;

    enqueue(&queue.head, &queue.tail, 'a');
    enqueue(&queue.head, &queue.tail, 'b');
    enqueue(&queue.head, &queue.tail, 'c');
    enqueue(&queue.head, &queue.tail, 'd');

    printData(queue.head);
    printf(" data dequeue = %c\n", dequeue(&queue.head, &queue.tail));
    printData(queue.head);
    printf(" data dequeue = %c\n", dequeue(&queue.head, &queue.tail));
    printData(queue.head);
}

void testStack(){
    list stack;
    stack.head = NULL;
    stack.tail = NULL;

    push(&stack.head, &stack.tail, 'a');
    push(&stack.head, &stack.tail, 'b');
    push(&stack.head, &stack.tail, 'c');
    push(&stack.head, &stack.tail, 'd');

    printData(stack.head);
    printf(" data pop = %c\n", pop(&stack.head));
    printData(stack.head);
    printf(" data pop = %c\n", pop(&stack.head));
    printData(stack.head);
}

void testLinkedList(){
    list linkedList;
    linkedList.head = NULL;
    linkedList.tail = NULL;

    insertFirst(&linkedList.head, &linkedList.tail, 'a');
    insertFirst(&linkedList.head, &linkedList.tail, 'b');
    insertFirst(&linkedList.head, &linkedList.tail, 'c');
    insertFirst(&linkedList.head, &linkedList.tail, 'd');

    printData(linkedList.head);
    printf(" data delete = %c\n", deleteFirstReturn(&linkedList.head));
    printData(linkedList.head);
    printf(" data delete = %c\n", deleteLastReturn(&linkedList.head, &linkedList.tail));
    printData(linkedList.head);
}

int main(){

    printf("\ntest stack\n");
    testStack();
    printf("\ntest queue\n");
    testQueue();
    printf("\ntest linklist\n");
    testLinkedList();

    return 0;
}
