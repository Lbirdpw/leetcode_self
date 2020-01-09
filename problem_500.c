#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

int key[26] = {0};

void initKey()
{
    char ch = 'A';
    while (ch <= 'Z')
    {
        switch (ch)
        {
            case 'Q':
            case 'W':
            case 'E':
            case 'R':
            case 'T':
            case 'Y':
            case 'U':
            case 'I':
            case 'O':
            case 'P':
                key[ch - 'A'] = 0;
                break;
            case 'A':
            case 'S':
            case 'D':
            case 'F':
            case 'G':
            case 'H':
            case 'J':
            case 'K':
            case 'L':
                key[ch - 'A'] = 1;
                break;
            default:
                key[ch - 'A'] = 2;

        }
        ch += 1;
    }
}

bool isSelected(char *str)
{
    int iPre = -1;
    bool bFirst = true;
    while (*str != '\0')
    {
        int iCur = key[toupper(*str) - 'A'];
        if (bFirst)
        {
            iPre = iCur;
            bFirst = false;
        }
        else
        {
            if (iPre != iCur)
            {
                return false;
            }
        }
        
        ++str;
    }
    return true;

}

/**
 *  * Return an array of size *returnSize.
 *   * Note: The returned array must be malloced, assume caller calls free().
 *    */
char** findWords(char** words, int wordsSize, int* returnSize) 
{
       initKey();
       *returnSize = 0;
       char **res;
       res = (char **)malloc(sizeof(char *) * wordsSize); 
       for (int i = 0; i < wordsSize; ++i)
       {
           res[i] = (char *)malloc(sizeof(char) * 128);
           memset(res[i], 0, sizeof(char)*128);
       }

       for (int i = 0; i < wordsSize; ++i)
       {
           bool bRes = false;
           bRes = isSelected(words[i]);
           if (bRes)
           {
               strcpy(res[*returnSize], words[i]);
               ++(*returnSize);
           }
       }
       return res;
}

void PrintArStr(char **arStr, int iSize)
{
    printf("size:%d\n", iSize);
    for (int i = 0; i < iSize; ++i)
    {
        printf("%s\n", arStr[i]);
    }
}

int main()
{
    char *arStr[] = {"qz","wq","asdddafadsfa","adfadfadfdassfawde"};
    int iCnt = 0;
    char **res = findWords(arStr, 4, &iCnt);
    PrintArStr(res, iCnt);
    return 0;
}
