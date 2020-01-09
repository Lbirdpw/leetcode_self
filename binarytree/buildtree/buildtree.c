#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/**
 *  * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int GetRootPos(int *arr, int iArrSize, int iVal)
{
    for (int i = 0; i < iArrSize; ++i)
    {
        if (arr[i] == iVal)
        {
            return i;
        }
    }
    return -1;
}

void GetLeftInOrder(int **pInorder, int *pInorderSize, int iRootPos, int* inorder, int inorderSize)
{
    int iLen = iRootPos;
    (*pInorder) = (int *)malloc(sizeof(int) * (iLen));
    if ((*pInorder) == NULL) 
    {
        printf("alloc failed!\n");
        *pInorderSize = 0;
        return;
    }
    memset((*pInorder), 0, sizeof(int) * (iLen));
    for (int i = 0; i < iLen; ++i)
    {
        (*pInorder)[i] = inorder[i];
    }
    *pInorderSize = iLen;
}

void GetRightInOrder(int **pInorder, int *pInorderSize, int iRootPos, int* inorder, int inorderSize)
{
    int iLen = inorderSize - 1 - iRootPos; 
    (*pInorder) = (int *)malloc(sizeof(int) * (iLen));
    if ((*pInorder) == NULL) 
    {
        printf("alloc failed!\n");
        *pInorderSize = 0;
        return;
    }
    memset((*pInorder), 0, sizeof(int) * (iLen));
    for (int i = 0; i < iLen; ++i)
    {
        (*pInorder)[i] = inorder[i + iRootPos + 1];
    }
    *pInorderSize = iLen;
}

void GetLeftPostOrder(int **pPostOrder, int *pPostOrderSize, int iRootPos, int* postorder, int postorderSize)
{
    int iLen = iRootPos;
    (*pPostOrder) = (int *)malloc(sizeof(int) * (iLen));
    if ((*pPostOrder) == NULL) 
    {
        printf("alloc failed!\n");
        *pPostOrderSize = 0;
        return;
    }
    memset((*pPostOrder), 0, sizeof(int) * (iLen));
    for (int i = 0; i < iLen; ++i)
    {
        (*pPostOrder)[i] = postorder[i];
    }
    *pPostOrderSize = iLen;

}

void GetRightPostOrder(int **pPostOrder, int *pPostOrderSize, int iRootPos, int* postorder, int postorderSize)
{
    int iLen = postorderSize - 1 - iRootPos;
    (*pPostOrder) = (int *)malloc(sizeof(int) * (iLen));
    if ((*pPostOrder) == NULL) 
    {
        printf("alloc failed!\n");
        *pPostOrderSize = 0;
        return;
    }
    memset((*pPostOrder), 0, sizeof(int) * (iLen));
    for (int i = 0; i < iLen; ++i)
    {
        (*pPostOrder)[i] = postorder[i + iRootPos];
    }
    *pPostOrderSize = iLen;

}
 

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) 
{
    if (postorderSize == 0) 
    {
        return NULL;
    }
    struct TreeNode *pNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    pNode->val = postorder[postorderSize - 1];
    int iRootPos = GetRootPos(inorder, inorderSize, pNode->val);
    int *pLeftInOrder = NULL;
    int iLeftInOrderSize = 0;
    int *pRightInOrder = NULL;
    int iRightInOrderSize = 0;

    int *pLeftPostOrder = NULL;
    int iLeftPostorderSize = 0;
    int *pRightPostOrder = NULL;
    int iRightPostOrderSize = 0;

    GetLeftInOrder(&pLeftInOrder, &iLeftInOrderSize, iRootPos, inorder, inorderSize);
    GetRightInOrder(&pRightInOrder, &iRightInOrderSize, iRootPos, inorder, inorderSize);
    GetLeftPostOrder(&pLeftPostOrder, &iLeftPostorderSize, iRootPos, postorder, postorderSize);
    GetRightPostOrder(&pRightPostOrder, &iRightPostOrderSize, iRootPos, postorder, postorderSize);
    pNode->left = buildTree(pLeftInOrder, iLeftInOrderSize, pLeftPostOrder, iLeftPostorderSize);
    pNode->right = buildTree(pRightInOrder, iRightInOrderSize, pRightPostOrder, iRightPostOrderSize);
    return pNode;
}

void Inorder(struct TreeNode *pTree)
{
    if (NULL == pTree)
    {
        return;
    }
    Inorder(pTree->left);
    printf("%d,", pTree->val);
    Inorder(pTree->right);
    //printf("\n");
}

int main()
{
    int inorder[] = {9,3,15,20,7};
    int inorderSize = sizeof(inorder) / sizeof(int);
    int postorder[] = {9,15,7,20,3};
    int postorderSize = sizeof(postorder) / sizeof(int);
    struct TreeNode *pTree = buildTree(inorder, inorderSize, postorder, postorderSize);
    Inorder(pTree);
    
    return 0;
}
