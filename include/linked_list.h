#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct node{
    char * path;
    struct node * next; 
};

struct node * getNewLinkedList();
void push(struct node * head, char * value);
void pull(struct node * head);
void freeTree(struct node * head);

#endif