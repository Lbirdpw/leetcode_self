#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

int GetStrLen(const char *str)
{
    int iLen = 0;
    while (*str != '\0')
    {
        ++iLen;
        ++str;
    }
    ++iLen; 
    return iLen;
}

char * GetModStr(const char *str)
{
    int iLen = GetStrLen(str);
    char *pStr = (char *)malloc(sizeof(char) * iLen);
    assert(pStr != NULL);
    memset(pStr, 0, sizeof(char) * iLen);
    bool bAt = false;
    bool bAdd = false;
    int iInd = 0;
    for (int i = 0; str[i] != '\0'; ++i)
    {
       if (bAt)
       {
           pStr[iInd] = str[i];
           ++iInd;
           continue;
       }
       if (!bAt && !bAdd && str[i] != '.') 
       {
           pStr[iInd] = str[i]; 
           ++iInd;
       }
       if (str[i] == '+')
       {
           bAdd = true;
       }
       if (str[i] == '@')
       {
           bAt = true;
       }
    }
    return pStr;
}

bool IsEqualStr(const char *strA, const char *strB)
{
    bool bRes = false;
    char *pResA = NULL;
    char *pResB = NULL;
    pResA = GetModStr(strA);
    pResB = GetModStr(strB);
    if (strcmp(pResA, pResB) == 0)
    {
        bRes = true;
    }
    free(pResA);
    pResA = NULL;
    free(pResB);
    pResB = NULL;
    return bRes;
}

int numUniqueEmails(char** emails, int emailsSize) 
{
    if (emailsSize <= 0)
    {
        return 0;
    }
    int iCnt = 1;
    for (int i = 0; i < emailsSize - 1; ++i)
    {
        bool bNew = true;
        for (int j = i + 1; j < emailsSize; ++j)
        {
            if (IsEqualStr(emails[i], emails[j]))
            {
                bNew = false;
            }
        }
        if (bNew)
        {
            ++iCnt;
        }
    }
    return iCnt;
}

int main()
{
    char *emails[] = {"test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"};
    int iCnt = numUniqueEmails(emails, 3);
    printf("%d:\n", iCnt);
}
