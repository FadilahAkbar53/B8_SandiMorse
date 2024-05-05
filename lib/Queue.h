//
// Created by ASUS on 18/4/2024.
//

#ifndef ULIK_QUEUE_H
#define ULIK_QUEUE_H

#include "LinkedList.h"

void enqueue(node** head, node** tail, infonode data){
    insertLast(head, tail, data);
}

char dequeue(node** head, node** tail){
    return deleteLastReturn(head, tail);
}

#endif //ULIK_QUEUE_H
