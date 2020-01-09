#include <stdio.h>
#include "mystack.h"

void InitStack(MyStack *pStack)
{
    pStack->iCurPos = 0;
}

int Push(MyStack *pStack, ELEMTYPE iVal)
{
    int iRet = 0;
    if (pStack->iCurPos < MAXSTACKSIZE)
    {
        pStack->elements[pStack->iCurPos] = iVal;
        pStack->iCurPos += 1;
    }
    else
    {
        printf("Stack is full, cant't push val!\n");
        iRet = -1;
    }
    return iRet;
}

int Pop(MyStack *pStack, ELEMTYPE *pVal)
{
    int iRet = 0;
    if (pStack->iCurPos > 0)
    {
        *pVal = pStack->elements[pStack->iCurPos - 1];
        pStack->iCurPos -= 1;
    }
    else
    {
        printf("Stack is Empty, can't Pop val!\n");
        iRet = -1;
    }
    return iRet;
}

int isEmpty(MyStack *pStack)
{
    if (0 == pStack->iCurPos)
    {
        return 1;
    }
    return 0;
}

int GetTopVal(MyStack *pStack, ELEMTYPE *pVal)
{
    int iRet = 0;
    *pVal = pStack->elements[pStack->iCurPos - 1];
    return iRet;
}
