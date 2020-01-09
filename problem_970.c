#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

int GetPowVal(int num, int iPow)
{
    int iRet = 1;
    for (int i = 0; i < iPow; ++i)
    {
        iRet *= num;
    }
    return iRet;
}

int GetPow(int num , int bound)
{
    if (num == 1)
    {
        return 1;
    }
    int iPow = 0;
    while (GetPowVal(num, iPow) <= bound)
    {
        ++iPow;
    }
    return iPow;
}


int* powerfulIntegers(int x, int y, int bound, int* returnSize) 
{
    int iXPow = GetPow(x, bound); 
    int iYPow = GetPow(y, bound);
    int *pArrRet = (int *)malloc(sizeof(int) * iXPow * iYPow);
    assert(pArrRet != NULL);
    memset(pArrRet, 0, sizeof(int) * iXPow * iYPow);
    int iInd = 0;
    for (int i = 0; i < iXPow; ++i)
    {
        for (int j = 0; j < iYPow; ++j)
        {
            int iVal = GetPowVal(x, i) + GetPowVal(y, j);
            if (iVal <= bound)
            {
                pArrRet[iInd++] = iVal;
            }
        }
    }
    int *Hash = (int *)malloc(sizeof(int) * (bound + 1));
    assert(Hash != NULL);
    memset(Hash, 0, sizeof(int) * (bound + 1));
    for (int i = 0; i < iInd; ++i)
    {
        Hash[pArrRet[i]] += 1;
    }
    iInd = 0;
    for (int i = 0; i <= bound; ++i)
    {
        if (Hash[i] > 0)
        {
            pArrRet[iInd++] = i;
        }
    }
    *returnSize = iInd;
    return pArrRet;
}

int main()
{
    int x = 2;
    int y = 1;
    int bound = 10;
    int iRetSize = 0;
    int *pArrRet = powerfulIntegers(x, y, bound, &iRetSize);
    for (int i = 0; i < iRetSize; ++i)
    {
        printf("%d,", pArrRet[i]);
    }
    printf("\n");
}
