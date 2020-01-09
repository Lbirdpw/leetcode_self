#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool repeatedSubstringPattern(char* s) 
{
    int iLen = strlen(s);         
    if (1 == iLen)
    {
        return false;
    }

    bool bFlag = true;        
    for (int iLeap = 1; iLeap <= iLen / 2; ++iLeap)
    {
        bFlag = true;        
        for (int j = 0; j < iLeap; ++j)
        {
            for (int i = j; i + iLeap < iLen && i < iLen; i = i + iLeap)
            {
                if (s[i] != s[i + iLeap])
                {
                    bFlag = false;
                    break;
                }
            }
        }
        if (bFlag && (iLen % iLeap == 0))
        {
            printf("%d\n", iLeap);
            return bFlag;
        }
    }
    return false;
}

int main()
{
    char str[] = {"aabaaba"};
    bool bRet = repeatedSubstringPattern(str);
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
