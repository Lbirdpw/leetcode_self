#include <stdio.h>
#include <stdbool.h>

int maxDistToClosest(int* seats, int seatsSize) 
{
    int iLeft = 0;
    int iRight = 0;
    bool bFirst = true;
    int iMaxLen = 0;
    for (int i = 0; i < seatsSize; ++i)
    {
        if (seats[i] == 1)
        {
            if (bFirst)
            {
                iRight = i;
                bFirst = false;
                iMaxLen = i;
            }
            else
            {
                iLeft = iRight;
                iRight = i;
                int iTmpLen = iLeft + (iRight - iLeft) / 2 - iLeft;
                iMaxLen = iTmpLen > iMaxLen ? iTmpLen : iMaxLen;
            }
        }
    }
    if (iRight != seatsSize - 1)
    {

        int iTmpLen = (seatsSize - 1 - iRight); 
        iMaxLen = iTmpLen > iMaxLen ? iTmpLen : iMaxLen;
    }
    return iMaxLen;
}

int main()
{
    int arr[] = {1,0,0,0,1,0,1};
    int iSize = sizeof(arr) / sizeof(int);
    int iLen = 0;
    iLen = maxDistToClosest(arr, iSize);
    printf("%d\n", iLen);
}
