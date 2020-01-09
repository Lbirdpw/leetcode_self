#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MINVAL -2147483648

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int CreateTree(struct TreeNode **head, int *pVal, int iSize, int iIndex)
{
    if (iIndex >= iSize || pVal[iIndex] == MINVAL)
    {
        printf("empty val\n");
        *head = NULL;
        return iIndex;
    }
    *head = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    printf("111:%d\n", pVal[iIndex]);
    (*head)->val = pVal[iIndex];
    assert(*head != NULL);
    int iInd = CreateTree(&(*head)->left, pVal, iSize, iIndex + 1);
    iInd = CreateTree(&(*head)->right, pVal, iSize, iInd + 1);
    return iInd;
}

int InOrderTree(struct TreeNode *head, int iIndex)
{
    if (NULL == head)
    {
        
        return iIndex;
    }
    printf("%d\n", head->val);
    int iInd = InOrderTree(head->left, iIndex + 1);
    iInd = InOrderTree(head->right, iInd + 1);
    return iInd;
}

int GetInOrderArray(struct TreeNode *head, int *arr, int iSize, int iIndex)
{
    if (iIndex >= iSize)
    {
        printf("out of size");
        return iIndex;
    }
    if (NULL == head)
    {
        arr[iIndex] = MINVAL;
        return iIndex;
    }
    printf("get:%d\n", head->val);
    arr[iIndex] = head->val;
    int iInd = GetInOrderArray(head->left, arr, iSize, iIndex + 1);
    iInd = GetInOrderArray(head->right, arr, iSize, iInd + 1);
    return iInd;

}

int * MergeArray(int *a, int iASize, int *b, int iBSize, int *iSize)
{
    int *p = NULL;
    *iSize = 0;
    int iMin = 0;
    if (iASize > iBSize)
    {
        p = a;
        *iSize = iASize;
        iMin = iBSize;
    }
    else
    {
        p = b;
        *iSize = iBSize;
        iMin = iASize;
    }
    for (int i = 0; i < iMin; ++i)
    {
        if (a[i] == MINVAL)
        {
            p[i] = b[i];
        }
        else if(b[i] == MINVAL)
        {
            p[i] = a[i];
        }
        else
        {
            p[i] = a[i] + b[i];
        }
    }
    return p;
}

struct TreeNode* mergeTreesA(struct TreeNode* t1, struct TreeNode* t2) 
{
    int iFullSizeA = InOrderTree(t1, 1);
    int iFullSizeB = InOrderTree(t2, 1);

    int *aGet = (int *) malloc(sizeof(int) * iFullSizeA);
    assert(aGet != NULL);
    memset(aGet, 0, iFullSizeA);
    GetInOrderArray(t1, aGet, iFullSizeA, 0);
    int *bGet = (int *) malloc(sizeof(int) * iFullSizeB);
    assert(bGet != NULL);
    memset(bGet, 0, iFullSizeB);
    GetInOrderArray(t2, bGet, iFullSizeB, 0);
    
    int iSize = 0;
    int *p = MergeArray(aGet, iFullSizeA, bGet, iFullSizeB, &iSize);

    for (int i = 0; i < iSize; ++i)
    {
        printf("qqqq:%d\n", p[i]);
    }
        
    struct TreeNode *tRes;
    CreateTree(&tRes, p, iSize, 0);
}


void DoMerge(struct TreeNode *t1, struct TreeNode *t2, struct TreeNode **tmerge)
{
    if (t1 == NULL && t2 == NULL)
    {
        *tmerge = NULL;
        return;
    }
    else if (t1 != NULL && t2 == NULL)
    {
        *tmerge = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        (*tmerge)->val = t1->val;
        printf("merge:%d\n", (*tmerge)->val);
        DoMerge(t1->left, NULL, &((*tmerge)->left));
        DoMerge(t1->right, NULL, &((*tmerge)->right));
        return;
    }
    else if (t1 == NULL && t2 != NULL)
    {
        *tmerge = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        (*tmerge)->val = t2->val;
        printf("merge:%d\n", (*tmerge)->val);
        DoMerge(NULL, t2->left, &((*tmerge)->left));
        DoMerge(NULL, t2->right, &((*tmerge)->right));
        return;
    }
    else
    {
        *tmerge = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        (*tmerge)->val = t1->val + t2->val;
        printf("merge:%d\n", (*tmerge)->val);
        DoMerge(t1->left, t2->left, &((*tmerge)->left));
        DoMerge(t1->right, t2->right, &((*tmerge)->right));
        return;
    }
}

struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2) 
{
    struct TreeNode *pRes;
    DoMerge(t1, t2, &pRes);
    return pRes;
}

int main()
{
    int a[] = {1, 3, 5, MINVAL, MINVAL, MINVAL, 2, MINVAL, MINVAL};
    int b[] = {2, 1, MINVAL, 4, MINVAL, MINVAL, 3, MINVAL, 7, MINVAL, MINVAL};
    struct TreeNode *treeA = NULL;
    CreateTree(&treeA, a, 9, 0);


    struct TreeNode *treeB = NULL;
    CreateTree(&treeB, b, 11, 0);

    struct TreeNode *pResTree = mergeTrees(treeA, treeB);
    int iFullSize = InOrderTree(pResTree, 1);
    printf("%d\n", iFullSize);

    return 0;
}

