#include <stdio.h>
#define LIMIT 46340

int mySqrt(int x) 
{
    if (0 == x)
    {
        return 0;
    }
    if (x == 1)
    {
        return 1;
    }
    int iLimit = x / 2;
    while (iLimit >= LIMIT)
    {
        iLimit = iLimit / 2;
    }
    while (iLimit <= LIMIT && iLimit * iLimit >= x)
    {
        iLimit = iLimit / 2;
    }
    printf("iLimit:%d\n", iLimit);
    int iStart = iLimit;
    int iEnd = iLimit * 2;
    if (iEnd > LIMIT)
    {
        iEnd = LIMIT;
    }
    int iMid = (iStart + iEnd) / 2;
    while (iStart <= iEnd)
    {
        printf("%d\n", iMid);
        if (iMid * iMid < x)
        {
            iStart = iMid + 1;
        }
        else if (iMid * iMid > x)
        {
            iEnd = iMid- 1;
        }
        else
        {
            return iMid;
        }
        iMid = (iStart + iEnd) / 2;
    }
    //printf("iStart:%d, iEnd:%d\n", iStart, iEnd);
    return iEnd;
}

int main()
{
    int x = 2147395599;
    int iRet = mySqrt(x);
    printf("%d\n", iRet);
    return 0;
}
