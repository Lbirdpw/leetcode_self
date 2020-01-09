#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

bool isAnagram(char *s, char *p)
{
    bool bFlag = true;
    int a[256] = {0};
    char *pStr = p;
    while (*pStr != '\0')
    {
        a[*pStr] += 1;
        ++pStr;
    }
    int iLenP = strlen(p);
    for (int i = 0; i < iLenP; ++i)
    {
        a[s[i]] -= 1;
    }
    for (int i = 0; i < 256; ++i)
    {
        if (a[i] != 0)
        {
            return false;
        }
    }
    return bFlag;
}



int* findAnagrams(char* s, char* p, int* returnSize) 
{ 
    int iLenS = strlen(s);
    int iLenP = strlen(p);
    if (iLenS < iLenP)
    {
        return NULL;
    }
    int *pRet = (int *)malloc(sizeof(int) * iLenS);
    assert(pRet != NULL);
    memset(pRet, 0, sizeof(int) * iLenS);
    int iInd = 0;
    for (int i = 0; i <= iLenS - iLenP; ++i)
    {
        if (isAnagram(s + i, p))
        {
            pRet[iInd++] = i;
        }
    }
    *returnSize = iInd;
    return pRet;
}

int main()
{
    char s[] = {"cbaebabacd"};
    char p[] = {"abc"};
    int iRetSize = 0;
    int *pRet = findAnagrams(s, p, &iRetSize);
    for (int i = 0; i < iRetSize; ++i)
    {
        printf("%d,", pRet[i]);
    }
    printf("\n");
    return 0;
}
