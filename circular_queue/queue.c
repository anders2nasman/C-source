#include "queue.h"
/*
    int items[QUEUESIZE];
    int rindex;
    int windex;
    int numitems;
*/
void queue_init(QUEUE *q)
{
    memset(q,0,sizeof(QUEUE));
    q->windex=0; // free to write
    q->rindex=0; // next to read
    q->numitems=0; // if not full or not empty
}

int queue_enqueue(QUEUE *q,int item)
{
    // check if queue not full
    if ( q->numitems < QUEUESIZE )
    {
        q->items[q->windex] = item;
        // wrap index, only works for size 2**n
        q->windex=(q->windex+1)&(QUEUESIZE-1);
        //return ++q->numitems;
        ++q->numitems;
        return q->numitems;
    }
    return 0;

}

int queue_dequeue(QUEUE *q,int *item)
{
    // check if queue not empty
    if ( q->numitems > 0 )
    {
        *item = q->items[q->rindex]; //
        q->rindex=(q->rindex+1)&(QUEUESIZE-1); // only works for size 2**n
        //return --q->numitems;
        --q->numitems;
        return q->numitems;
    }
    return 0;

}

void queue_print(QUEUE *q)
{
    int i;
    // iterate over existing items, wrap around index by vuffer size
    for (i=0; i<q->numitems; i++ )
    {
        printf("%d",q->items[(q->rindex+i)&(QUEUESIZE-1)]); // wrap index
    }
    printf("\n");
}


