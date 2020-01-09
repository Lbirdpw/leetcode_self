#include <stdio.h>

int missingNumber(int* nums, int numsSize) 
{
    int iSum1 = 0
    for (int i = 0; i < numsSize; ++i)        
    {
        iSum1 += nums[i];
    }
    int iSum2 = 0;
    for (int i = 0; i < numsSize; ++i)
    {
        iSum2 += i;
    }
    return iSum2 - iSum1;
}
