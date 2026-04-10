#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linked_list.h"


//I (((stole))) was inspired by this code from https://www.geeksforgeeks.org/c/linked-list-in-c/ 
struct node * getNewLinkedList(){
    struct node * newList = malloc(sizeof(struct node));
    return newList;
}

struct node * newNode(const char * path){
    struct node * new = malloc(sizeof(struct node));
    new->path = strdup(path);
    new->next = NULL;
    return new;
}

void push(struct node ** head, char * path){
    if((*head)->path == NULL){
        (*head)->path = strdup(path);
    }
    else{
        struct node * temp = malloc(sizeof(struct node));
        temp->next = (*head);
        (*head) = temp;
    }
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