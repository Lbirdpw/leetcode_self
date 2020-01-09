#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
#include <stdbool.h>

#define MAXSIZE 10240


/**
 *  * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void SwapVal(char *str, int i, int j)
{
    str[i] = str[i] ^ str[j];
    str[j] = str[i] ^ str[j];
    str[i] = str[i] ^ str[j];
}

void reverseStr(char *str, int iSize)
{
    int iStart = 0;
    int iEnd = iSize - 1;
    while (iStart < iEnd)
    {
        SwapVal(str, iStart, iEnd);
        ++iStart;
        --iEnd;
    }
}

int int2Str(char *str, int val)
{
    if (val == 0)
    {
        str[0] = '0';
        return 1;
    }
    int iInd = 0;
    bool bNeg = false;
    if (val < 0)
    {
        val = -val;
        bNeg = true;
    }
    while (val != 0)
    {
        int iTmp = val % 10;
        char ch = iTmp + '0';
        str[iInd++] = ch;
        val = val / 10;
    }
    //printf("bbbb,%s\n", str);
    reverseStr(str, iInd);
    //printf("cccc,%s\n", str);
    if (bNeg)
    {
        int iLen = strlen(str);
        for (int i = iLen; i > 0; --i)
        {
            str[i] = str[i - 1];
        }
        str[0] = '-';
        ++iInd;
    }
    //printf("cccc,%s\n", str);
    return iInd;
}

int GetStr(struct TreeNode* root, char *str, int iInd)
{
    if (root == NULL)
    {
        str[iInd++] = '#';
        str[iInd++] = ',';
        return iInd;
    }
    int iRet = int2Str(str + iInd, root->val);
    //printf("eeee,%s\n", str);
    iInd += iRet;
    str[iInd++] = ','; 
    //printf("aaaaa,%s\n", str);
    iRet = GetStr(root->left, str, iInd);
    return GetStr(root->right, str, iRet);
}



/** Encodes a tree to a single string. */
char* serialize(struct TreeNode* root) {
    char *pStr = (char *)malloc(sizeof(char) * MAXSIZE);
    if (pStr == NULL)
    {
        printf("alloc failed!\n");
    }
    memset(pStr, 0, sizeof(char) * MAXSIZE);
    GetStr(root, pStr, 0);
    int iLen = strlen(pStr);
    pStr[iLen - 1] = '\0'; //strip the last comma
    return pStr;
}

void ParseStr2Int(char *data, int *pArr, int *pArrSize)
{
    int iArrInd = 0;
    char strTmp[MAXSIZE] = {'\0'};
    int iInd = 0;
    bool bDig = true;
    while (*data != '\0')
    {
        if (isdigit(*data) || '-' == *data)
        {
            strTmp[iInd++] = *data;
            bDig = true;
        }
        else if (*data == ',')
        {
            if (bDig)
            {
                pArr[iArrInd++] = atoi(strTmp);
                //printf("bbbb,%d\n", atoi(strTmp));
                memset(strTmp, 0, sizeof(char) * MAXSIZE);
                iInd = 0;
            }
            
        }
        else if (*data == '#')
        {
            pArr[iArrInd++] = INT_MAX;
            bDig = false;
        }
        ++data;
    }
    if (iInd != 0)
    {
        pArr[iArrInd++] = atoi(strTmp);
    }
    *pArrSize = iArrInd;
}

struct TreeNode * BuildTreeFromArray(int *pArr, int pArrSize, int iInd, int *pRetInd)
{
    if (pArr == NULL || pArrSize <= 0 || iInd >= pArrSize)
    {
        return NULL;
    }
    if (pArr[iInd] == INT_MAX)
    {
        *pRetInd = iInd;
        return NULL;
    }
    struct TreeNode *pTree = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    if (pTree == NULL)
    {
        printf("malloc failed!\n");
        return NULL;
    }
    //printf("aaaaaaaaaaaaa%d\n", pArr[iInd]);
    pTree->val = pArr[iInd];
    //int iRetInd = 0;
    pTree->left = BuildTreeFromArray(pArr, pArrSize, iInd + 1, pRetInd);
    pTree->right = BuildTreeFromArray(pArr, pArrSize, (*pRetInd) + 1, pRetInd);
    return pTree;
}

/** Decodes your encoded data to tree. */
struct TreeNode* deserialize(char* data) {
    int Arr[MAXSIZE] = {0};
    int iDataSize = 0;
    
    ParseStr2Int(data, Arr, &iDataSize); 
    int iRetInd = 0;
    return BuildTreeFromArray(Arr, iDataSize, 0, &iRetInd);
}

void Inorder(struct TreeNode *pTree)
{
    if (NULL == pTree)
    {
        return ;
    }
    Inorder(pTree->left);
    printf("%d,", pTree->val);
    Inorder(pTree->right);
}

int main()
{
    char str[] = {"-1,0,#,#,1,#,#"};
    
    struct TreeNode *pTree = deserialize(str);
    Inorder(pTree);
    char *pStr = serialize(pTree);
    printf("\n%s\n", pStr);
    
    return 0;
}
