#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node_t
{
    int data;
    struct node_t *next;
} PQueueNode;

typedef struct pqueue_t
{
    int _size;
    PQueueNode *top;
} PriorityQueue;

void init(PriorityQueue *pqueue)
{
    pqueue->top = NULL;
    pqueue->_size = 0;
}

bool isEmpty(PriorityQueue *pqueue)
{
    return (pqueue->top == NULL);
}

void push(PriorityQueue *pqueue, int val)
{
    PQueueNode *tmp = pqueue->top, *newNode = (PQueueNode *)malloc(sizeof(PQueueNode));
    newNode->data = val;
    newNode->next = NULL;

    if (isEmpty(pqueue))
    {
        pqueue->top = newNode;
        return;
    }

    if (val < pqueue->top->data)
    {
        newNode->next = pqueue->top;
        pqueue->top = newNode;
    }
    else
    {
        while (tmp->next != NULL && tmp->next->data < val)
            tmp = tmp->next;
        newNode->next = tmp->next;
        tmp->next = newNode;
    }
}

void pop(PriorityQueue *pqueue)
{
    if (!isEmpty(pqueue))
    {
        PQueueNode *tmp = pqueue->top;
        pqueue->top = pqueue->top->next;
        free(tmp);
    }
}

int top(PriorityQueue *pqueue)
{
    if (!isEmpty(pqueue))
    {
        return pqueue->top->data;
    }
    return 0;
}

int main()
{
    // min-priority queue
    PriorityQueue pq;
    init(&pq);
    for (int i = 0; i < 10; i++)
    {
        push(&pq, i * 5);
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", top(&pq));
        pop(&pq);
    }
}