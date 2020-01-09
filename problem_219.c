#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

typedef struct tagBinSearchTree
{
    struct tagBinSearchTree *pLeft;
    struct tagBinSearchTree *pRight;
    int iVal;

}BinSearchTree;

void InOrder(BinSearchTree *pTree)
{
    if (pTree == NULL)
    {
        return;
    }
    InOrder(pTree->pLeft);
    printf("%d,", pTree->iVal);
    InOrder(pTree->pRight);
}


BinSearchTree * InsertBST(BinSearchTree *pTree, int iVal)
{
    if (pTree == NULL)
    {
        BinSearchTree *pNode = (BinSearchTree *)malloc(sizeof(BinSearchTree));
        assert(pNode != NULL);
        pNode->pLeft = NULL;
        pNode->pRight = NULL;
        pNode->iVal = iVal;
        return pNode;
    }
    if (pTree->iVal > iVal)
    {
        pTree->pLeft = InsertBST(pTree->pLeft, iVal);
    }
    else if (pTree->iVal < iVal)
    {
        pTree->pRight = InsertBST(pTree->pRight, iVal);
    }
    else
    {
        return pTree;
    }
    return pTree;
}

BinSearchTree * FindVal(BinSearchTree *pTree, int iVal)
{
    if (pTree == NULL)
    {
        return NULL;
    }
    if (pTree->iVal > iVal)
    {
        return FindVal(pTree->pLeft, iVal);
    }
    else if (pTree->iVal < iVal)
    {
        return FindVal(pTree->pRight, iVal);
    }
    else
    {
        return pTree;
    }
}

BinSearchTree * FindMin(BinSearchTree *pTree)
{
    if (pTree == NULL)
    {
        return NULL;
    }
    while (pTree->pLeft != NULL)
    {
        pTree = pTree->pLeft;
    }
    return pTree;
}

BinSearchTree * DeleteVal(BinSearchTree *pTree, int iVal)
{
    if (NULL == pTree)
    {
        printf("%d not exists!\n", iVal);
        return pTree;
    }
    if (pTree->iVal > iVal)
    {
         pTree->pLeft = DeleteVal(pTree->pLeft, iVal);
    }
    else if (pTree->iVal < iVal)
    {
        pTree->pRight = DeleteVal(pTree->pRight, iVal);
    }
    else
    {
        if (pTree->pLeft != NULL && pTree->pRight != NULL)
        {
            BinSearchTree *pTmp = FindMin(pTree->pRight);
            pTree->iVal = pTmp->iVal;
            pTree->pRight = DeleteVal(pTree->pRight, pTmp->iVal);
        }
        else
        {
            BinSearchTree *pTmp = NULL;
            if (pTree->pLeft == NULL)
            {
                pTmp = pTree->pRight;
                free(pTree);
                return pTmp;
            }
            if (pTree->pRight == NULL)
            {
                pTmp = pTree->pLeft;
                free(pTree);
                return pTmp;
            }
        }
    }
    return pTree;
    
}

void InitBST(BinSearchTree **pTree, int *nums, int iSize)
{
    if (iSize == 0)
    {
        printf("arr empty!\n");
        (*pTree) = NULL;
        return;
    }
    (*pTree) = (BinSearchTree *)malloc(sizeof(BinSearchTree));
    assert((*pTree) != NULL);
    (*pTree)->pLeft = NULL;
    (*pTree)->pRight = NULL;
    (*pTree)->iVal = nums[0];
    for (int i = 1; i < iSize; ++i)
    {
        InsertBST(*pTree, nums[i]);
    }
}

bool containsNearbyDuplicate(int* nums, int numsSize, int k) 
{
    if (numsSize <= 0 || k <=0)
    {
        return false;
    }
    int iBSTSize = numsSize < k ? numsSize : k;
    BinSearchTree *pTree = NULL;
    pTree = InsertBST(pTree, nums[0]);
    for (int i = 1; i <= iBSTSize && i < numsSize; ++i)
    {
        BinSearchTree *pTmp = FindVal(pTree, nums[i]);
        if (pTmp != NULL)
        {
            return true;
        }
        pTree = InsertBST(pTree, nums[i]);
    }
    int iInd = 0;
    for (int i = iBSTSize + 1; i < numsSize; ++i)
    {
        pTree = DeleteVal(pTree, nums[iInd]);
        BinSearchTree *pTmp = FindVal(pTree, nums[i]);
        if (pTmp != NULL)
        {
            return true;
        }
        pTree = InsertBST(pTree, nums[i]);
        ++iInd;
    }
    return false;
}

int main()
{
    int arr[] = {1,2,3,1,2,3};
    int k = 2;
    int iArrSize = sizeof(arr) / sizeof(int);
    BinSearchTree *pTree = NULL;
    InitBST(&pTree, arr, iArrSize);
    InOrder(pTree);
    bool bRet = containsNearbyDuplicate(arr, iArrSize, k);
    if (bRet)
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }
    return 0;
}
