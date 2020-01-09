#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#define ARRSIZE 128
#define INTARRSIZE 27
#define RETSIZE 10

typedef struct tagBSTNode
{
    char key;
    int val;
    struct tagBSTNode *pLeft;
    struct tagBSTNode *pRight;
}BSTNode;

void InitBSTTree(BSTNode **BSTTree)
{
    *BSTTree = NULL;
}

void InsertData(BSTNode **BSTTree, char key)
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
    printf("key:%c,val:%d\n", BSTTree->key, BSTTree->val);
    InOrder(BSTTree->pRight);
}

void unInit(void **pArr, int iArrSize)
{
    for (int i = 0; i < iArrSize; ++i)
    {
        free(pArr[i]);
    }
    free(pArr);
}

char **InitStr(int iTypeSize, int iArrSize, int iInSize)
{
    char **pArr = (char **)malloc(sizeof(char *) * iArrSize);
    assert(pArr != NULL);
    for (int i = 0; i < iArrSize; ++i)
    {
        pArr[i] = (char *)malloc(sizeof(char) * iInSize);
        assert(pArr[i] != NULL);
        memset(pArr[i], 0, sizeof(char) * iInSize);
    }
    return pArr;
}

char** commonChars(char** A, int ASize, int* returnSize) 
{
    BSTNode ** pArrBST = (BSTNode **)malloc(sizeof(BSTNode *) * ASize);
    assert(pArrBST != NULL);
    for (int i = 0; i < ASize; ++i)
    {
        InitBSTTree(&pArrBST[i]);        
        char *p = A[i];
        while (*p != '\0')
        {
            InsertData(&pArrBST[i], *p);
            ++p;
        }
    }
    //InOrder(pArrBST[0]);
    //InOrder(pArrBST[1]);
    //InOrder(pArrBST[2]);
    char **pRes = InitStr(sizeof(char), ARRSIZE, RETSIZE);
    int iInd = 0;
    for(char ch = 'a'; ch <= 'z'; ++ch)
    {
        int iMin = -1;
        for (int i = 0; i < ASize; ++i)
        {
            int iVal = FindVal(pArrBST[i], ch);
            if (-1 == iMin)
            {
                iMin = iVal;
            }
            else
            {
                iMin = iMin > iVal? iVal : iMin;
            }
        }
        for (int i = 0; i < iMin; ++i)
        {
            pRes[iInd++][0] = ch;
        }
    }
    *returnSize = iInd;
    return pRes;
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
    int iTypeSize = 1;
    int iArrSize = 3;
    char **pArr = (char **)InitStr(iTypeSize, iArrSize, ARRSIZE);
    strcpy(pArr[0], "bella");
    strcpy(pArr[1], "label");
    strcpy(pArr[2], "roller");
    printArr((void **)pArr, 1, 3, 1);


    int iRetSize = 0;
    char **pGet = commonChars(pArr, iArrSize, &iRetSize);
    printArr((void **)pGet, sizeof(char), iRetSize, 1);
    return 0;
}
