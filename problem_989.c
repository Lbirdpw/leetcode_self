#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define RETSIZE 20

void PrintArr(int *arr, int iSize)
{
    for (int i = 0; i < iSize; ++i)
    {
        printf("%d,", arr[i]);
    }
    printf("\n");
}

int* addToArrayForm(int* A, int ASize, int K, int* returnSize) 
{
    int *arrRet = (int *)malloc(sizeof(int) * RETSIZE);
    assert(arrRet != NULL);
    memset(arrRet, 0, sizeof(int) * RETSIZE);
    int iInd = RETSIZE - 1;
    int iOver = 0;
    int iIndA = ASize - 1;
    while (K != 0 && iIndA >= 0)
    {
        int iBit = K % 10;
        int iBitAdd = (A[iIndA]  + iBit + iOver) % 10;
        iOver = (A[iIndA] + iBit + iOver) / 10;
        arrRet[iInd--] = iBitAdd;
        K = K / 10;
        --iIndA;
        //PrintArr(arrRet, RETSIZE);
    }
    while (iIndA >=0)
    {
        arrRet[iInd--] = (A[iIndA] + iOver) % 10;
        iOver = (A[iIndA] + iOver) / 10;
        --iIndA;
    }
    while (K != 0)
    {
        int iBit = K % 10;
        arrRet[iInd--] = (iBit + iOver) % 10;
        iOver = (iBit + iOver) / 10;
        K = K / 10;
    }
 
    if (iOver != 0)
    {
        arrRet[iInd--] = iOver;
    }
    //PrintArr(arrRet, RETSIZE);
    *returnSize = (RETSIZE - 1 - iInd);
    for (int i = iInd + 1; i < RETSIZE; ++i)
    {
        arrRet[i - 1 - iInd] = arrRet[i];
    }
    return arrRet;
}

int main()
{
    int arr[] = {0};
    int iSize = sizeof(arr) / sizeof(int);
    int k = 23;
    int iRetSize = 0;
    int *arrRet = addToArrayForm(arr, iSize, k, &iRetSize);
    printf("size:%d\n", iRetSize);
    for (int i = 0; i < iRetSize; ++i)
    {
        printf("%d,", arrRet[i]);
    }
    printf("\n");
}
