#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

void BuildHash(int *pHash, char *order, int iOrderSize)
{
    for (int i = 0; i < iOrderSize; ++i)
    {
        pHash[order[i] - 'a'] = i; 
    }
}

int selfStrCmp(char *str1, char *str2, int *pHash)
{
    int iLen1 = strlen(str1);
    int iLen2 = strlen(str2);
    int iMin = iLen1 < iLen2? iLen1 : iLen2;
    for (int i = 0; i < iMin; ++i)
    {
        if (pHash[str1[i] - 'a'] < pHash[str2[i] - 'a'])
        {
            return -1;
        }
        else if (pHash[str1[i] - 'a'] > pHash[str2[i] - 'a']) 
        {
            return 1;
        }
    }
    if (iLen1 > iMin)
    {
        return 1;
    }
    if (iLen2 > iMin)
    {
        return -1;
    }
    return 0;
}

bool isAlienSorted(char** words, int wordsSize, char* order) 
{
    int HashTable[26] = {0}; 
    BuildHash(HashTable, order, 26);
    bool bFlag = true;
    for (int i = 0; i < wordsSize - 1; ++i)
    {
        int iRes = selfStrCmp(words[i], words[i + 1], HashTable);
        if (iRes != -1)
        {
            bFlag &= false;
        }
        else
        {
            bFlag &= true;
        }
    }
    return bFlag;
}

char **InitStr(int iTypeSize, int iArrSize, int iInSize)
{
    char **pArr = (char **)malloc(sizeof(char *) * iArrSize);
    assert(pArr != NULL);
    for (int i = 0; i < iArrSize; ++i)
    {
        pArr[i] = (char *)malloc(sizeof(char) * iInSize);
        assert(pArr[i] != NULL);
        memset(pArr[i], 0, sizeof(char) * iInSize);
    }
    return pArr;
}

int main()
{
    char **words = InitStr(sizeof(char), 3, 100);
    strcpy(words[0], "word");
    strcpy(words[1], "world");
    strcpy(words[2], "row");
    char order[27] = "worldabcefghijkmnpqstuvxyz";
    bool bRes = isAlienSorted(words, 2, order);
    if (bRes)
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }
}
