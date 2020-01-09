#include <stdio.h>
#include <ctype.h>
#include <string.h>

void Swap(char *ch1, char *ch2)
{
    (*ch1) = (*ch1) ^ (*ch2);
    (*ch2) = (*ch1) ^ (*ch2);
    (*ch1) = (*ch1) ^ (*ch2);
}

char* reverseOnlyLetters(char* S) 
{
    if (S == NULL)
    {
        return S;
    }
    int iLen = strlen(S);
    int iStart = 0;
    int iEnd = iLen - 1;
    while (iStart < iEnd)
    {
       while (iStart < iLen && !isalpha(S[iStart])) 
       {
           ++iStart;
       }
       while (iEnd >= 0 && !isalpha(S[iEnd]))
       {
           --iEnd;
       }
       if (iStart < iLen && iEnd >= 0 && iStart < iEnd)
       {
           Swap(S + iStart, S + iEnd);
           //printf("%d, %d\n%s\n", iStart, iEnd, S);
           ++iStart;
           --iEnd;
       }
    }
    return S;
}

int main()
{
    char str[] = {"z<*zj"};
    char *retStr = reverseOnlyLetters(str);
    printf("%s\n", retStr);
}
