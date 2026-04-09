#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linked_list.h"


//i stole most of this code from https://www.geeksforgeeks.org/c/linked-list-in-c/ check them out
struct node * getNewLinkedList(){
    struct node * newList = malloc(sizeof(struct node));

}

struct node * newNode(const char * path){
    struct node * new = malloc(sizeof(struct node));
    new->path = strdup(path);
    new->next = NULL;
    return new;
}

void push(struct node * head, char * value){

}

void pull(struct node * head){

}

void freeTree(struct node * head){
    struct node *temp = head;
    temp = head;
    while (temp != NULL){
        struct Node *next = temp->next;
        free(temp->path);
        free(temp);
        temp = next;
    }
}