#include "queue.h"
#include "list.h"
#include "malloc.h"
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
//
//#define NULL *void
void list_init(LIST *a)
{
    //memset(q,0,sizeof(QUEUE));
    a->queue = NULL;
    a->left = NULL; // left branch
    a->right = NULL; // right
    a->tag = 0; // id of item
}

//------------------------------------------ list_insert
// add item to list, sorted
// traverse post-order (left,right,visit) and return item
int list_insert(LIST *a,QUEUE q,int tag)
{
    //int i;
    LIST *p=a, *b=NULL;
    while ( p != NULL )
    {
        if ( tag < p->tag )
        {
            if ( ! p->left ) {
                b=malloc(sizeof(LIST));
                p->left=b;
                b->queue=&q;
                b->tag=tag;
                b->left=NULL;
                b->right=NULL;
                return 1;
            } else {
                return list_insert( p->left, q, tag );
            }
        } else {
            if ( ! p->right ) {
                b=malloc(sizeof(LIST));
                p->right=b;
                b->tag=tag;
                b->queue=&q;
                b->left=NULL;
                b->right=NULL;
                return 1;
            } else {
                return list_insert( p->right, q, tag );

            }
        }
    }
    return 0;
}

//------------------------------------------ list_insert
// riteinsert item to list, sorted, no alloc
// traverse post-order (left,right,visit) and return item
int list_reinsert(LIST *a,QUEUE q,int tag)
{
    //int i;
    LIST *p=a, *b=NULL;
    while ( p != NULL )
    {
        if ( tag < p->tag )
        {
            if ( ! p->left ) {
                b=malloc(sizeof(LIST));
                p->left=b;
                b->queue=&q;
                b->tag=tag;
                b->left=NULL;
                b->right=NULL;
                return 1;
            } else {
                return list_insert( p->left, q, tag );
            }
        } else {
            if ( ! p->right ) {
                b=malloc(sizeof(LIST));
                p->right=b;
                b->tag=tag;
                b->queue=&q;
                b->left=NULL;
                b->right=NULL;
                return 1;
            } else {
                return list_insert( p->right, q, tag );

            }
        }
    }
    return 0;
}

// add item to list, sorted
// should return tag/item? or 0 on fail
int list_enqueue(LIST *a, QUEUE q)
{
    return list_insert( a, q, a->tag++ );
}

// traverse post-order (left,right,visit) and return item
// ok, this does not work yet
// return root or null on fail
int list_dequeue(LIST *a,int tag)
{
    LIST *p=a, *parent=a;
    while ( p!=NULL ) {
    if ( tag == p->tag ) {
        // unlink, take out of tree and reinsert?
        parent->left = p->left;
        parent->right = p->right;
        // list_insert( a, q, a->tag );
        // list_insrert( a, q, a->tag );
        // free(p);
    } else if ( tag<p->tag && p->left ) {
        list_dequeue(p->left,tag);
    } else if ( tag>p->tag && p->right )
        list_dequeue(p->right,tag);
    }
    return 0;

}

// find in queue
// traverse in-order (left,visit,right) and return item
// return tag/item? or NULL on fail
int list_find(LIST *a, int value)
{

    return 0;

}

// traverse in-order (left,visit,right) and print
// return root or NULL at fail
void list_print(LIST *a)
{
    LIST *p=a;
    while ( p != NULL )
    {
        list_print(p->left);
        if ( p->queue )
        {
            queue_print(p->queue);
            printf(" {%d}\n",p->tag);
        }
        list_print(p->right);
        //return(1);
    }
    //return(0);
}



