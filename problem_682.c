#include <stdiol.h>

typedef STACKMAXSIZE 1024

typedef struct tagMyStack
{
    int arr[STACKMAXSIZE];
    int iEffSize;
}MyStack;

void InitStack(MyStack *pStack)
{
    pStack->iEffSize = 0;
}

int calPoints(char** ops, int opsSize) 
{
        
}
