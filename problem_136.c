#include <stdio.h>

int singleNumber(int* nums, int numsSize) 
{
    if (numsSize <= 0)
    {
        return 0;
    }
    int iRes = nums[0];
    for (int i = 1; i < numsSize; ++i)        
    {
       iRes ^= nums[i]; 
    }
    return iRes;
}

int main()
{
    int a[] = {1, 2, 1};
    int iLen = sizeof(a) / sizeof(int);
    int iRet = singleNumber(a, iLen);
    printf("%d\n", iRet);
    return 0;
}
