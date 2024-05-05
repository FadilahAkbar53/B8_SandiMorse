//
// Created by ASUS on 30/3/2024.
//

#ifndef ULIK_LINKEDLIST_H
#define ULIK_LINKEDLIST_H

#include "Struktur.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

node *alokasiNode(infonode data) {
    node *newNode = (node *) malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Alokasi gagal");
        exit(1);
    } else {
        newNode->next = NULL;
        newNode->data = data;
        return newNode;
    }
}

bool isEmpty(node *head) {
    return head == NULL;
}

node *searchNode(node **head, infonode data) {
    node *pNode = *head;
    while (pNode != NULL) {
        if (pNode->data == data) {
            return pNode;
        }
        pNode = pNode->next;
    }
    printf("Error(searchNode) : dataAfter tidak ditemukan ketika mencari node data = %c\n", data);
    return NULL;
}

void insertEmptyList(node** head, node** tail, node** pNode){
    *head = *pNode;
    *tail = *pNode;
}

void insertFirst(node** head, node** tail, infonode data){
    node* pNode = alokasiNode(data);
    if (*head == NULL){
//        printf("Head adalah NULL, memanggil insertEmptyList\n");
        insertEmptyList(head, tail, &pNode);
    } else{
        pNode->next = *head;
        *head = pNode;
    }
}

void insertAfter(node** head, node** tail, infonode data, infonode dataAfter){
    node* pNode = alokasiNode(data);
    if (*head == NULL){
        insertEmptyList(head, tail, &pNode);
    }else{
        node* precNode = searchNode(head, dataAfter);
        if (precNode != NULL){
            pNode->next = precNode->next;
            precNode->next = pNode;
        }
    }
}

void insertLast(node** head, node** tail, infonode data){
    node* pNode = alokasiNode(data);
    if (*tail == NULL){
        insertEmptyList(head, tail, &pNode);
    }else{
        (*tail)->next = pNode;
        (*tail) = pNode;
    }
}


void deleteFirst(node** head){
    // check underflow
    if (*head != NULL){
        node* temp = *head;
        *head = (*head)->next;
        temp->next = NULL;
        free(temp);
    } else{
        printf("Error (deleteFirst) : Underflow\n");
    }
}

infonode deleteFirstReturn(node** head){
    // check underflow
    if (*head != NULL){
        node* temp = *head;
        *head = (*head)->next;
        temp->next = NULL;
        infonode data = temp->data;
        free(temp);
        return data;
    } else{
        printf("Error (deleteFirst) : Underflow\n");
        return 0;
    }
}


void deleteAfter(node** head, node** tail, infonode dataAfter) {
    // Check underflow
    if (*head == NULL) {
        printf("Error (deleteAfter): Underflow\n");
        return;
    }

    node* precNode = searchNode(head, dataAfter);

    //periksa apakah precNode berada pada simpul terakhir
    if (precNode->next == NULL) {
        printf("Error (deleteAfter): Node dengan data %c berada pada simpul terakhir\n", dataAfter);
        return;
    }

    node* temp = precNode->next;
    //periksa apakah node yang dihapus adalah node terakhir atau tidak
    if (temp->next == NULL) {
        precNode->next = NULL;
        *tail = precNode;  // Update tail jika node terakhir dihapus
    } else {
        precNode->next = temp->next;
    }

    temp->next = NULL;
    free(temp);
}

infonode deleteAfterReturn(node** head, node** tail, infonode dataAfter) {
    // Check underflow
    if (*head == NULL) {
        printf("Error (deleteAfter): Underflow\n");
        return 0;
    }

    node* precNode = searchNode(head, dataAfter);

    //periksa apakah precNode berada pada simpul terakhir
    if (precNode->next == NULL) {
        printf("Error (deleteAfter): Node dengan data %c berada pada simpul terakhir\n", dataAfter);
        return 0;
    }

    node* temp = precNode->next;
    //periksa apakah node yang dihapus adalah node terakhir atau tidak
    if (temp->next == NULL) {
        precNode->next = NULL;
        *tail = precNode;  // Update tail jika node terakhir dihapus
    } else {
        precNode->next = temp->next;
    }

    infonode data = temp->data;
    temp->next = NULL;
    free(temp);
    return data;
}

void deleteLast(node** head, node** tail) {
    // Check underflow
    if (*tail != NULL) {
        node* temp = *tail;
        // Jika tail adalah head, artinya ini adalah satu-satunya node dalam daftar
        if (*head == *tail) {
            *head = NULL;
            *tail = NULL;
        } else {
            node* p = *head;
            while (p->next != temp) {
                p = p->next;
            }
            *tail = p;
            p->next = NULL;
        }
        free(temp);
    } else {
        printf("Error (deleteLast): Underflow\n");
    }
}

infonode deleteLastReturn(node** head, node** tail) {
    // Check underflow
    if (*tail != NULL) {
        node* temp = *tail;
        // Jika tail adalah head, artinya ini adalah satu-satunya node dalam daftar
        if (*head == *tail) {
            *head = NULL;
            *tail = NULL;
        } else {
            node* p = *head;
            while (p->next != temp) {
                p = p->next;
            }
            *tail = p;
            p->next = NULL;
        }
        infonode data = temp->data;
        free(temp);
        return data;
    } else {
        printf("Error (deleteLast): Underflow\n");
        return 0;
    }
}

void printData(node* head){
    node* p = head;
    while (p != NULL){
        printf("-> %c ", p->data);
        p = p->next;
    }
    printf("\n");
}

void printinfonode(node** head){
    node* p = *head;
    while (p != NULL){
        printf("%p | %c | %p\n", p, p->data, p->next);
        p = p->next;
    }
}

void printHeadTail(node** head, node** tail){
    if (*head == NULL) {
        printf("Linked list is empty\n");
        return;
    }
    printf("head ={ %p | %c | %p } tail = { %p | %c | %p }\n",
           *head, (*head)->data, (*head)->next, *tail, (*tail)->data, (*tail)->next
    );
}



#endif //ULIK_LINKEDLIST_H
