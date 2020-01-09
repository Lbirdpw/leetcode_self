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


 

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) 
{
    if (preorderSize == 0) 
    {
        return NULL;
    }
    struct TreeNode *pNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    pNode->val = preorder[0];
    int iRootPos = GetRootPos(inorder, inorderSize, pNode->val);
    
    
    pNode->left = buildTree(preorder  + 1, iRootPos, inorder, iRootPos);
    pNode->right = buildTree(preorder + iRootPos + 1, preorderSize - 1 - iRootPos, inorder + iRootPos + 1, inorderSize - 1 - iRootPos);
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
    int preorder[] = {3,9,20,15,7};
    int preorderSize = sizeof(preorder) / sizeof(int);
    struct TreeNode *pTree = buildTree(preorder, preorderSize, inorder, inorderSize);
    Inorder(pTree);
    
    return 0;
}
