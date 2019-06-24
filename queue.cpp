#include <iostream>
#include <string>

typedef struct
{
    int size = 1000;
    int elements[1000];
    int tail = 0;
    int head = 0;
} queue;

void enqueue(queue *q, int x)
{
    q->elements[q->tail] = x;
    if(q->tail == q->size)
        q->tail = 1;
    else
        q->tail = q->tail + 1;
}

int dequeue(queue *q)
{
    int x = q->elements[q->head];
    if(q->head == q->size)
        q->head = 1;
    else
        q->head = q->head + 1;
    return x;
}

int main(int argc, char const *argv[])
{
    queue q;

    //test
    enqueue(&q, 1);
    int a = dequeue(&q);
    printf("%d\n", a);

    return 0;
}