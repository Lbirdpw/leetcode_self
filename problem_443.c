#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void swap(char *pStr, int i, int j)
{
    pStr[i] = pStr[i] ^ pStr[j];
    pStr[j] = pStr[i] ^ pStr[j];
    pStr[i] = pStr[i] ^ pStr[j];
}

void ReverseStr(char *pStr, int iSize)
{
    int i = 0;
    int j = iSize - 1;
    while (i < j)
    {
        swap(pStr, i, j);
        ++i;
        --j;
    }
}

int addCnt(char *chars, int iCnt)
{
    if (iCnt == 1)
    {
        return 0;
    }
    int iInd = 0;
    while (iCnt != 0)
    {
        int iVal = iCnt % 10;
        chars[iInd++] = iVal + '0';
        iCnt /= 10;
    }
    ReverseStr(chars, iInd);
    return iInd;
}

int compress(char* chars, int charsSize) 
{
    if (1 == charsSize)
    {
        return 1;
    }
    int iCnt = 0;
    char chVal = chars[0];
    int iInd = 0;
    for (int i = 0; i < charsSize; ++i)
    {
       if (chars[i] != chVal) 
       {
            chars[iInd++] = chVal;
            int bitPos = addCnt(chars + iInd, iCnt);
            iInd += bitPos;
            //chars[iInd++] = a[i] + '0';

            chVal = chars[i];
            iCnt = 0;
       }
       ++iCnt;
    }
    chars[iInd++] = chVal;
    int bitPos = addCnt(chars + iInd, iCnt);
    iInd += bitPos;

   //chars[iInd] = '\0';
    return iInd;
}

int main()
{
    char str[] = {"aabbaa"};
    int iSize = strlen(str);
    int iRet = compress(str, iSize);
    printf("%d,%s\n", iRet, str);
    return 0;
}
