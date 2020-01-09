#include <stdio.h>
#include <string.h>

#define HASHSIZE 26

void GetHashCnt(char *s, int *pHash)
{
    int iLen = strlen(s);
    for (int i = 0; i < iLen; ++i)
    {
        pHash[s[i] - 'a'] += 1;
    }
}

void GetHashIndex(char *s, int *pHash)
{
    int iLen = strlen(s);
    for (int i = 0; i < iLen; ++i)
    {
        if (pHash[s[i] - 'a'] == -1)
        {
            pHash[s[i] - 'a'] = i;
        }
    }
}

void PrintArr(int *arr, int iSize)
{
    for (int i = 0; i < iSize; ++i)
    {
        printf("%d,", arr[i]);
    }
    printf("\n");
}

int firstUniqChar(char* s) 
{
    int HashCnt[HASHSIZE] = {0};     
    GetHashCnt(s, HashCnt);

    int HashIndex[HASHSIZE] = {-1};
    for (int i = 0; i < HASHSIZE; ++i)
    {
        HashIndex[i] = -1;
    }
    GetHashIndex(s, HashIndex);

    //PrintArr(HashCnt, HASHSIZE);
    //PrintArr(HashIndex, HASHSIZE);
    int iMinInd = strlen(s);
    for (int i = 0; i < HASHSIZE; ++i)
    {
        if (1 == HashCnt[i])
        {
            if (HashIndex[i] < iMinInd)
            {
                iMinInd = HashIndex[i];
            }
        }
    }
    if (strlen(s) == iMinInd)
    {
        return -1;
    }
    return iMinInd;
}

int main()
{
    char *s = "loveleetcode";
    int iRet = firstUniqChar(s);
    printf("%d\n", iRet);
    return 0;
}
