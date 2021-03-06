#include <stdio.h>
#include "queue.h"
#include "list.h"
#define EXP(x,t) (x==t)?"succeeded\n":"failed\n"

#define NQUEUES 25
#define KEY 0x5a5a

// design decisions:
// 1) B() changed

int main(void)
{
    LIST list;
    LIST *p=&list;
    QUEUE queue[NQUEUES];
    QUEUE *q=&queue;

    int item=KEY, i=0,r;

    list_init(p);
    queue_init(q);

    for ( i=0; i<NQUEUES; i++) {
        q=&queue[i];
        queue_init(q);
        list_enqueue(p,*q);
        printf("dequeue empty %s",EXP(0,queue_dequeue(q,&item)));
        printf("enqueue 1 %s",EXP(1,queue_enqueue(q,i*100+1)));         // change order to test prio
        printf("enqueue 2 %s",EXP(2,queue_enqueue(q,i*100+7)));
        printf("enqueue 3 %s",EXP(3,queue_enqueue(q,i*100+5)));
        printf("enqueue 4 %s",EXP(4,queue_enqueue(q,i*100+3)));
        printf("enqueue 5 %s",EXP(5,queue_enqueue(q,i*100+9)));
        printf("enqueue 6 %s",EXP(6,queue_enqueue(q,i*100+4)));
        printf("enqueue 7 %s",EXP(7,queue_enqueue(q,i*100+6)));
        printf("enqueue 8 %s",EXP(8,queue_enqueue(q,i*100+2)));
        printf("enqueue 9 overflow %s",EXP(0,queue_enqueue(q,i*100+8)));
        //
        printf("list enqueue %s",EXP(1,list_enqueue(p,*q)));

        queue_print(q);

        printf("dequeue 7 %s",EXP(7,queue_dequeue(q,&item)));
        printf("dequeue 6 %s",EXP(6,queue_dequeue(q,&item)));
        printf("dequeue 5 %s",EXP(5,queue_dequeue(q,&item)));

        queue_print(q);

        printf("enqueue 6 %s",EXP(6,queue_enqueue(q,0)));

        queue_print(q);
    }
    list_print(p);

    return 0;
}
