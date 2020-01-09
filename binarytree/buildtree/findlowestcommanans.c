#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


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

bool isAns(struct TreeNode* root, struct TreeNode* p)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->val == p->val)
    {
        return true;
    }
    return isAns(root->left, p) || isAns(root->right, p);
}

void GetlowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q, struct TreeNode** pAns)
{
    if (root == NULL)
    {
        //(*pAns) = NULL;
        return;
    }
    if (isAns(root, p) && isAns(root,q))
    {
        (*pAns) = root;
    }
    GetlowestCommonAncestor(root->left, p, q, pAns);
    GetlowestCommonAncestor(root->right, p, q, pAns);
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    struct TreeNode* pFind = NULL;
    GetlowestCommonAncestor(root, p, q, &pFind);
    return pFind;
}

int main()
{
    int inorder[] = {6,5,7,2,4,3,0,1,8};
    int inorderSize = sizeof(inorder) / sizeof(int);
    int preorder[] = {3,5,6,2,7,4,1,0,8};
    int preorderSize = sizeof(preorder) / sizeof(int);
    struct TreeNode *pTree = buildTree(preorder, preorderSize, inorder, inorderSize);
    Inorder(pTree);
    
    struct TreeNode *p = pTree->left;
    struct TreeNode *q = pTree->left->right->right;
    struct TreeNode *pFind = lowestCommonAncestor(pTree, p, q);
    printf("\n%d\n", pFind->val);
    return 0;
}
