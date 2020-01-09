#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

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
    vector<vector<int> > levelOrder(TreeNode* root) 
    {
        vector<vector<int> > vecVal;    
        if (!root)
        {
            return vecVal;
        }
        queue<TreeNode *> oMyQueue;
        oMyQueue.push(root);
        int iCurLevelCnt = 1;
        int iNextLevelCnt = 0;
        vector<int> vecLevel;
        while (!oMyQueue.empty())
        {
            TreeNode *pNode = oMyQueue.front();
            oMyQueue.pop();
            --iCurLevelCnt;
            vecLevel.push_back(pNode->val);
            if (pNode->left)
            {
                oMyQueue.push(pNode->left);
                ++iNextLevelCnt;
            }
            if (pNode->right)
            {
                oMyQueue.push(pNode->right);
                ++iNextLevelCnt;
            }
            if (0 == iCurLevelCnt)
            {
                iCurLevelCnt = iNextLevelCnt;
                iNextLevelCnt = 0;
                vecVal.push_back(vecLevel);
                vecLevel.clear();
            }
        }
        return vecVal;

    }
};

int main()
{
    return 0;
}
