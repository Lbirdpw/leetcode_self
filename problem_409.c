#include <stdio.h>
#include <string.h>

#define HASHSIZE 256

void GetHash(char *s, int *pHash)
{
    int iLen = strlen(s);
    for (int i = 0; i < iLen; ++i)
    {
        pHash[s[i]] += 1;
    }
}

int longestPalindrome(char* s) 
{
    int iOddMax = 0;
    int iSum = 0;
    int arrHash[HASHSIZE] = {0};
    GetHash(s, arrHash);
    int iOddFlag = 0;
    for (int i = 0; i < HASHSIZE; ++i)
    {
        if (0 == arrHash[i])
        {
            continue;
        }
        if (arrHash[i] % 2 == 0)
        {
            iSum += arrHash[i];
            //printf("%d\n", arrHash[i]);
        }
        else
        {
            iSum += (arrHash[i] - 1);
            iOddFlag = 1;
            //printf("%d\n", arrHash[i]);
        }
    }
    if (iOddFlag)
    {
        iSum += 1;
    }
    return iSum;
}

int main()
{
    char *s = "abccccdd";
    int iRet = longestPalindrome(s);
    printf("%d\n", iRet);
}
