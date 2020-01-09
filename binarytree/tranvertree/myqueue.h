#ifndef __MY_QUEUE_H
#define __MY_QUEUE_H

#include "binaraytree.h"

#define MAXQUEUESIZE 1024

typedef struct TreeNode * ELEMTYPE;

typedef struct tagMyQueue
{
   int iFront; // pos of first val;
   int iRear; // the next pos of last val;
   ELEMTYPE elems[MAXQUEUESIZE];
}MyQueue;

int InQueue(MyQueue *stQueue, ELEMTYPE elemVal)
{
    int iRet = 0;
    if (iRear >= MAXQUEUESIZE)
    {
        printf("queue is full!\n");
        return -1;
    }
    stQueue->elems[stQueue->iRear] = elemVal;
    stQueue->iRear += 1;
    return iRet;
}

int OutQueue(MyQueue *stQueue, ELEMTYPE *pElem)
{
    int iRet = 0;
    if (stQueue->iFront < 0)
    {
        printf("queue is empty!\n");
        return -1;
    }
    *pElem = stQueue->elems[stQueue->iFront];
    stQueue->iFront += 1;
    return iRet;
}

int isEmpty(MyQueue *stQueue)
{
    if (stQueue->iFront == stQueue->iRear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

#endif
