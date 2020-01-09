#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#define HASHSIZE 100

typedef struct tagMyHashNode
{
    int key;
    int val;
    struct tagMyHashNode *pNext;
}MyHashNode;

typedef struct tagMyHashMap
{
    int iSize;
    MyHashNode *pHashTable; 
} MyHashMap;

/** Initialize your data structure here. */
MyHashMap* myHashMapCreate() 
{
    MyHashMap *pMap = (MyHashMap *)malloc(sizeof(MyHashMap));
    assert(pMap != NULL);
    pMap->iSize = HASHSIZE;
    pMap->pHashTable = (MyHashNode *)malloc(sizeof(MyHashNode) * HASHSIZE);
    assert(pMap->pHashTable != NULL);
    for (int i = 0; i < HASHSIZE; ++i)
    {
        pMap->pHashTable[i].key = -1;
        pMap->pHashTable[i].val = -1;
        pMap->pHashTable[i].pNext = NULL;
    }
    return pMap;
}

/** value will always be non-negative. */
void myHashMapPut(MyHashMap* obj, int key, int value) 
{ 
    int iInd = key % HASHSIZE;
    MyHashNode *pNode = &(obj->pHashTable[iInd]); 
    MyHashNode *pPreNode = pNode; 
    //if (pNode->key == -1)
    //{
    //   pNode->key = key;
    //    pNode->val = value;
    //}
    //else
    {
        while (pNode != NULL)
        {
            if (pNode->key == key)
            {
                pNode->val = value;
                return;
            }
            pPreNode = pNode;
            pNode = pNode->pNext;
        }
        MyHashNode *pTmpNode = (MyHashNode *)malloc(sizeof(MyHashNode));
        assert(pTmpNode != NULL);
        pTmpNode->key = key;
        pTmpNode->val = value;
        pPreNode->pNext = pTmpNode;
        pTmpNode->pNext = NULL;
    }
}

/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
int myHashMapGet(MyHashMap* obj, int key) 
{
    int iInd = key % HASHSIZE;
    MyHashNode *pNode = &(obj->pHashTable[iInd]); 
    while (pNode != NULL)
    {
        if (pNode->key == key)
        {
            return pNode->val;
        }
        pNode = pNode->pNext;
    }
    return -1;
}

/** Removes the mapping of the specified value key if this map contains a mapping for the key */
void myHashMapRemove(MyHashMap* obj, int key) 
{
    int iInd = key % HASHSIZE;
    MyHashNode *pNode = &(obj->pHashTable[iInd]); 
    MyHashNode *pPreNode = pNode;
    while (pNode != NULL)
    {
        if (pNode->key == key)
        {
            pPreNode->pNext = pNode->pNext;
            free(pNode);
            pNode = NULL;
            return;
        }
        pPreNode = pNode;
        pNode = pNode->pNext;
    }
        
}

void myHashMapFree(MyHashMap* obj) 
{
    int iLen = obj->iSize;
    for (int i = 0; i < iLen; ++i) 
    {
        MyHashNode *pNode = &(obj->pHashTable[i]);
        if (pNode->key == -1)
        {
            pNode = pNode->pNext;
            continue;
        }
        while(pNode != NULL)
        {
            MyHashNode *pNextTmp = pNode->pNext;
            free(pNode);
            pNode = pNextTmp;
        }
    }
    free(obj->pHashTable);
    obj->pHashTable = NULL;
    obj->iSize = 0;
}

int main()
{
    MyHashMap* obj = myHashMapCreate();
    int key = 1;
    int value = 1;
    myHashMapPut(obj, key, value);
    int param_2 = myHashMapGet(obj, key);
    myHashMapRemove(obj, key);
    myHashMapFree(obj);
    return 0;
}
