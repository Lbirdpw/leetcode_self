#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>


bool isParStr(char *s, int i, int j, int iFlag)
{
    while (i < j)    
    {
        if (s[i] == s[j])
        {
            i += 1;
            j -= 1;
        }
        else
        {
            if (1 == iFlag)
            {
                return false;
            }
            iFlag = 1;
            return isParStr(s, i + 1, j, iFlag) || isParStr(s, i, j - 1, iFlag);
        }
    }
    return true;
}

bool validPalindrome(char* s) 
{
    int iLen = strlen(s);
    return isParStr(s, 0, iLen - 1, 0);
}

int main()
{
    char str[] = {"abca"};
    bool bRet = validPalindrome(str);
    if (bRet)
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }
    return 0;
}
