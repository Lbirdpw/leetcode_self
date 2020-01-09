#include <stdio.h>

void Swap(char *p, char *q)
{
    (*p) = (*p) ^ (*q);
    (*q) = (*p) ^ (*q);
    (*p) = (*p) ^ (*q);
}

void reWord(char *s, int iStart, int iEnd)
{
    //printf("000, %s\n", s);
    while (iStart < iEnd)
    {
        Swap(s + iStart, s + iEnd);
        ++iStart;
        --iEnd;
    }
    //printf("000, %s\n", s);
}

char* reverseWords(char* pStr) 
{
    char *s = pStr;
    if (NULL == s)
    {
        return NULL;
    }
    int iStart = 0; 
    int iEnd = -1;
    while (*s != '\0')
    {
        if (*s == ' ')
        {
            ++iEnd;
            //printf("%d, %d\n", iStart, iEnd);
            reWord(pStr, iStart, iEnd - 1);
            //printf("111,%s\n", pStr);
            iStart = iEnd + 1;
        }
        else
        {
            ++iEnd;
        }
        //printf("%c,%d\n", *s, iEnd);
        ++s;
    }
    reWord(pStr, iStart, iEnd);
    return pStr;
}

int main()
{
    char s[] = "Let's take LeetCode contest";
    char *sret = reverseWords(s);
    printf("%s\n", sret);
}
