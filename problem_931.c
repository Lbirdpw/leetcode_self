#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define MAXVAL 1000

void PrintArr(int **p, int iRowSize, int iColSize)
{
    for (int i = 0; i < iRowSize; ++i)
    {
        for (int j = 0; j < iColSize; ++j)
        {
            printf("%d,", p[i][j]);
        }
        printf("\n");
    }
}

int minFallingPathSum(int** A, int ARowSize, int AColSize) 
{
    int **p = (int **)malloc(sizeof(int *) * ARowSize);
    assert(p != NULL);
    for (int i = 0; i < ARowSize; ++i)
    {
        p[i] = (int *)malloc(sizeof(int) * AColSize);
        assert(p[i] != NULL);
        memset(p[i], 0, sizeof(int) * AColSize);
    }
    for (int i = 0; i < ARowSize; ++i)        
    {
        int row = i - 1;
        for (int j = 0; j < AColSize; ++j)
        {
            int iMin = MAXVAL;
            for (int col = j - 1; col <= j + 1; ++col)
            {
                
                if (row >= 0 && col >= 0 && col < AColSize)
                {
                   if (iMin > p[row][col]) 
                   {
                       iMin = p[row][col];
                   }
                }
                else
                {        
                    continue;       
                }
            }
            //printf("%d,", iMin);
            if (iMin == MAXVAL)
            {
                p[i][j] = A[i][j];
            }
            else
            {
                p[i][j] = A[i][j] + iMin;
            }
            //printf("i=%d, j=%d,p[i][j]=%d\n", i, j, p[i][j]);
        }
    }
    //PrintArr(p, ARowSize, AColSize);
    int iMin = MAXVAL;
    for (int j = 0; j < AColSize; ++j)
    {
        if (iMin > p[ARowSize - 1][j])
        {
            iMin = p[ARowSize - 1][j];
        }
    }
    for (int i = 0; i < ARowSize; ++i)
    {
        free(p[i]);
        p[i] = NULL;
    }
    free(p);
    p = NULL;
    return iMin;
}

int main()
{
    int ARowSize = 3;
    int AColSize = 3;
    int **p = (int **)malloc(sizeof(int *) * ARowSize);
    assert(p != NULL);
    for (int i = 0; i < ARowSize; ++i)
    {
        p[i] = (int *)malloc(sizeof(int) * AColSize);
        assert(p[i] != NULL);
        memset(p[i], 0, sizeof(int) * AColSize);
    }
    int iVal = 1;
    for (int i = 0; i < ARowSize; ++i)
    {
        for (int j = 0; j < AColSize; ++j)
        {
            p[i][j] = iVal;
            ++iVal;
        }
    }
    //PrintArr(p, ARowSize, AColSize);
    int iRet = minFallingPathSum(p, ARowSize, AColSize);
    printf("%d\n", iRet);
}
