//
// Created by yuanh on 2021/9/11.
//

#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int item;
    struct Node *next;
};
typedef struct Node Node;
struct Queue
{
    int size;
    Node *head;
    Node *tail;
};
typedef struct Queue Queue;

Queue *create_queue(void)
{
    Queue *queue = malloc(sizeof(Queue));
    if (!queue)
        return queue;
    queue->size = 0;
    queue->head = queue->tail = NULL;
    return queue;
}

int empty(Queue *queue)
{
    return queue->size == 0;
}

void enqueue(Queue *queue, int item)
{
    struct Node *new = malloc(sizeof(Node));
    if (!new)
        return;
    new->item = item;
    new->next = NULL;
    if (queue->head)
        queue->tail->next = new;
    else
        queue->head = new;
    queue->tail = new;
    queue->size++;
}

int dequeue(Queue *queue)
{
    if (empty(queue))
        return -1;
    int retval = queue->head->item;
    struct List *torm = queue->head;
    if (queue->head == queue->tail)
        queue->tail = NULL;
    queue->head = queue->head->next;
    free(torm);
    queue->size--;
    return retval;
}

int main()
{
    // 约瑟夫环问题， 队列模拟求解，用数组实现队列也是可以的，叫做循环队列，可以去了解一下。
    Queue *q = create_queue();
    for (int i = 1; i <= 100; ++i)
    {
        enqueue(q, i);
    }
    int count = 0;
    while (q->size > 1)
    {
        count++;
        if (count % 3 == 0)
        {
            dequeue(q);
            count = 0;
        } else
        {
            int tmp = q->head->item;
            dequeue(q);
            enqueue(q, tmp);
        }
    }

    int ret = q->head->item;
    printf("%d\n", ret);
}