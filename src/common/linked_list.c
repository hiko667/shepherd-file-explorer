#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linked_list.h"


//I (((stole))) was inspired by this code from https://www.geeksforgeeks.org/c/linked-list-in-c/ 
struct node * getNewLinkedList(){
    struct node * newList = NULL;
    return newList;
}

struct node * newNode(const char * path){
    struct node * new = malloc(sizeof(struct node));
    if (!new) return NULL; 
    new->path = strdup(path);
    new->next = NULL;
    return new;
}

void push(struct node ** head, const char * path){
    struct node * temp = newNode(path);
    if (*head != NULL) {
        temp->next = *head;
    }
    *head = temp;
}

void pop(struct node ** head){
    if(head == NULL || * head == NULL) return;
    struct node * temp = (*head);
    (*head) = (*head)->next;
    free(temp->path);
    free(temp);
}

void freeLinkedList(struct node ** head){
    struct node *temp = (*head);
    while (temp != NULL){
        struct node *next = temp->next;
        free(temp->path);
        free(temp);
        temp = next;
    }
    *head = NULL;
}