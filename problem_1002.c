#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#define ARRSIZE 128
#define INTARRSIZE 27
#define RETSIZE 10

void **InitCommon(int iTypeSize, int iArrSize, int iInSize)
{
    void **pArr = (void **)malloc(4 * iArrSize);
    assert(pArr != NULL);
    for (int i = 0; i < iArrSize; ++i)
    {
        pArr[i] = (void *)malloc(iTypeSize * iInSize);
        assert(pArr[i] != NULL);
        memset(pArr[i], 0, iTypeSize * iInSize);
    }
    return pArr;
}

void unInit(void **pArr, int iArrSize)
{
    for (int i = 0; i < iArrSize; ++i)
    {
        free(pArr[i]);
    }
    free(pArr);
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

int **InitInt(int iTypeSize, int iArrSize, int iInSize)
{
    int **pArr = (int **)malloc(sizeof(int *) * iArrSize);
    assert(pArr != NULL);
    for (int i = 0; i < iArrSize; ++i)
    {
        pArr[i] = (int *)malloc(sizeof(int) * iInSize);
        assert(pArr[i] != NULL);
        memset(pArr[i], 0, sizeof(char) * iInSize);
    }
    return pArr;
}

char** commonChars(char** A, int ASize, int* returnSize) 
{
   int **pSet = InitInt(sizeof(int), ASize, INTARRSIZE); 
   for (int i = 0; i < ASize; ++i)
   {
       char *p = A[i];
       while (*p != '\0')
       {
           pSet[i][*p - 'a'] += 1;
           ++p;
       }
   }
   //for (int i = 0; i < ASize; ++i)
   {
    //   for(int j = 0; j < INTARRSIZE; ++j)
       {
           //printf("%d,", pSet[i][j]);
       }
       //printf("\n");
   }
   char **pRet = InitStr(sizeof(char),ARRSIZE, RETSIZE);
   int iInd = 0;
   for (int i = 0; i < INTARRSIZE; ++i)
   {
       int iMin = pSet[0][i];
       for (int j = 1; j < ASize; ++j)
       {
           if (iMin > pSet[j][i])
           {
               iMin = pSet[j][i];
           }
       }
       if (iMin != 0)
       {
           for (int k = 0; k < iMin; ++k)
           {
               pRet[iInd++][0] = i + 'a';
           }
       }
   }
   unInit((void**)pSet, ASize);
   *returnSize = iInd;
   return pRet;
}



void printArr(void **pArr, int iTypeSize, int iArrSize, int iType)
{
    printf("size:%d\n", iArrSize);
    if (1 == iType)
    {
        for (int i = 0; i < iArrSize; ++i)
        {
            printf("%s\n", pArr[i]);
        }
    }
    else if(2 == iType)
    {
    }
}

int main()
{
    int iTypeSize = 1;
    int iArrSize = 3;
    char **pArr = (char **)InitCommon(iTypeSize, iArrSize, ARRSIZE);
    strcpy(pArr[0], "bella");
    strcpy(pArr[1], "label");
    strcpy(pArr[2], "roller");
    printArr((void **)pArr, 1, 3, 1);


    int iRetSize = 0;
    char **pGet = commonChars(pArr, iArrSize, &iRetSize);
    printArr((void **)pGet, sizeof(char), iRetSize, 1);
    return 0;
}
