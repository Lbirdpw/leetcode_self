#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAXHASHSIZE 200

void swap(int *arr, int i, int j)
{
    arr[i] = arr[i] ^ arr[j];
    arr[j] = arr[i] ^ arr[j];
    arr[i] = arr[i] ^ arr[j];
}


void BuildMaxHeap(int *nums, int numsSize)
{
    int iFirstNoneLeaf = numsSize / 2 - 1;
    for (int i = iFirstNoneLeaf; i >= 0; --i)
    {
        int iLeft = 2 * iFirstNoneLeaf + 1;
        int iRight = 2 * iFirstNoneLeaf + 2;
        int iMax = nums[i];
        int iInd = i;
        if (iLeft < numsSize && nums[iLeft] > iMax)
        {
            iMax = nums[iLeft];
            iInd = iLeft;
        }
        else if (iRight < numsSize && nums[iRight] > iMax)
        {
            iMax = nums[iRight];
            iInd = iRight;
        }
        else
        {
        }
        if (i != iInd)
        {
           swap(nums, i, iInd); 
        }

    }
}

void GetHashTable(int *nums, int numsSize, int *arrHash)
{
    for (int i = 0; i < numsSize; ++i)
    {
        arrHash[nums[i]] = i; 
    }
}

int dominantIndex(int* nums, int numsSize) 
{
    if (1 == numsSize)
    {
        return 0;
    }
    int *arrHash = (int *)malloc(sizeof(int) * MAXHASHSIZE);
    assert(arrHash != NULL);
    for (int i = 0; i < MAXHASHSIZE; ++i)
    {
        arrHash[i] = -1;
    }
    GetHashTable(nums, numsSize, arrHash);
    int iMax = -1;
    int iPreMax = -1;
    for (int i = 0; i < MAXHASHSIZE; ++i)
    {
        if (arrHash[i] >= 0)
        {
            iPreMax = iMax;
            iMax = i;
        }
    }
    if (iMax >= 0 && iPreMax >=0 && iMax >= iPreMax * 2)
    {
        return arrHash[iMax];
    }
    return -1;
}

int main()
{
    int arr[] = {3,6,1,0};
    int iLen = sizeof(arr) / sizeof(int);
    int iRet = dominantIndex(arr, iLen);
    printf("%d\n", iRet);
    return 0;
}
