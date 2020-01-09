#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

int* sortedSquares(int* A, int ASize, int* returnSize) 
{
    int *arRet = (int *)malloc(sizeof(int) * ASize);
    assert(arRet != NULL);
    memset(arRet, 0, sizeof(int) * ASize);
    int iInd = 0;
    for (int i = 0; i < ASize; ++i)
    {
        int j = i;
        bool bIn = false;
        for (j = i; j < iInd; ++j)
        {
            if (abs(A[i]) == arRet[j])
            {
                bIn = true;
                break;
            }
        }
        if (!bIn)
        {
            int k = iInd - 1;
            while (k >= 0 && arRet[k] > abs(A[i]))
            {
                arRet[k + 1] = arRet[k];
                --k;
            }
            arRet[k + 1] = abs(A[i]);
            ++iInd;
        }
    }
    for (int i = 0; i < iInd; ++i)
    {
        arRet[i] = arRet[i] * arRet[i];
    }
    *returnSize = iInd;
    return arRet;
}

int main()
{
    int a[] = {-4,-1,0,3,10};
    int iRetSize = 0;
    int *p = sortedSquares(a, 5, &iRetSize);
    for (int i = 0; i < iRetSize; ++i)
    {
        printf("%d\n", p[i]);
    }
    printf("\n");
}
