#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

bool IsSelfDividNum(int num)
{
    int iTmp = num;
    while (iTmp != 0)
    {
        int iDig = iTmp % 10;
        if (iDig == 0)
        {
            return false;
        }
        if (num % iDig != 0)
        {
            return false;
        }
        iTmp /= 10;
    }
    return true;
}



int* selfDividingNumbers(int left, int right, int* returnSize) 
{
    int iSize = right - left + 1;
    int *flag = (int *)malloc(sizeof(int) * iSize);
    assert(flag != NULL);
    memset(flag, 0, sizeof(int) * iSize);
    *returnSize = 0;
    for (int i = left; i <= right; ++i)
    {
        if (IsSelfDividNum(i))
        {
            flag[i - left] = 1;
            ++(*returnSize);
        }
    }
    int *retNum = (int *)malloc(sizeof(int) * (*returnSize));
    assert(retNum != NULL);
    memset(retNum, 0, sizeof(int) * (*returnSize));
    int iInd = 0;
    for (int i = 0; i < iSize; ++i)
    {
        if (flag[i])
        {
            retNum[iInd] = i + left;
            ++iInd;
        }
    }
    free(flag);
    return retNum;
}

void printArr(int *arr, int iSize)
{
    printf("total %d:\n", iSize);
    for (int i = 0; i < iSize; ++i)
    {
        printf("%d\n", arr[i]);
    }
}

int main()
{
    int left = 1;
    int right = 22;
    int iSize = 0;
    int *ret = selfDividingNumbers(left, right, &iSize);
    printArr(ret, iSize);
    free(ret);
}
