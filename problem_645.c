#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

int* findErrorNums(int* nums, int numsSize, int* returnSize) 
{
    int iAndRes = 0;
    for (int i = 0; i < numsSize; ++i)
    {
        iAndRes ^= nums[i];
        iAndRes ^= (i + 1);
    }
    for (int i = 0; i < numsSize; ++i)
    {
        int iTmp = nums[i];
        if (iTmp < 0)
        {
            iTmp = -iTmp;
        }
        int iIndex = iTmp - 1;
        if (nums[iIndex] > 0)
        {
            nums[iIndex] = -nums[iIndex];
        }
    }
    int iMissing = 0;
    for (int i = 0; i < numsSize; ++i)
    {
        if (nums[i] > 0)
        {
            iMissing = i + 1;
        }
    }
    int iDup = iAndRes ^ iMissing;
    int *arrRet = (int *)malloc(sizeof(int) * 2);
    assert(arrRet != 0);
    memset(arrRet, 0, sizeof(int) * 2);
    arrRet[0] = iDup;
    arrRet[1] = iMissing;
    *returnSize = 2;
    return arrRet;
}

int main()
{
    int arr[] = {1,2,2,4};
    int iSize = sizeof(arr) / sizeof(int);
    int iRetSize = 0;
    int *arrRet = NULL;
    arrRet = findErrorNums(arr, iSize, &iRetSize);
    for (int i = 0; i < iRetSize; ++i)
    {
        printf("%d,", arrRet[i]);
    }
    printf("\n");
    free(arrRet);
    return 0;
}
