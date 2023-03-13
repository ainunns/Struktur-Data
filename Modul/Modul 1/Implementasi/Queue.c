#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node_t
{
    int data;
    struct node_t *next;
} QueueNode;

typedef struct t
{
    int _size;
    QueueNode *front, *rear;
} Queue;

void init(Queue *queue)
{
    queue->front = queue->rear = NULL;
    queue->_size = 0;
}

bool isEmpty(Queue *queue)
{
    return (queue->front == NULL && queue->rear == NULL);
}

void push(Queue *queue, int val)
{
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    if (newNode)
    {
        queue->_size++;
        newNode->data = val;
        newNode->next = NULL;

        if (isEmpty(queue))
            queue->front = queue->rear = newNode;
        else
        {
            queue->rear->next = newNode;
            queue->rear = newNode;
        }
    }
}

void pop(Queue *queue)
{
    if (!isEmpty(queue))
    {
        QueueNode *tmp = queue->front;
        queue->front = queue->front->next;
        free(tmp);

        if (queue->front == NULL)
            queue->rear = NULL;
        queue->_size--;
    }
}

int front(Queue *queue)
{
    if (!isEmpty(queue))
    {
        return queue->front->data;
    }
    return 0;
}

int main()
{
    Queue myQueue;

    init(&myQueue);

    for (int i = 0; i < 10; i++)
    {
        push(&myQueue, i);
    }

    while (!isEmpty(&myQueue))
    {
        printf("%d ", front(&myQueue));
        pop(&myQueue);
    }
    puts("");
    return 0;
}