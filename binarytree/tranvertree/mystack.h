#ifndef __MYSTACK_H
#define __MYSTACK_H

#include "binaraytree.h"

#define MAXSTACKSIZE 1024

typedef struct TreeNode * ELEMTYPE;


typedef struct tagMyStack
{
    ELEMTYPE elements[MAXSTACKSIZE];    
    int iCurPos; //point to the next pos of the top val
}MyStack;

void InitStack(MyStack *pStack);

//return 0 means success, -1 means failed
int Push(MyStack *pStack, ELEMTYPE iVal);

//return 0 means success, -1 means failed
int Pop(MyStack *pStack, ELEMTYPE *pVal);

//emtpy return 1, else return 0;
int isEmpty(MyStack *pStack);

//return 0 means success, -1 means failed
int GetTopVal(MyStack *pStack, ELEMTYPE *pVal);

#endif
