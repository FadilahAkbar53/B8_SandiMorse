//
// Created by ASUS on 13/5/2024.
//

#ifndef B8_SANDIMORSE_STACKQUEUE_H
#define B8_SANDIMORSE_STACKQUEUE_H

#include "LinkedList.h"

void push(stack *s, morseTree *data){
    insertFirst(&(s->top), data);
}

morseTree *pop(stack *s){
    return deleteFirstReturn(&(s->top));
}

//void enqueue(queue *q, morseTree *data){
//    insertLast(&(q->head), data);
//    if (q->tail == NULL){
//        q->tail = q->head;
//    }
//}
//
//morseTree *dequeue(queue *q){
//    return deleteFirstReturn(&(q->head));
//}


#endif //B8_SANDIMORSE_STACKQUEUE_H
