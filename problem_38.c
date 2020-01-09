#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


#define MAXSIZE 5148

char* countAndSay(int n) 
{
    int iAllocSize = sizeof(char) * MAXSIZE;
    char *pBackStr = (char *)malloc(iAllocSize);            
    assert(pBackStr != NULL);
    memset(pBackStr, 0, iAllocSize);
    int iInd = 0;
    pBackStr[iInd++] = '1';
    if (n == 1)
    {
        return pBackStr;
    }
    char *pRetStr = (char *)malloc(iAllocSize);            
    assert(pRetStr != NULL);
    memset(pRetStr, 0, iAllocSize);
    for (int i = 2; i <= n; ++i)
    {
        int iIndRet = 0;
        int iCnt = 0;
        char *pStr = pBackStr;
        char chVal = pStr[0];
        while (*pStr != '\0')
        {
            if (*pStr != chVal)
            {
                char chCntVal = '0' + iCnt; 
                pRetStr[iIndRet++] = chCntVal;
                pRetStr[iIndRet++] = chVal;
                chVal = *pStr;
                iCnt = 0;
            }
            ++iCnt;
            ++pStr;
        }
        char chCntVal = '0' + iCnt; 
        pRetStr[iIndRet++] = chCntVal;
        pRetStr[iIndRet++] = chVal;
 
        //printf("Back:%s\n", pBackStr);
        //printf("Ret:%s\n", pRetStr);
        strncpy(pBackStr, pRetStr, iIndRet);
        memset(pRetStr, 0, iAllocSize);
    }

    free(pRetStr);
    return pBackStr;
}

int main()
{
    int n = 30;
    char *pRetStr = countAndSay(n);
    printf("%s\n", pRetStr);
    free(pRetStr);
    return 0;
}
