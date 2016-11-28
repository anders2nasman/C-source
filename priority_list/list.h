#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#define LISTSIZE 256
#include <stdio.h>
#include <string.h>

// list of queues (or any struct)
//typedef _LIST;
typedef struct _LIST
{
    int tag; // id and sort index, may be a hash
    struct _LIST *left;
    struct _LIST *right;
    QUEUE *queue;
} LIST;

void list_init(LIST *a);
int list_enqueue(LIST *a, QUEUE item); // should return tag or 0 on fail
int list_dequeue(LIST *a, int tag);
int list_find(LIST *a, int value);
void list_print(LIST *a);

#endif // LIST_H_INCLUDED


