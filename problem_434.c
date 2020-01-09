#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int countSegments(char* s) 
{
    if (strlen(s) == 0)
    {
        return 0;
    }
    int iCnt = 0;        
    bool bFlag = false;
    while (*s != '\0')
    {
        if (' ' == *s && bFlag)
        {
            ++iCnt;
            bFlag = false;
        }
        if (' ' != *s)
        {
            bFlag = true;
        }
        ++s;
    }
    if (bFlag)
    {
        ++iCnt;
    }
    return iCnt;
}
