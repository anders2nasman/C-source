#include <stdio.h>
#include "queue.h"
#define B(x) x?"succeeded\n":"failed\n"

int main(void)
{
    QUEUE queue;
    QUEUE *q=&queue;

    int item;

    queue_init(q);

    printf("%s",B(queue_dequeue(q,&item)));
    printf("%s",B(queue_enqueue(q,1)));
    printf("%s",B(queue_enqueue(q,2)));
    printf("%s",B(queue_enqueue(q,3)));
    printf("%s",B(queue_enqueue(q,4)));
    printf("%s",B(queue_enqueue(q,5)));
    printf("%s",B(queue_enqueue(q,6)));
    printf("%s",B(queue_enqueue(q,7)));
    printf("%s",B(queue_enqueue(q,8)));
    printf("%s",B(queue_enqueue(q,9)));

    queue_print(q);

    printf("%s",B(queue_dequeue(q,&item)));
    printf("%s",B(queue_dequeue(q,&item)));
    printf("%s",B(queue_dequeue(q,&item)));

    queue_print(q);

    printf("%s",B(queue_enqueue(q,0)));

    queue_print(q);

    return 0;
}
