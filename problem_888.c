#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


int GetSum(int *arr, int iSize)
{
    int iSum = 0;
    for (int i = 0; i < iSize; ++i)
    {
        iSum += arr[i];
    }
    return iSum;
}

int* fairCandySwap(int* A, int ASize, int* B, int BSize, int* returnSize) 
{
    int iSumA = GetSum(A, ASize);
    int iSumB = GetSum(B, BSize);
    int iDiff = (iSumA - iSumB) / 2;
    int *arrRet = (int *)malloc(sizeof(int) * 2);
    *returnSize = 2;
    assert(NULL != arrRet);
    memset(arrRet, 0, sizeof(int) * 2);
    for (int i = 0; i < ASize; ++i)
    {
        for (int j = 0; j < BSize; ++j)
        {
            if (iDiff == A[i] - B[j])
            {
                arrRet[0] = A[i];
                arrRet[1] = B[j];
                return arrRet;
            }
        }
    }
    return arrRet;
}

int main()
{
    int a[] = {1,1};
    int asize = sizeof(a) / sizeof(int);
    int b[] = {2,2};
    int bsize = sizeof(b) / sizeof(int);
    int iRetSize = 0;
    int *arrRet = fairCandySwap(a, asize, b, bsize, &iRetSize);
    for (int i = 0; i < iRetSize; ++i)
    {
        printf("%d,", arrRet[i]);
    }
    printf("\n");
    return 0;
}
