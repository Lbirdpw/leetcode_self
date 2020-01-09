#include <stdio.h>

int Sum(int *nums, int numsSize)
{
    int iRes = 0;
    for (int i = 0; i < numsSize; ++i)
    {
        iRes += nums[i];
    }
    return iRes;
}

int pivotIndex(int* nums, int numsSize) 
{
    int iSum = Sum(nums, numsSize);
    for (int k = 0; k < numsSize; ++k)
    {
        int iSumLeft = 0;
        int iSumRight = iSum;
        int iInd = k;
        for (int i = 0; i < iInd; ++i)
        {
            iSumLeft += nums[i];
            iSumRight -= nums[i]; 
        }
        iSumRight -= nums[iInd];
        if (iSumLeft == iSumRight)
        {
            return iInd;
        }
    }
    
    return -1;
}
