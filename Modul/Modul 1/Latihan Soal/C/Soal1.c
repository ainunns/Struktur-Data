#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node_t
{
    int elem, min;
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
        newNode->elem = val;

        if (isEmpty(stack))
        {
            newNode->next = NULL;
            newNode->min = val;
        }
        else
        {
            newNode->next = stack->_top;
            if (stack->_top->min <= val)
                newNode->min = stack->_top->min;
            else
                newNode->min = val;
        }

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
        return stack->_top->min;
    return 0;
}

int main()
{
    Stack myStack;

    init(&myStack);

    push(&myStack, 10);
    push(&myStack, 4);
    push(&myStack, 3);
    push(&myStack, 2);
    push(&myStack, 9);
    push(&myStack, 1);
    push(&myStack, 8);
    push(&myStack, 7);

    while (!isEmpty(&myStack))
    {
        printf("%d ", top(&myStack));
        pop(&myStack);
    }
    puts("");
    return 0;
}