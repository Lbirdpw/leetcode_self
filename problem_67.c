#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void swap(char *pStr, int i, int j)
{
    pStr[i] = pStr[i] ^ pStr[j];
    pStr[j] = pStr[i] ^ pStr[j];
    pStr[i] = pStr[i] ^ pStr[j];
}

void ReverseStr(char *pStr, int iSize)
{
    int i = 0; 
    int j = iSize - 1;
    while (i < j)
    {
        swap(pStr, i, j);
        ++i;
        --j;
    }
}

char* addBinary(char* a, char* b) 
{
    int iLenA = strlen(a);        
    int iLenB = strlen(b);        
    int iLen = iLenA > iLenB? iLenA : iLenB;
    iLen += 10;
    char *pRetStr = (char *)malloc(sizeof(char) * iLen);
    assert(pRetStr != NULL);
    memset(pRetStr, 0, iLen);

    int iInc = 0;
    int i = iLenA - 1;
    int j = iLenB - 1;
    int iInd = 0;
    while (i >=0 && j >= 0)
    {
        int iSum = (a[i] - '0') + (b[j] - '0') + iInc;
        pRetStr[iInd++] = (iSum % 2) + '0';
        iInc = iSum / 2;
        --i;
        --j;
    }
    while (i >= 0)
    {
        int iSum = (a[i] - '0') + iInc;
        pRetStr[iInd++] = (iSum % 2) + '0';
        iInc = iSum / 2;
        --i;
    }
    while (j >= 0)
    {
        int iSum = (b[j] - '0') + iInc;
        pRetStr[iInd++] = (iSum % 2) + '0';
        iInc = iSum / 2;
        --j;
    }
    if (iInc != 0)
    {
        pRetStr[iInd++] = iInc + '0';
    }
    ReverseStr(pRetStr, iInd);
    return pRetStr;
}

int main()
{
    char a[] = {"11"};
    char b[] = {"1"};
    char *pRetStr = addBinary(a, b);
    printf("%s\n", pRetStr);
    free(pRetStr);
    return 0;
}
