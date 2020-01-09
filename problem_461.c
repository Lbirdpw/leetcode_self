#include <stdio.h>
#include <stdlib.h>

int hammingDistance(int x, int y) 
{
    int z = x ^ y;
    int iCnt = 0;
    while (z != 0)
    {
        if (z & 1)
        {
            ++iCnt;
        }
        z = z >> 1;
    }
    return iCnt;
}

int main()
{
    int x = 1;
    int y = 4;
    int iRes = hammingDistance(x, y);
    printf("%d\n", iRes);
}
