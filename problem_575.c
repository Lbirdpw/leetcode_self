#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#define ARRSIZE 128
#define INTARRSIZE 27
#define RETSIZE 10

typedef struct tagBSTNode
{
    int key;
    int val;
    struct tagBSTNode *pLeft;
    struct tagBSTNode *pRight;
}BSTNode;

void InitBSTTree(BSTNode **BSTTree)
{
    *BSTTree = NULL;
}

void InsertData(BSTNode **BSTTree, int key)
{
    if (*BSTTree == NULL)
    {
        (*BSTTree) = (BSTNode *)malloc(sizeof(BSTNode));
        assert((*BSTTree) != NULL);
        (*BSTTree)->key = key;
        (*BSTTree)->val = 1;
        (*BSTTree)->pLeft = NULL;
        (*BSTTree)->pRight = NULL;
        return;
    }
    else
    {
        BSTNode *pTmp = *BSTTree;
        if (pTmp->key < key)
        {
            InsertData(&(pTmp->pRight), key);
        }
        else if (pTmp->key > key)
        {
            InsertData(&(pTmp->pLeft), key);
        }
        else
        {
            pTmp->val += 1;
        }
    }
}

int FindVal(BSTNode *BSTTree, int val)
{
    if (NULL == BSTTree)
    {
        return 0;
    }
    if (BSTTree->key > val)
    {
        return FindVal(BSTTree->pLeft, val);
    }
    else if (BSTTree->key < val)
    {
        return FindVal(BSTTree->pRight, val);
    }
    else
    {
        return BSTTree->val;
    }
}

void InOrder(BSTNode *BSTTree)
{
    if (BSTTree == NULL)
    {
        return;
    }
    InOrder(BSTTree->pLeft);
    printf("key:%d,val:%d\n", BSTTree->key, BSTTree->val);
    InOrder(BSTTree->pRight);
}

int GetNodeCnt(BSTNode *BSTTree)
{
    if (BSTTree == NULL)
    {
        return 0;
    }
    else if (BSTTree->pLeft == NULL && BSTTree->pRight == NULL)
    {
        return 1;
    }
    else
    {
        int iLeftCnt = GetNodeCnt(BSTTree->pLeft);
        int iRightCnt = GetNodeCnt(BSTTree->pRight);
        return 1 + iLeftCnt + iRightCnt;
    }
}

void unInit(void **pArr, int iArrSize)
{
    for (int i = 0; i < iArrSize; ++i)
    {
        free(pArr[i]);
    }
    free(pArr);
}

int distributeCandies(int* candies, int candiesSize) 
{
    BSTNode *BSTTree = NULL;
    InitBSTTree(&BSTTree);
    for (int i = 0; i < candiesSize; ++i)        
    {
        InsertData(&BSTTree, candies[i]);
    }
    //InOrder(BSTTree);
    int iCnt = GetNodeCnt(BSTTree);
    //printf("icnt:%d\n", iCnt);
    iCnt = iCnt < (candiesSize / 2)? iCnt : (candiesSize / 2);
    return iCnt;
}



void printArr(void **pArr, int iTypeSize, int iArrSize, int iType)
{
    printf("size:%d\n", iArrSize);
    if (1 == iType)
    {
        for (int i = 0; i < iArrSize; ++i)
        {
            printf("%s\n", pArr[i]);
        }
    }
    else if(2 == iType)
    {
    }
}

int main()
{
   int a[] = {1,1,2,2,3,3};
   int iLen = sizeof(a) / sizeof(int); 

   int iRet = distributeCandies(a, iLen);
   printf("%d\n", iRet);
   return 0;
}
