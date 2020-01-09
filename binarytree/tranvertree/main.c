#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
//#include <unistd.h>
//#include "mystack.h"
//#include "binaraytree.h"

#define MAXSTACKSIZE 1024
#define MAXQUEUESIZE 1024

struct TreeNode 
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct TreeNode * ELEMTYPE;

typedef struct tagMyQueue
{
   int iFront; // pos of first val;
   int iRear; // the next pos of last val;
   ELEMTYPE elems[MAXQUEUESIZE];
}MyQueue;


typedef struct tagMyStack
{
    ELEMTYPE elements[MAXSTACKSIZE];    
    int iCurPos; //point to the next pos of the top val
}MyStack;

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



void InitQueue(MyQueue *stQueue)
{
    stQueue->iFront = 0;
    stQueue->iRear = 0;
}

int InQueue(MyQueue *stQueue, ELEMTYPE elemVal)
{
    int iRet = 0;
    if (stQueue->iRear >= MAXQUEUESIZE)
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

int isEmptyQueue(MyQueue *stQueue)
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

struct TreeNode * BuildTree(int *pVal, int iSize)
{
    static int iIndex = -1;
    ++iIndex;
    if (iIndex >= iSize || pVal[iIndex] == INT_MAX)    
    {
        return NULL;
    }
    struct TreeNode *pTree = NULL;
    pTree = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (pTree == NULL)
    {
        printf("malloc failed!\n");
        return NULL;
    }
    pTree->val = pVal[iIndex];
    pTree->left = BuildTree(pVal, iSize);
    pTree->right = BuildTree(pVal, iSize);
    return pTree;
}

void PreOrder(struct TreeNode *pNode)
{
    if (pNode == NULL)
    {
        return;
    }
    printf("%d,", pNode->val);
    PreOrder(pNode->left);
    PreOrder(pNode->right);
}
 
void InOrder(struct TreeNode *pNode)
{
    if (pNode == NULL)
    {
        return;
    }
    PreOrder(pNode->left);
    printf("%d,", pNode->val);
    PreOrder(pNode->right);
}

//alloce ints of number iSize
int *MyMalloc(int iSize)
{
    int *arrRet = (int *)malloc(sizeof(int) * iSize);
    if (arrRet == NULL)
    {
        printf("alloc failed!\n");
        return NULL;
    }
    memset(arrRet, 0, sizeof(int) * iSize);
    return arrRet;

}

/**
Return an array of size *returnSize.
Note: The returned array must be malloced, assume caller calls free().
*/
int* preorderTraversal(struct TreeNode* root, int* returnSize) 
{
    if (root == NULL)
    {
        return NULL;
    }
    int *arrRet = (int *)malloc(sizeof(int) * MAXSTACKSIZE);
    if (arrRet == NULL)
    {
        printf("alloc failed!\n");
        return NULL;
    }
    memset(arrRet, 0, sizeof(int) * MAXSTACKSIZE);
    MyStack stStack;
    InitStack(&stStack);
    int iInd = 0;
    //printf("abc\n");
    while (root != NULL)
    {
        Push(&stStack, root);
        arrRet[iInd++] = root->val;
        //printf("%d,", root->val);
        root = root->left;
    }
//printf("abc\n");
    while (!isEmpty(&stStack))
    {
        ELEMTYPE pVal = NULL;
        Pop(&stStack, &pVal);
//printf("%d\n", pVal->val);
        ELEMTYPE pNow = pVal->right;
        while (pNow != NULL)
        {
            Push(&stStack, pNow);
            arrRet[iInd++] = pNow->val;
            //printf("%d\n", pNow->val);
            pNow = pNow->left;
        }
    }
//printf("abc\n");
    *returnSize = iInd;
    return arrRet;
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) 
{
    if (root == NULL)
    {
        *returnSize = 0;
        return NULL;
    }
    int *arrRet = MyMalloc(MAXSTACKSIZE);
    MyStack stStack;
    InitStack(&stStack);
    struct TreeNode *pNode = root;
    while (pNode != NULL)
    {
        Push(&stStack, pNode);
        pNode = pNode->left;
    }
    int iInd = 0;
    while (!isEmpty(&stStack))
    {
        struct TreeNode *pVal = NULL;
        Pop(&stStack, &pVal);
        arrRet[iInd++] = pVal->val;
        struct TreeNode *pNode = pVal->right;
        while (pNode != NULL)
        {
            Push(&stStack, pNode);
            pNode = pNode->left;
        }
    }
    *returnSize = iInd;
    return arrRet;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize) 
{
    if (root == NULL)
    {
        *returnSize = 0;
        return NULL;
    }
    int *arrRet = MyMalloc(MAXSTACKSIZE);
    MyStack stStack;
    InitStack(&stStack);
    struct TreeNode *pNode = root;
    while (pNode != NULL)
    {
        Push(&stStack, pNode);
        pNode = pNode->left;
    }   
    int iInd = 0;
    struct TreeNode *pPre = NULL;
    while (!isEmpty(&stStack))
    {
        struct TreeNode *pVal = NULL;
        GetTopVal(&stStack, &pVal);
        struct TreeNode *pNow = pVal->right;
        if (pNow == NULL || (pNow != NULL && pNow == pPre))
        {
            Pop(&stStack, &pPre);
            arrRet[iInd++] = pPre->val;
            //sleep(1);
            //printf("%d,", pPre->val);
        }
        else
        {
            while (pNow != NULL)
            {
                Push(&stStack, pNow);
                pNow = pNow->left;
            }
        }
    }
    *returnSize = iInd;
    return arrRet;
}

int **MyMallocMatrix(int iRowSize, int iColSize)
{
    int **pMatrix = (int **)malloc(sizeof(int *) * iRowSize);
    if (pMatrix == NULL)
    {
        printf("alloc failed!\n");
        return NULL;
    }
    for (int i = 0; i < iRowSize; ++i)
    {
        pMatrix[i] = (int *)malloc(sizeof(int) * iColSize);
        if (pMatrix[i] == NULL)
        {
            printf("alloc failed!\n");
            return NULL;
        }
        memset(pMatrix[i], 0, sizeof(int) * iColSize);
    }
    return pMatrix;
}

int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
    if (root == NULL) 
    {
        return NULL;
    }
    int **pMatrix = MyMallocMatrix(100, MAXQUEUESIZE);
    (*columnSizes) = MyMalloc(MAXQUEUESIZE);
    MyQueue stQueue;
    InitQueue(&stQueue);
    InQueue(&stQueue, root);
    int iCurLevel = 1;
    int iNextVal = 0;
    int iRowInd = 0;
    int iColInd = 0;
    while (!isEmptyQueue(&stQueue))
    {
        struct TreeNode *pNode = NULL;
        OutQueue(&stQueue, &pNode);
        pMatrix[iRowInd][iColInd++] = pNode->val;
        --iCurLevel;
        if (pNode->left != NULL)
        {
            InQueue(&stQueue, pNode->left);
            ++iNextVal;
        }
        if (pNode->right != NULL)
        {
            InQueue(&stQueue, pNode->right);
            ++iNextVal;
        }
        if (iCurLevel == 0)
        {
            iCurLevel = iNextVal;
            iNextVal = 0;
            (*columnSizes)[iRowInd] = iColInd;
            ++iRowInd;
            iColInd = 0;
        }

    }
    *returnSize = iRowInd;
    return pMatrix;
}

int main()
{
    printf("abc\n");
    int Arr[] = {1,2,3,INT_MAX, INT_MAX, INT_MAX, 4, INT_MAX, 5, INT_MAX, INT_MAX};
    int iSize = sizeof(Arr) / sizeof(int);
//printf("abc\n");
    struct TreeNode *pTree = BuildTree(Arr, iSize);
//printf("abc\n");
    //PreOrder(pTree);
printf("\n");
    //int iRetSize = 0;
    //int *arrRet = preorderTraversal(pTree, &iRetSize);
//printf("abc\n");
    //int *arrRet = postorderTraversal(pTree, &iRetSize);
    int *columnSizes = NULL;
    int returnSize = 0;
    int **pMatrix = levelOrder(pTree, &columnSizes, &returnSize);
    for (int i = 0; i < returnSize; ++i)
    {
        for (int j = 0; j < columnSizes[i]; ++j)
        {
            printf("%d,", pMatrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}
