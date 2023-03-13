#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node_t
{
    int data;
    struct node_t *next, *prev;
} dqistNode;

typedef struct deque_t
{
    int _size;
    dqistNode *head, *tail;
} Deque;

dqistNode *createNode(int val)
{
    dqistNode *newNode = (dqistNode *)malloc(sizeof(dqistNode));

    if (!newNode)
        return NULL;

    newNode->data = val;
    newNode->next = newNode->prev = NULL;

    return (dqistNode *)newNode;
}

void init(Deque *deque)
{
    deque->head = deque->tail = NULL;
    deque->_size = 0;
}

bool isEmpty(Deque *deque)
{
    return (deque->head == NULL && deque->tail == NULL);
}

void push_front(Deque *deque, int val)
{
    dqistNode *newNode = createNode(val);
    if (newNode)
    {
        deque->_size++;
        if (isEmpty(deque))
        {
            deque->head = deque->tail = newNode;
            return;
        }

        newNode->next = deque->head;
        deque->head->prev = newNode;
        deque->head = newNode;
    }
}

void push_back(Deque *deque, int val)
{
    dqistNode *newNode = createNode(val);
    if (newNode)
    {
        deque->_size++;
        if (isEmpty(deque))
        {
            deque->head = deque->tail = newNode;
            return;
        }
        deque->tail->next = newNode;
        newNode->prev = deque->tail;
        deque->tail = newNode;
    }
}

int front(Deque *deque)
{
    if (!isEmpty(deque))
    {
        return deque->head->data;
    }
    return 0;
}

int back(Deque *deque)
{
    if (!isEmpty(deque))
    {
        return deque->tail->data;
    }
    return 0;
}

void pop_front(Deque *deque)
{
    if (!isEmpty(deque))
    {
        dqistNode *tmp = deque->head;
        if (deque->head == deque->tail)
        {
            deque->head = deque->tail = NULL;
        }
        else
        {
            deque->head = deque->head->next;
            deque->head->prev = NULL;
        }
        free(tmp);
        deque->_size--;
    }
}

void pop_back(Deque *deque)
{
    if (!isEmpty(deque))
    {
        dqistNode *tmp;
        if (deque->head == deque->tail)
        {
            tmp = deque->head;
            deque->head = deque->tail = NULL;
        }
        else
        {
            tmp = deque->tail;
            deque->tail = deque->tail->prev;
            deque->tail->next = NULL;
        }
        free(tmp);
        deque->_size--;
    }
}

int main()
{
    Deque dq;
    init(&dq);

    push_back(&dq, 1);
    push_back(&dq, 2);
    push_back(&dq, 3);
    push_back(&dq, 4);

    push_front(&dq, 10);
    push_front(&dq, 9);
    push_front(&dq, 8);
    push_front(&dq, 7);

    pop_back(&dq);
    pop_front(&dq);

    while (!isEmpty(&dq))
    {
        printf("%d ", front(&dq));
        pop_front(&dq);
    }
}