#include <stdio.h>
#include <string.h>

int findLUSlength(char* a, char* b) 
{
    int iLenA = strlen(a);        
    int iLenB = strlen(b);
    if (iLenA != iLenB)
    {
        return (iLenA > iLenB ? iLenA : iLenB);
    }
    else
    {
        if (0 == strcmp(a, b))
        {
            return -1;
        }
        else
        {
            return iLenA;
        }
    }
    return -1;
}
