#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include "mystack.h"
#include "binaraytree.h"



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

int main()
{
    printf("abc\n");
    int Arr[] = {1,2,3,INT_MAX, INT_MAX, INT_MAX, 4, INT_MAX, 5, INT_MAX, INT_MAX};
    int iSize = sizeof(Arr) / sizeof(int);
//printf("abc\n");
    struct TreeNode *pTree = BuildTree(Arr, iSize);
//printf("abc\n");
    PreOrder(pTree);
printf("\n");
    int iRetSize = 0;
    int *arrRet = preorderTraversal(pTree, &iRetSize);
//printf("abc\n");
    for (int i = 0; i < iRetSize; ++i)
    {
        printf("%d,", arrRet[i]);
    }
    printf("\n");
    return 0;
}
