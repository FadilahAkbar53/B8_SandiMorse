//
// Created by ASUS on 13/5/2024.
//

#ifndef B8_SANDIMORSE_LINKEDLIST_H
#define B8_SANDIMORSE_LINKEDLIST_H

#include "Struktur.h"


bool isEmpty(nodeTree *head){
    return head == NULL;
}

nodeTree* createNode(morseTree *data){
    nodeTree *newNode = (nodeTree*)malloc(sizeof(nodeTree));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertFirst(nodeTree **head, morseTree *data){
    if (head == NULL){
        *head = createNode(data);
    } else{
        nodeTree *newNode = createNode(data);
        newNode->next = *head;
        *head = newNode;
    }
}

void insertLast(nodeTree **head, morseTree *data){
    if (*head == NULL){
        *head = createNode(data);
    } else{
        nodeTree *curr = *head;
        while (curr->next != NULL){
            curr = curr->next;
        }
        curr->next = createNode(data);
    }
}

morseTree *deleteLastReturn(nodeTree **head){
    if (*head == NULL){
        return NULL;
    } else if ((*head)->next == NULL){
        morseTree *data = (*head)->data;
        free(*head);
        *head = NULL;
        return data;
    } else{
        nodeTree *curr = *head;
        while (curr->next->next != NULL){
            curr = curr->next;
        }
        morseTree *data = curr->next->data;
        free(curr->next);
        curr->next = NULL;
        return data;
    }
}

morseTree *deleteFirstReturn(nodeTree **head){
    if (*head == NULL){
        return NULL;
    } else{
        nodeTree *temp = *head;
        *head = (*head)->next;
        morseTree *data = temp->data;
        free(temp);
        return data;
    }
}

void printdata(nodeTree *head){
    nodeTree *curr = head;
    while (curr != NULL){
        printf("%c <- ", curr->data->data);
        curr = curr->next;
    }
}

#endif //B8_SANDIMORSE_LINKEDLIST_H
