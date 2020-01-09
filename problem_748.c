#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define HASHSIZE 256
#define MAXWORDSIZE 32

void GetHash(char *str, int *pHashTable)
{
    int iLen = strlen(str);
    for (int i = 0; i < iLen; ++i)
    {
        if (isalpha(str[i]))
        {
            char ch = tolower(str[i]);
            pHashTable[ch] += 1;
        }
    }
}

int isComWord(int *pPlateHash, int *pWordHash)
{
    for (int i = 0; i < HASHSIZE; ++i)
    {
        if (pWordHash[i] < pPlateHash[i])
        {
            return -1;
        }
    }
    return 1;
}

char* shortestCompletingWord(char* licensePlate, char** words, int wordsSize) 
{
    int hashPlate[256] = {0};        
    GetHash(licensePlate, hashPlate);
    int iLen = MAXWORDSIZE;
    char *retStr = NULL;
    for (int i = 0; i < wordsSize; ++i)
    {
        int wordHash[HASHSIZE] = {0};
        GetHash(words[i], wordHash);
        if (1 == isComWord(hashPlate, wordHash))
        {
            int iComLen = strlen(words[i]);
            if (iComLen < iLen)
            {
                iLen = iComLen;
                retStr = words[i];
            }
        }
    }
    return retStr;
}

int main()
{
    char *p[4] = {"looks", "pest", "stew", "show"};
    int wordsSize = 4;
    char *licensePlate = "1s3 456";
    char *retStr = shortestCompletingWord(licensePlate, p, wordsSize) ;
    printf("%s\n", retStr);
}
