//
// Created by ASUS on 30/3/2024.
//

#ifndef ULIK_STRUKTURE_H
#define ULIK_STRUKTURE_H

typedef char infonode;
typedef struct Node{
    infonode data;
    struct Node *next;
}node;

typedef struct List{
    node *head;
    node *tail;
}list;



#endif //ULIK_STRUKTURE_H
