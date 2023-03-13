#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node_t
{
    int data;
    struct node_t *next;
} StackNode;

typedef struct t
{
    StackNode *_top;
    int _size;
} Stack;

void init(Stack *stack)
{
    stack->_size = 0;
    stack->_top = NULL;
}

bool isEmpty(Stack *stack)
{
    return (stack->_top == NULL);
}

void push(Stack *stack, int val)
{
    StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
    if (newNode)
    {
        stack->_size++;
        newNode->data = val;

        if (isEmpty(stack))
            newNode->next = NULL;
        else
            newNode->next = stack->_top;

        stack->_top = newNode;
    }
}

void pop(Stack *stack)
{
    if (!isEmpty(stack))
    {
        StackNode *tmp = stack->_top;
        stack->_top = stack->_top->next;
        free(tmp);
        stack->_size--;
    }
}

int top(Stack *stack)
{
    if (!isEmpty(stack))
        return stack->_top->data;
    return 0;
}

int main()
{
    Stack myStack;

    init(&myStack);

    for (int i = 0; i < 10; i++)
    {
        push(&myStack, i);
    }

    while (!isEmpty(&myStack))
    {
        printf("%d ", top(&myStack));
        pop(&myStack);
    }
    puts("");
    return 0;
}