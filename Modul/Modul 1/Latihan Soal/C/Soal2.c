#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node_t
{
    int data, id;
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

void push(PriorityQueue *pqueue, int val, int ID)
{
    PQueueNode *tmp = pqueue->top, *newNode = (PQueueNode *)malloc(sizeof(PQueueNode));
    newNode->data = val;
    newNode->next = NULL;
    newNode->id = ID;

    if (isEmpty(pqueue))
    {
        pqueue->top = newNode;
        return;
    }

    if (val >= pqueue->top->data)
    {
        newNode->next = pqueue->top;
        pqueue->top = newNode;
    }
    else
    {
        while (tmp->next != NULL && tmp->next->data >= val)
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
        return pqueue->top->id;
    }
    return 0;
}

int main()
{
    int q, i;
    scanf("%d", &q);
    int patient[q + 1];

    PriorityQueue pq;
    init(&pq);

    for (i = 0; i < q; i++)
    {
        char s[10];
        scanf("%s", s);
        if (s[0] == 'M')
        {
            int urg;
            scanf("%d %d", &patient[i], &urg);
            push(&pq, urg, i);
        }
        else
        {
            if (isEmpty(&pq))
                puts("HORE\n");
            else
            {
                printf("%d\n", patient[top(&pq)]);
                pop(&pq);
            }
        }
    }
    return 0;
}