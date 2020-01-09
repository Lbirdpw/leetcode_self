#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

void PrintArr(int *arr, int iSize)
{
    for (int i = 0; i < iSize; ++i)
    {
        printf("%d,", arr[i]);
    }
    printf("\n");
}

int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) 
{
    int *arrRet = (int *)malloc(sizeof(int) * numsSize); 
    assert(arrRet != NULL);
    memset(arrRet, 0, sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; ++i)
    {
        int itmp = nums[i];
        if (itmp < 0)
        {
            itmp = - itmp;
        }
        int iIndex = itmp - 1;
        if (nums[iIndex] > 0)
        {
            nums[iIndex] = - nums[iIndex];
        }
        //PrintArr(nums, numsSize);
    }
    int iInd = 0;
    for (int i = 0; i < numsSize; ++i)
    {
        if(nums[i] > 0)
        {
            arrRet[iInd++] = i;
        }
    }
    *returnSize = iInd + 1;
    return arrRet;
}

int main()
{
    int arr[] = {4,3,2,7,8,2,3,1};
    int iSize = sizeof(arr) / sizeof(int);
    int iRetSize = 0;
    int *arrRet = findDisappearedNumbers(arr, iSize, &iRetSize);
    PrintArr(arrRet, iRetSize);
    free(arrRet);
}
