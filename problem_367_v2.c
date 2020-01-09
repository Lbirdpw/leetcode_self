#include <stdio.h>
#include <stdbool.h>

bool isPerfectSquare(int num) 
{
    if (num == 1)
    {
        return true;
    }
    int iLimit = num / 2;
    while (iLimit >= 46340)
    {
        iLimit = iLimit / 2;
    }
    while (iLimit <= 46340 && iLimit * iLimit >= num)
    {
        iLimit = iLimit / 2;
    }
    int iStart = iLimit;
    int iEnd = iLimit * 2;
    if (iEnd > 46340)
    {
        iEnd = 46340;
    }
    int iMid = (iStart + iEnd) / 2;
    while (iStart <= iEnd)
    {
        if (iMid * iMid < num)
        {
            iStart = iMid + 1;
        }
        else if (iMid * iMid > num)
        {
            iEnd = iMid - 1;
        }
        else
        {
            return true;
        }
        iMid = (iStart + iEnd) / 2;
        //printf("iStart:%d, iEnd:%d\n", iStart, iEnd);
    }
    return false;
}

int main()
{
    int num = 808201;
    bool bRes = isPerfectSquare(num);
    if (bRes)
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    };
    return 0;
}
