//
// Created by ASUS on 18/5/2024.
//

#ifndef B8_SANDIMORSE_HEADERLINKEDLIST_H
#define B8_SANDIMORSE_HEADERLINKEDLIST_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct Node {
    char data;
    struct Node *next;
} node;

node *createNode(char data);
void insertFirst(node **head, char data);
void insertLast(node **head, char data);
char deleteFirst(node **head);
char deleteLast(node **head);
void printLinkedList(node *head);
void freeLinkedList(node **head);
char *linkedListToString(node *head);

node *createNode(char data) {
    node *newNode = (node *) malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertFirst(node **head, char data) {
    node *newNode = createNode(data);
    if (newNode == NULL) {
        return;
    }
    newNode->next = *head;
    *head = newNode;
}

void insertLast(node **head, char data) {
    node *newNode = createNode(data);
    if (newNode == NULL) {
        return;
    }
    if (*head == NULL) {
        *head = newNode;
    } else {
        node *curr = *head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

char deleteFirst(node **head) {
    if (*head == NULL) {
        return '\0';
    }
    node *temp = *head;
    *head = (*head)->next;
    char data = temp->data;
    free(temp);
    return data;
}

char deleteLast(node **head) {
    if (*head == NULL) {
        return '\0';
    }
    if ((*head)->next == NULL) {
        char data = (*head)->data;
        free(*head);
        *head = NULL;
        return data;
    }
    node *curr = *head;
    while (curr->next->next != NULL) {
        curr = curr->next;
    }
    char data = curr->next->data;
    free(curr->next);
    curr->next = NULL;
    return data;
}

void printLinkedList(node *head) {
    node *curr = head;
    while (curr != NULL) {
        printf("%c -> ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

void freeLinkedList(node **head) {
    while (*head != NULL) {
        node *temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

char *linkedListToString(node *head) {
    // Step 1: Calculate the length of the linked list
    int length = 0;
    node *curr = head;
    while (curr != NULL) {
        length++;
        curr = curr->next;
    }

    // Step 2: Allocate memory for the string
    char *str = (char *) malloc((length + 1) * sizeof(char));
    if (str == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    // Step 3: Copy data from the linked list to the string
    curr = head;
    for (int i = 0; i < length; i++) {
        str[i] = curr->data;
        curr = curr->next;
    }
    str[length] = '\0'; // Null-terminate the string

    return str;
}


#endif //B8_SANDIMORSE_HEADERLINKEDLIST_H
