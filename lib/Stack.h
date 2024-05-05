//
// Created by ASUS on 18/4/2024.
//

#ifndef ULIK_STACK_H
#define ULIK_STACK_H

#include "LinkedList.h"

void push(node** head, node** tail, infonode data){
    insertFirst(head, tail, data);
}

// params head: pointer to head of the list
char pop(node** head){
    return deleteFirstReturn(head);
}

#endif //ULIK_STACK_H
