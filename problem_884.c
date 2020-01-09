#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <ctype.h>

#define WORDSISE 100
#define HASHNODE_SIZE 100

typedef struct tagHashNode
{
    char key[WORDSISE];
    int iCnt;
}HashNode;

typedef struct tagHashTable
{
    HashNode **pHashNode;
    int iSize;
    int iEffSize;
}HashTable;

void InitHashTab(HashTable *pHashTable, int iSize)
{
    pHashTable->pHashNode = (HashNode **)malloc(sizeof(HashNode *) * iSize);
    assert(pHashTable->pHashNode != NULL);
    for (int i = 0; i < iSize; ++i)
    {
        pHashTable->pHashNode[i] = (HashNode *)malloc(sizeof(HashNode));
        assert(pHashTable->pHashNode != NULL);
        memset(pHashTable->pHashNode[i], 0, sizeof(HashNode));
    }
    pHashTable->iSize = iSize;
    pHashTable->iEffSize = 0;
}

void unInitHashTab(HashTable *pHTable, int iSize)
{
    for (int i = 0; i < iSize; ++i)
    {
        free(pHTable->pHashNode[i]);
        pHTable->pHashNode[i] = NULL;
    }
    free(pHTable);
    pHTable = NULL;
}

int GetSpaceCnt(char *str)
{
    int iCnt = 0;
    while (*str != '\0')
    {
        if (isspace(*str))
        {
            ++iCnt;
        }
        ++str;
    }
    return iCnt + 1;
}

char** InitPWords(int iCnt)
{
    
    char **pWords = NULL;
    pWords = (char **)malloc(sizeof(char *) * iCnt);
    assert(pWords != NULL);
    for (int i = 0; i < iCnt; ++i)
    {
        pWords[i] = (char *)malloc(sizeof(char) * WORDSISE);
        assert(pWords[i] != NULL);
        memset(pWords[i], 0, sizeof(char) * WORDSISE);
    }
    return pWords;
}


char **GetWords(char *str, int iWordCnt)
{
    char **pWords = NULL;
    int iInd = 0;
    pWords = InitPWords(iWordCnt);
    char *pWord = strtok(str, " ");
    while (pWord)
    {
//printf("iInd:%d, iCnt:%d\n", iInd, iWordCnt);
        assert(iInd < iWordCnt);
        strcpy(pWords[iInd], pWord);
        pWord = strtok(NULL, " ");
        ++iInd;
    }
    return pWords;
}

void FreeWords(char **pWords, int iCnt)
{
    for (int i = 0; i < iCnt; ++i)
    {
        free(pWords[i]);
        pWords[i] = NULL;
    }
    free(pWords);
    pWords = NULL;

}

void AddToHashTable(char **pWords, int iWordCnt, HashTable *pHashTable)
{
    for(int i = 0; i < iWordCnt; ++i)
    {
        int j = 0;
        for (; j < pHashTable->iEffSize; ++j)
        {
            if (0 == strcmp(pHashTable->pHashNode[j]->key, pWords[i]))
            {
                ++(pHashTable->pHashNode[j]->iCnt);
                break;
            }
        }
        if (j >= pHashTable->iEffSize)
        {
            strcpy(pHashTable->pHashNode[pHashTable->iEffSize]->key, pWords[i]);
            pHashTable->pHashNode[pHashTable->iEffSize]->iCnt = 1; 
            ++(pHashTable->iEffSize);
        }
    }
    FreeWords(pWords, iWordCnt);
}

void PrintWords(char **pWords, int iCnt)
{
    printf("iCnt:%d", iCnt);
    for (int i = 0; i < iCnt; ++i)
    {
        printf("%s\n", pWords[i]);
    }
}



void FilterUnCommon(HashTable *pHashTable, char **pWords, int *iCnt)
{
    *iCnt = 0;
    for (int i = 0; i < pHashTable->iEffSize; ++i)
    {
       // printf("key:%s, icnt:%d\n", pHashTable->pHashNode[i]->key, pHashTable->pHashNode[i]->iCnt);
        if (1 == pHashTable->pHashNode[i]->iCnt)
        {
            strcpy(pWords[*iCnt], pHashTable->pHashNode[i]->key);
            ++(*iCnt);
        }
    }
    //PrintWords(pWords, *iCnt);
}

void ProcessStr(char *str, HashTable *pHashTable)
{
    int iWordCnt = GetSpaceCnt(str);
    char **pWords = GetWords(str, iWordCnt);
    //PrintWords(pWords, iWordCnt);
    AddToHashTable(pWords, iWordCnt, pHashTable);
}

char** uncommonFromSentences(char* A, char* B, int* returnSize) 
{
    HashTable stHTable;
    InitHashTab(&stHTable, HASHNODE_SIZE);        
    ProcessStr(A, &stHTable);
    ProcessStr(B, &stHTable);
    char **pWords = InitPWords(WORDSISE);
    FilterUnCommon(&stHTable, pWords, returnSize);
    return pWords;

}



int main()
{
    int iLen = sizeof(char) * WORDSISE;
    char *pA = (char *)malloc(iLen);
    memset(pA, 0, iLen);
    char *pB = (char *)malloc(iLen);
    memset(pB, 0, iLen);
    strcpy(pA, "a b c");
    strcpy(pB, "a b d");
    char **pWords = NULL;
    int iCnt = 0;
    pWords = uncommonFromSentences(pA, pB, &iCnt);
    PrintWords(pWords, iCnt);

    
    return 0;
}
