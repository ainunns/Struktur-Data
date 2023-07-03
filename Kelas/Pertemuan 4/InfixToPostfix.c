/*
    Kuis 1 - Convert Infix to Postfix
    Nama : Ainun Nadhifah Syamsiyah
    NRP : 5025221053
*/

#include <stdio.h>
#include <string.h>
#define MAX_STACK 100

typedef struct STACK
{
    int top;
    char data[MAX_STACK + 5];
} stack;

struct STACK st;

void init()
{
    st.top = -1;
}

int isEmpty()
{
    return (st.top == -1 ? 1 : 0);
}

void push(char nxt)
{
    st.data[++st.top] = nxt;
}

void pop()
{
    st.top--;
}

char peek()
{
    return st.data[st.top];
}

int ranks(char c)
{
    if (c == '*' || c == '/')
        return 1;
    return 0;
}

int main()
{
    init();
    char str[MAX_STACK + 5];
    scanf("%[^\n]s", str);

    int len = strlen(str), i;
    for (i = 0; i < len; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            printf("%c", str[i]);
        }
        else if (str[i] != ' ')
        {
            while (!isEmpty() && ranks(peek()) >= ranks(str[i]))
            {
                printf("%c", peek());
                pop();
            }
            push(str[i]);
        }
    }
    while (!isEmpty())
    {
        printf("%c", peek());
        pop();
    }
    puts("");
}