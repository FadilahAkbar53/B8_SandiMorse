#ifndef B8_SANDIMORSE_LINKEDLIST_H
#define B8_SANDIMORSE_LINKEDLIST_H

#include "LinkedList.h"

typedef struct Stack {
   node *top;
} stack;

char pop(stack *s) {
    return deleteFirst(&(s->top));
}

void push(stack *s, char data) {
    insertFirst(&(s->top), data);
}


#endif //B8_SANDIMORSE_LINKEDLIST_H
