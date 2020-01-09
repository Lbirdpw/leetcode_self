#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int GetOneBits(int num)
{
    int iCnt = 0;
    while (num != 0)
    {
        ++iCnt;
        num = num & (num - 1);
    }
    return iCnt;
}

int* countBits(int num, int* returnSize) 
{
    int *res = (int *)malloc(sizeof(int) * (num + 1));        
    assert(res != NULL);
    memset(res, 0, sizeof(int) * (num + 1));
    int iInd = 0;
    for (int i = 0; i <= num; ++i)
    {
        int iCnt = GetOneBits(i);
        res[iInd++] = iCnt;
    }
    *returnSize = iInd;
    return res;
}

int main()
{
    int num = 5;
    int retSize = 0;
    int *res = countBits(num, &retSize);
    for (int i = 0; i < retSize; ++i)
    {
        printf("%d,", res[i]);
    }
    printf("\n");
    free(res);
}
