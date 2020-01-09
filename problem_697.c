#include <stdio.h>

int findShortestSubArray(int* nums, int numsSize) 
{
    int iMaxCnt = 0;
    int iMaxCntOld = 0;
    int iLeft = -1;
    int iRight = -1;
    int iLeftOld = -1;
    int iRightOld = -1;
    for (int i = 0; i < numsSize - 1; ++i)
    {
        iMaxCnt = 0;
        iLeft = i;
        for (int j = i + 1; j < numsSize; ++j)
        {
            if (nums[i] == nums[j])
            {
                ++iMaxCnt;
                iRight = j;
            }
        }
        if (iMaxCnt > iMaxCntOld)
        {
            iLeftOld = iLeft;
            iRightOld = iRight;
            iMaxCntOld = iMaxCnt;
        }
        else if (iMaxCnt == iMaxCntOld)
        {
            iLen = iRight - iLeft;
            iLenOld = iRightOld - iLeftOld;
            if (iLen < iLenOld)
            {
                iLeftOld = iLeft;
                iRightOld = iRight;
                iMaxCntOld = iMaxCnt;
            }
        }
        else
        {
        }
    }
    return (iRightOld - iLeftOld);
}
