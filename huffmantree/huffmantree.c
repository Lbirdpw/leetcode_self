#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#define MAXBIT 100
#define MAXVALUE 10000
#define MAXLEAF 30
#define MAXNODE MAXLEAF * 2 - 1

typedef struct
{
    int bit[MAXBIT];
    int iStart;
}HuffCode;

typedef struct
{
    int iLeftChild;
    int iRightChild;
    int iParent;
    int iWeight;
    int iValue;
}HuffNode;



void GetMaxTwo(HuffNode *tree, int iSize, int *iInd1, int *iInd2)
{
    *iInd1 = -1;
    *iInd2 = -1;
    int iMin = MAXVALUE;
    for (int i = 0; i < iSize; ++i)
    {
        if (tree[i].iParent == -1 && tree[i].iWeight < iMin)
        {
            iMin = tree[i].iWeight;
            *iInd1 = i;
        }
    }
    iMin = MAXVALUE;
    for (int i = 0; i < iSize; ++i)
    {
        if (i != *iInd1)
        {
            if (tree[i].iParent == -1 && tree[i].iWeight < iMin)
            {
                iMin = tree[i].iWeight;
                *iInd2 = i;
            }
        }
    }
}

void HuffmanTree(HuffNode *tree, int iSize)
{
    //int iTotalNodeCnt = 2 * iSize - 1;
    for (int i = 0; i < iSize; ++i)
    {
        int iInd1 = -1;
        int iInd2 = -1;
        GetMaxTwo(tree, iSize + i, &iInd1, &iInd2);
        printf("iInd1:%d, iInd2:%d\n", iInd1, iInd2);
        if (iInd1 != -1 && iInd2 != -1)
        {
            //printf("iInd1:%d, iInd2:%d\n", iInd1, iInd2);
            tree[iSize + i].iWeight = tree[iInd1].iWeight + tree[iInd2].iWeight;
            tree[iSize + i].iLeftChild = iInd1;
            tree[iSize + i].iRightChild = iInd2;
            tree[iInd1].iParent = iSize + i;
            tree[iInd2].iParent = iSize + i;
        }
    }
}

void GetHuffCode(HuffNode *tree, int iLeafSize, HuffCode *pCode, int *CodeSize)
{
    for (int i = 0; i < iLeafSize; ++i)
    {
        int iParent = tree[i].iParent;
        pCode[i].iStart = iLeafSize;
        int iTmp = i;
        while (iParent != -1)
        {
            if (tree[iParent].iLeftChild == iTmp)
            {
                pCode[i].bit[pCode[i].iStart] = 0;
            }
            else
            {
                pCode[i].bit[pCode[i].iStart] = 1;
            }
            pCode[i].iStart = pCode[i].iStart - 1;
            iTmp = iParent;
            iParent = tree[iParent].iParent;
        }
        pCode[i].iStart = pCode[i].iStart + 1;
    }
}

void CreateTree(HuffNode **pTree, int iSize)
{
    (*pTree) = (HuffNode *)malloc(iSize * sizeof(HuffNode));
    assert((*pTree) != NULL);
}

void InitTree(HuffNode *pTree, int iSize)
{
    for (int i = 0; i < iSize; ++i)
    {
        pTree[i].iLeftChild = -1;
        pTree[i].iRightChild = -1;
        pTree[i].iParent = -1;
        pTree[i].iWeight = MAXVALUE;
        pTree[i].iValue = MAXVALUE;
    }
}

void AddLeaf(HuffNode *pTree, int *arrVal, int *arrWeight, int iLeafSize)
{
    for (int i = 0; i < iLeafSize; ++i)
    {
        pTree[i].iWeight = arrWeight[i];
        pTree[i].iValue = arrVal[i];
    }
}

void DestoryTree(HuffNode **pTree)
{
    free(*pTree);
    *pTree = NULL;
}

void CreateHuffCode(HuffCode **pCode, int iLeafSize)
{
    (*pCode) = (HuffCode *)malloc(sizeof(HuffCode) * iLeafSize);
    assert((*pCode) != NULL);
    memset(*pCode, 0, sizeof(HuffCode) * iLeafSize);
}

void DestoryCode(HuffCode **pCode)
{
    free(*pCode);
    (*pCode) = NULL;
}

void PrintCode(HuffNode *pTree, HuffCode *pCode, int iLeafSize)
{
    for (int i = 0; i < iLeafSize; ++i)
    {
        int iVal = pTree[i].iValue;
        int iWeight = pTree[i].iWeight;
        printf("val:%d, weight: %d, code:", iVal, iWeight);
        for (int j = pCode[i].iStart; j <= iLeafSize; ++j)
        {
            printf("%d", pCode[i].bit[j]);
        }
        printf("\n");
    }
}

int main()
{
    int arrVal[] = {1,2,3,4}; 
    int arrWeight[] = {1, 2, 3, 4};
    int iLen = sizeof(arrVal) / sizeof(int);
    int iTreeSize = 2 * iLen - 1;
    HuffNode *pNodeTree = NULL;
    CreateTree(&pNodeTree, iTreeSize);
    InitTree(pNodeTree, iTreeSize);
    AddLeaf(pNodeTree, arrVal, arrWeight, iLen);
    HuffmanTree(pNodeTree, iLen);

    HuffCode *pCode = NULL;
    CreateHuffCode(&pCode, iLen);
    int iCodeSize;
    GetHuffCode(pNodeTree, iLen, pCode, &iCodeSize);
    
    PrintCode(pNodeTree, pCode, iLen);
    DestoryCode(&pCode);
    DestoryTree(&pNodeTree);
    return 0;
}
