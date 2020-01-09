#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

int GetAlpnum(char *str)
{
    int iCnt = 0;
    while (*str != '\0')
    {
        if (isalnum(*str))
        {
            ++iCnt;
        }
        ++str;
    }
    return iCnt;
}


char* licenseKeyFormatting(char* S, int K) 
{
    int iLen = strlen(S);        
    char *tmpStr = (char *)malloc(sizeof(char) * iLen * 2);
    assert(tmpStr != NULL);
    memset(tmpStr, 0, sizeof(char) * iLen * 2);
    int iAlpNum = GetAlpnum(S);
    int iVal = iAlpNum % K;
    int iInd = 0;
    int iTmpCnt = 0;
    while (*S != '\0')
    {
        if (0 == iVal)
        {
            if (isalnum(*S))
            {
                printf("%c\n", *S);
                tmpStr[iInd++] = toupper(*S);
                ++iTmpCnt;
                if (iTmpCnt % K == 0)
                {
                    tmpStr[iInd++] = '-';
                    iTmpCnt = 0;
                }
            }
        }
        else
        {
            if (iInd < iVal)
            {
                if (isalnum(*S))
                {
            printf("%c\n", *S);
                    tmpStr[iInd++] = toupper(*S);
                }
            }
            else
            {
                    tmpStr[iInd++] = '-';
                    iVal = 0;
                    if (isalnum(*S))
                    {
                        tmpStr[iInd++] = toupper(*S);
                        ++iTmpCnt;
                    }

            }
        }
        ++S;
    }
    //strcpy(S, tmpStr);
    //S[iInd] = '\0';
    //free(tmpStr);
    //tmpStr = NULL;
    if (iInd > 0 && tmpStr[iInd - 1] == '-')
    {
        tmpStr[iInd - 1] = '\0';
    }
    return tmpStr;
}

int main()
{
    char str[] = {"0123456789"};
    int k = 1;
    char *ret = licenseKeyFormatting(str, k);
    printf("%s\n", ret);
    return 0;
}
