#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int BinSearch(int *arr, int iStart, int iEnd, int key)
{
    int iMid = (iStart + iEnd) / 2;
    while (iStart <= iEnd)
    {
        if (arr[iMid] < key)
        {
            return BinSearch(arr, iMid + 1, iEnd, key);
        }
        else if (arr[iMid] > key)
        {
            return BinSearch(arr, iStart, iMid - 1, key);
        }
        else
        {
            return iMid;
        }
    }
    return iStart;
}

int searchInsert(int* nums, int numsSize, int target) 
{
    int iRet = BinSearch(nums, 0, numsSize - 1, target); 
    return iRet;
}


int main()
{
    int arr[] = {1,3,5,6};
    int iLen = sizeof(arr) / sizeof(int);
    int target = 2;
    int iRet = searchInsert(arr, iLen, target);
    printf("%d\n", iRet);
}
