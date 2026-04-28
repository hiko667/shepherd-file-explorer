#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct node{
    char * path;
    struct node * next; 
};

struct node * getNewLinkedList();
void push(struct node ** head, char * path);
void pop(struct node ** head);
void freeLinkedList(struct node ** head);

#endif