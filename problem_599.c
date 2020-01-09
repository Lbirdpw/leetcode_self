#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void PrintArr(char **arr, int iSize)
{
    for (int i = 0; i < iSize; ++i)
    {
        printf("%s,", arr[i]);
    }
    printf("\n");
}

//BKDR Hash
unsigned int BKDRHash(char *str)
{
    unsigned int seed = 131;
    unsigned int hash = 0;
    while (*str)
    {
        hash = hash * seed + (*str++);
    }
    return (hash & 0x7FFFFFFF);
}

char** findRestaurant(char** list1, int list1Size, char** list2, int list2Size, int* returnSize) 
{
    int *pHash = (int *)malloc(list1Size * sizeof(int));        
    assert(pHash != NULL);
    memset(pHash, 0, list1Size * sizeof(int));
    for (int i = 0; i < list1Size; ++i)
    {
        pHash[i] = BKDRHash(list1[i]);
    }
    int iMin = list1Size + list2Size;
    for (int i = 0; i < list2Size; ++i)
    {
        int iHashVal = BKDRHash(list2[i]);
        for (int j = 0; j < list1Size; ++j)
        {
            if (iHashVal == pHash[j])
            {
                if (i + j < iMin)
                {
                    iMin = i + j;
                }
            }
        }
    }
    int iRow = list1Size > list2Size ? list1Size : list2Size;
    int iCol = 32;
    char **ret = (char **)malloc(sizeof(char *) * iRow);
    assert(ret != NULL);
    for (int i = 0; i < iRow; ++i)
    {
        ret[i] = (char *)malloc(iCol * sizeof(char));
        assert(ret[i] != NULL);
        memset(ret[i], 0 , iCol * sizeof(char));
    }
    int iInd = 0;
    for (int i = 0; i < list2Size; ++i)
    {
        int iHashVal = BKDRHash(list2[i]);
        for (int j = 0; j < list1Size; ++j)
        {
            if (iHashVal == pHash[j])
            {
                if (i + j == iMin)
                {
                   //printf("111,%s\n", list1[j]);
                   strcpy(ret[iInd++], list1[j]); 
                }
            }
        }
    }
    *returnSize = iInd;
    return ret;
}

int main()
{
    char *list1[4] = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
    char *list2[3] = {"KFC", "Shogun", "Burger King"};
    int list1Size = 4;
    int list2Size = 4;
    int returnSize = 0;
    char **arrRet = findRestaurant(list1, list1Size, list2, list2Size, &returnSize);
    PrintArr(arrRet, returnSize);
}
