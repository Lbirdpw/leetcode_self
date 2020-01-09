#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

bool IsEven(int i)
{
    if (i < 0)
    {
        i = 0 - i;
    }
    if (i % 2 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int GetEvenSum(int *arr, int iSize)
{
    int iSum = 0;
    for (int i = 0; i < iSize; ++i)
    {
        if (IsEven(arr[i]))
        {
            iSum += arr[i];
        }
    }
    return iSum;
}

/**
 *  * Return an array of size *returnSize.
 *   * Note: The returned array must be malloced, assume caller calls free().
 *    */
int* sumEvenAfterQueries(int* A, int ASize, int** queries, int queriesRowSize, int *queriesColSizes, int* returnSize) 
{
    int *iRetArr = (int *)malloc(sizeof(int) * queriesRowSize);
    assert(iRetArr != NULL);
    memset(iRetArr, 0, sizeof(int) * queriesRowSize);
    int iSum = GetEvenSum(A, ASize);
    int iInd = 0;
    for (int row = 0; row < queriesRowSize; ++row)
    {
        int iVal = queries[row][0];
        int iIndex = queries[row][1];
        if (IsEven(A[iIndex]))
        {
            iSum -= A[iIndex];
        }
        A[iIndex] += iVal;
        if (IsEven(A[iIndex]))
        {
            iSum += A[iIndex];
        }
 
        iRetArr[iInd++] = iSum;
    }
    *returnSize = iInd;
    return iRetArr;
}


