#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


int* countBits(int num, int* returnSize) 
{
    int *res = (int *)malloc(sizeof(int) * (num + 1));        
    assert(res != NULL);
    memset(res, 0, sizeof(int) * (num + 1));
    int iInd = 0;
    res[iInd++] = 0;
    for (int i = 1; i <= num; ++i)
    {
        if (i % 2 == 0)
        {
            res[iInd++] = res[i & (i - 1)] + 1;
        }
        else
        {
            res[iInd++] = res[i - 1] + 1;
        }
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
