#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct node_t
{
    char data[101];
    struct node_t *next;
} SListNode;

typedef struct list_t
{
    int _size;
    SListNode *head;
} SinglyList;

void init(SinglyList *list)
{
    list->_size = 0;
    list->head = NULL;
}

bool isEmpty(SinglyList *list)
{
    return (list->head == NULL);
}

void push_back(SinglyList *list, char val[])
{
    SListNode *newNode = (SListNode *)malloc(sizeof(SListNode));
    if (newNode)
    {
        list->_size++;
        strcpy(newNode->data, val);
        newNode->next = NULL;
        if (isEmpty(list))
        {
            list->head = newNode;
        }
        else
        {
            SListNode *tmp = list->head;
            while (tmp->next != NULL)
                tmp = tmp->next;
            tmp->next = newNode;
        }
    }
}

void push_front(SinglyList *list, char val[])
{
    SListNode *newNode = (SListNode *)malloc(sizeof(SListNode));
    if (newNode)
    {
        list->_size++;
        strcpy(newNode->data, val);

        if (isEmpty(list))
            newNode->next = NULL;
        else
            newNode->next = list->head;
        list->head = newNode;
    }
}

void insertAt(SinglyList *list, int index, char val[])
{
    if (index == 0)
    {
        push_front(list, val);
        return;
    }
    if (isEmpty(list) || index >= list->_size)
    {
        push_back(list, val);
        return;
    }
    SListNode *newNode = (SListNode *)malloc(sizeof(SListNode));
    if (newNode)
    {
        SListNode *tmp = list->head;
        int i = 0;

        while (tmp->next != NULL && i < index - 1)
        {
            tmp = tmp->next;
            i++;
        }

        strcpy(newNode->data, val);
        newNode->next = tmp->next;
        tmp->next = newNode;
        list->_size++;
    }
}

char *back(SinglyList *list)
{
    if (!isEmpty(list))
    {
        SListNode *tmp = list->head;
        while (tmp->next != NULL)
            tmp = tmp->next;
        return tmp->data;
    }
    return NULL;
}

char *front(SinglyList *list)
{
    if (!isEmpty(list))
    {
        return list->head->data;
    }
    return NULL;
}

char *getAt(SinglyList *list, int index)
{
    if (!isEmpty(list))
    {
        SListNode *tmp = list->head;
        int i = 0;
        while (tmp->next != NULL && i < index)
        {
            tmp = tmp->next;
            i++;
        }
        return tmp->data;
    }
    return NULL;
}

void pop_back(SinglyList *list)
{
    if (!isEmpty(list))
    {
        SListNode *curNode = list->head;
        SListNode *nxtNode = curNode->next;

        if (nxtNode == NULL)
        {
            free(curNode);
            list->head = NULL;
            return;
        }

        while (nxtNode->next != NULL)
        {
            curNode = nxtNode;
            nxtNode = curNode->next;
        }

        curNode->next = NULL;
        free(nxtNode);
        list->_size--;
    }
}

void pop_front(SinglyList *list)
{
    if (!isEmpty(list))
    {
        SListNode *tmp = list->head;
        list->head = list->head->next;
        free(tmp);
        list->_size--;
    }
}

void remove_nd(SinglyList *list, char val[])
{
    if (!isEmpty(list))
    {
        SListNode *tmp = list->head, *prev;

        if (!strcmp(tmp->data, val))
        {
            pop_front(list);
            return;
        }

        while (tmp != NULL && strcmp(tmp->data, val))
        {
            prev = tmp;
            tmp = tmp->next;
        }

        if (tmp == NULL)
            return;
        prev->next = tmp->next;
        free(tmp);
        list->_size--;
    }
}

int main()
{
    SinglyList sl;
    init(&sl);

    push_back(&sl, "apel");
    push_back(&sl, "jeruk");

    SListNode *tmp = sl->head;

    while (tmp != NULL)
    {
        printf("%s\n", tmp->data);
        tmp = tmp->next;
    }
}