#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#define QUEUESIZE 8
#include <stdio.h>
#include <string.h>


typedef struct
{
    int items[QUEUESIZE];
    int rindex;
    int windex;
    int numitems;
} QUEUE;

void queue_init(QUEUE *q);
int queue_enqueue(QUEUE *q,int item);
int queue_dequeue(QUEUE *q,int *item);
void queue_print(QUEUE *q);

#endif // QUEUE_H_INCLUDED

