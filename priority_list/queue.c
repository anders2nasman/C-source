#include "queue.h"
// module: queue.c
// purpose: implements priority queue handling with lists
// revision history:
// 2016-11-10 Anders Näsman, created and basic test
//
// design decisions:
// 1) index definition and usage, see below
// 2) sort on write, or sort on read ?
//    read is more common than write => sort on write
// 3) print queue as is, or sorted => no issue, already sorted, always sorted
// 4) separate new function for sorted insert, queue_insert(q,item,pos)
// 5) return number of item of success, otherwhise 0
//
void queue_init(QUEUE *q)
{
    memset(q,0,sizeof(QUEUE));
    q->windex=0; // next free to write, index are always &(SIZE-1), assume 2^n
    q->rindex=0; // read index, next to read, if num>0
    q->numitems=0; // if not full or not empty, num=w-r
}


int queue_insert(QUEUE *q,int item,int position)
{
    int i;
    // 6 -> [3]5][7][9][ ][][][][][]
    // 6 -> [3]5][ ][7][9][][][][][]   move from w to index upwards,
    // 6 -> [3]5][6][7][9][][][][][]   to create empty space, insert item
    //       r   +p       w            and wrap indices
    // note: position is offset to read pointer, i.e. n:th element
    if ( (q->numitems < QUEUESIZE) && (position < QUEUESIZE) )  // should be <w-r
    {
        for ( i=q->numitems; i>position; i--)
        {
            q->items[(q->rindex+i)&((QUEUESIZE-1))] =
                q->items[(q->rindex+i-1)&((QUEUESIZE-1))]; // shift item, a[i]=a[i-i]
        }
        q->items[(q->rindex+position)&((QUEUESIZE-1))] = item;
        q->windex=(q->windex+1)&(QUEUESIZE-1);
        q->numitems++;
        return 1;
    }
    //return q->numitems; // should actually return inserted or not inserted
    return 0;
}


int queue_enqueue(QUEUE *q,int item)
{
    int i,result=0;
    // check if queue not full
    if ( q->numitems < QUEUESIZE )
    {
        // if less than existing, insert before, push the rest
        for ( i=0; i<q->numitems; i++)
        {
            if ( item < q->items[q->rindex+i&((QUEUESIZE-1))] )
            {
                result=queue_insert(q,item,i); // insert item a position i
                break;
            }
        }
        // if gt or equal insert after - assumes it is already ordered
        if ( !result ) // put it at the end
        {
            q->items[q->windex] = item; // add to end/top
            q->windex=(q->windex+1)&(QUEUESIZE-1);
            ++q->numitems;
        }
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
        printf("%d ",q->items[(q->rindex+i)&(QUEUESIZE-1)]); // wrap index
    }
    printf("\n");
}


