#include <stdio.h>
#include <stdbool.h>

#define MAXSTACKSIZE 1024

typedef struct tagMyStack
{
    char arr[MAXSTACKSIZE];
    int iStackPos;
}MyStack;

void InitStack(MyStack *stStack)
{
    stStack->iStackPos = 0;
}

void PushStack(MyStack *stStack, char chVal)
{
    if (stStack->iStackPos >= MAXSTACKSIZE)
    {
        printf("stack full!\n");
        return;
    }
    stStack->arr[stStack->iStackPos] = chVal;
    ++(stStack->iStackPos);
}

char PopStack(MyStack *stStack)
{
    if (stStack->iStackPos == 0)
    {
        printf("stack empty!\n");
        return '\0';
    }
    (--stStack->iStackPos);
    return stStack->arr[stStack->iStackPos];
}

bool IsEmpty(MyStack *stStack)
{
    if (0 == stStack->iStackPos)
    {
        return true;
    }
    return false;
}

bool IsMatch(MyStack *stStack, char chVal)
{
    if (stStack->iStackPos == 0)
    {
        printf("stack empty!\n");
        return false;
    }
    int iPos = stStack->iStackPos - 1;
    if (stStack->arr[iPos] == '(' && chVal == ')')
    {
        return true;
    }
    if (stStack->arr[iPos] == '[' && chVal == ']')
    {
        return true;
    }
    if (stStack->arr[iPos] == '{' && chVal == '}')
    {
        return true;
    }
    return false;
}

bool isValid(char* s) 
{
    MyStack stStack;
    InitStack(&stStack);
    while (*s != '\0') 
    {
        if (*s == '(' || *s == '{' || *s == '[')
        {
            PushStack(&stStack, *s); 
        }
        else
        {
            if (IsMatch(&stStack, *s))
            {
                PopStack(&stStack);
            }
            else
            {
                PushStack(&stStack, *s);
            }
        }
        ++s;
    }
    if (IsEmpty(&stStack))
    {
        return true;
    }
    return false;
}

int main()
{
    char str[] = {"()[]{}"};
    bool bRes = isValid(str);
    if (bRes)
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }
    return 0;
}
