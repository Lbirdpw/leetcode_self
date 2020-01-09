#include <stdio.h>


int findMaxConsecutiveOnes(int* nums, int numsSize) 
{
    int iTotal = 0;
    int iTotalOld = 0;
    for (int i = 0; i < numsSize; ++i)            
    {
        if (1 == nums[i])
        {
            iTotal += 1;
        }
        else
        {
            iTotalOld = iTotal > iTotalOld ? iTotal : iTotalOld;
            iTotal = 0;
        }
    }
    iTotalOld = iTotal > iTotalOld ? iTotal : iTotalOld;
    return iTotalOld;
}

int main()
{
    int a[] = {1,1,0,1,1,1};
    int iSize = sizeof(a) / sizeof(int);
    int iRet = findMaxConsecutiveOnes(a, iSize);
    printf("%d\n", iRet);
    return 0;
}
