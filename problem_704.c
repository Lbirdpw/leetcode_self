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
    return -1;
}

int search(int* nums, int numsSize, int target) 
{
    return BinSearch(nums, 0, numsSize - 1, target);        
}



int main()
{
    int arr[] = {-1,0,3,5,9,12};
    int iLen = sizeof(arr) / sizeof(int);
    int iRet = search(arr, iLen, 9);
    printf("%d\n", iRet);
}
