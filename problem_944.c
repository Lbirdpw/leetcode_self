#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

int GetStrLen(const char *str)
{
    int iLen = 0;
    while (*str++ != '\0')
    {
        ++iLen;
    }
    return iLen;
}

int minDeletionSize(char** A, int ASize) 
{
    if (NULL == A || 0 == ASize)
    {
        return 0;
    }
    int iRet = 0;
    int iLen = GetStrLen(A[0]);
    for (int i = 0; i < iLen; ++i)
    {
        bool bIncrease = true;
        for (int j = 0; j < ASize - 1; ++j)
        {
            if (A[j][i] > A[j + 1][i])
            {
                bIncrease = false;
                ++iRet;
                break;
            }
        }
    }
    return iRet;
}

int main()
{
    char *Str[] = {"cba","daf","ghi"};
    int iRet = minDeletionSize(Str, 3);
    printf("%d\n", iRet);
}
