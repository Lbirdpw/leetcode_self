#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>



typedef struct tagHeapNode
{
    char ch;
    int iCnt;
}HeapNode;

typedef struct tagMinHeap
{
    int iHeapSize;
    HeapNode nodes[256];
}MinHeap;

void InitHeap(MinHeap *pHeap)
{
    pHeap->iHeapSize = 0;
    for (int i = 0; i < 256; ++i)
    {
        pHeap->nodes[i].ch = '\0';
        pHeap->nodes[i].iCnt = 0;
    }
}


void GetHash(char *s, int *arHash)
{
    while (*s != '\0')
    {
        int iVal = (int)(*s);
        if (iVal < 256)
        {
        arHash[iVal] += 1;
        }
        ++s;
    }
}

void SwapHeapNode(HeapNode *pNode1, HeapNode *pNode2)
{
    HeapNode tmpNode;
    tmpNode.ch = pNode1->ch;
    tmpNode.iCnt = pNode1->iCnt;

    pNode1->ch = pNode2->ch;
    pNode1->iCnt = pNode2->iCnt;

    pNode2->ch = tmpNode.ch;
    pNode2->iCnt = tmpNode.iCnt;
}

void BuildMinHeap(HeapNode *pHeap, int iSize)
{
    int iFirstNoLeaf = (iSize / 2) - 1;
    for (int i = iFirstNoLeaf; i >= 0; --i)
    {
        int iLeft = 2 * i + 1;
        int iRight = 2 * i + 2;
        int iMin = pHeap[i].iCnt;
        int iMinInd = i;
        if (iLeft < iSize && iMin > pHeap[iLeft].iCnt)
        {
            iMinInd = iLeft;
            iMin = pHeap[iLeft].iCnt;
        }
        if (iRight < iSize && iMin > pHeap[iRight].iCnt)
        {
            iMinInd = iRight;
            iMin = pHeap[iRight].iCnt;
        }
        if (iMinInd != i)
        {
            SwapHeapNode(pHeap + iMinInd, pHeap + i);
        }
    }
}

void PrintHeap(HeapNode *pHeap, int iSize)
{
    for (int i = 0; i < iSize; ++i)
    {
        printf("%c:%d,", pHeap[i].ch, pHeap[i].iCnt);
    }
    printf("\n");
}

void MinHeapSort(HeapNode *pHeap, int iSize)
{
    //PrintHeap(pHeap, iSize);
    for (int i = iSize - 1; i > 0; --i)
    {
        SwapHeapNode(pHeap + i, pHeap);
        BuildMinHeap(pHeap, i);
        //PrintHeap(pHeap, iSize);
    }
}

void BuildSortStr(HeapNode *pHeap, int iSize, char *str, int iLenStr)
{
    int iInd = 0;
    for (int i = 0; i < iSize; ++i)
    {
        int iLen = pHeap[i].iCnt;
        char ch = pHeap[i].ch;
        for (int j = 0; j < iLen; ++j)
        {
            if (iInd < iLenStr)
            {
                str[iInd++] = ch;
            }
        }
    }
}

char* frequencySort(char* s) 
{
    int iLen = strlen(s);
    
    int arHash[256] = {0};
    GetHash(s, arHash);
    MinHeap stHeap;
    InitHeap(&stHeap);
    for (int i = 0; i < 256; ++i)
    {
        if (arHash[i] > 0 && stHeap.iHeapSize < 256)
        {
            stHeap.nodes[stHeap.iHeapSize].ch = i;
            stHeap.nodes[stHeap.iHeapSize].iCnt = arHash[i];
            stHeap.iHeapSize += 1;
        }
    }
    BuildMinHeap(stHeap.nodes, stHeap.iHeapSize);
    MinHeapSort(stHeap.nodes, stHeap.iHeapSize);
    char *pstr = (char *)malloc(sizeof(char) * (iLen + 1));
    assert(pstr != NULL);
    memset(pstr, 0, sizeof(char) * (iLen + 1));
    BuildSortStr(stHeap.nodes, stHeap.iHeapSize, pstr, iLen + 1);
    return pstr;
}

int main()
{
    char *str = "cccaaa";
    char *pStr = frequencySort(str);
    printf("%s\n", pStr);
    return 0;
}
