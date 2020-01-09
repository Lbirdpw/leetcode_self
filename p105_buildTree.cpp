#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;


 // Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int FindRootPos(vector<int> &vecVal, int iStart, int iEnd, int iVal)
    {
        int iPos = -1;
        int iSize = vecVal.size();
        for (int i = iStart; i < iEnd; ++i)
        {
            if (iVal == vecVal[i])
            {
                return i;
            }
        }
        return iPos;
    }

    TreeNode *dfsImpl(vector<int> &preorder, int iPreStart, int iPreEnd, vector<int> &inorder, int iInStart, int iInEnd)
    {
        if (iPreStart >= iPreEnd || iInStart >= iInEnd)
        {
            return NULL;
        }
        TreeNode *pRoot = new TreeNode(preorder[iPreStart]);
        if (NULL == pRoot)
        {
            printf("alloc error!\n");
            exit(-1);
        }
        int iPos = FindRootPos(inorder, iInStart, iInEnd, pRoot->val);
        if (iPos != -1)
        {
            printf("%d\n", iPos);
            int iLen = iPos - iInStart;
            pRoot->left = dfsImpl(preorder, iPreStart + 1, iPreStart + 1 + iLen, inorder, iInStart, iPos);
            pRoot->right = dfsImpl(preorder, iPreStart + 1 + iLen, iPreEnd,  inorder, iPos + 1, iInEnd);
        }
        else
        {
            //printf("FindRootPos error!\n");
            //exit(-2);
        }
        return pRoot;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        TreeNode *pRoot = NULL; 
        pRoot = dfsImpl(preorder, 0, preorder.size(), inorder, 0, inorder.size());
        return pRoot;
    }

    void PreOrder(TreeNode *pRoot)
    {
        if (!pRoot)
        {
            return;
        }
        printf("%d,", pRoot->val);
        PreOrder(pRoot->left);
        PreOrder(pRoot->right);
    }
};

int main()
{
    int arrPre[] = {3,9,20,15,7};
    int iPreSize = sizeof(arrPre) / sizeof(arrPre[0]);
    int arrIn[] = {9, 3, 15, 20, 7};
    int iInSize = sizeof(arrIn) / sizeof(arrIn[0]);
    vector<int> vecPre(arrPre, arrPre + iPreSize);
    vector<int> vecIn(arrIn, arrIn + iInSize);
    Solution obj;
    TreeNode *pRoot = obj.buildTree(vecPre, vecIn);
    obj.PreOrder(pRoot);
    printf("\n");
    
    return 0;
}
