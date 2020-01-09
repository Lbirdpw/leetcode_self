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

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) 
{
    int *arRet = (int *)malloc(sizeof(int) * 2);
    assert(arRet != NULL);
    memset(arRet, 0, 2 * sizeof(int));
    *returnSize = 2;
    for (int i = 0;  i < numbersSize; ++i)        
    {
        if (target - numbers[i] >= 0)
        {
            int iRet = BinSearch(numbers, i + 1, numbersSize - 1, target - numbers[i]);
            if (iRet != -1)
            {
                arRet[0] = i + 1;
                arRet[1] = iRet + 1;
                return arRet;
            }
        }
    }
    return arRet;
}

int main()
{
    int arr[] = {-1,0};
    int iLen = sizeof(arr) / sizeof(int);
    int iRetSize = 0;
    int *arRet = twoSum(arr, iLen, -1, &iRetSize);
    printf("%d,%d\n", arRet[0], arRet[1]);
}
