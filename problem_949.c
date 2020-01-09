#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

void swapval(int *arr, int i, int j)
{
    arr[i] = arr[i] ^ arr[j];
    arr[j] = arr[i] ^ arr[j];
    arr[i] = arr[i] ^ arr[j];
}

void sort(int *a, int ASize)
{
    for (int i = 1; i < ASize; ++i)
    {
        int j = i - 1;
        while (j >= 0)
        {
            if (a[j] > a[i])
            {
                a[j + 1] = a[j];
            }
            --j;
        }
        a[j] = a[i];
    }
}

char* largestTimeFromDigits(int* A, int ASize) 
{
    char *pStr = (char *)malloc(sizeof(char) * 6);
    assert(pStr != NULL);
    memset(pStr, 0, sizeof(char) * 6);
    int iMax = -1;
    int iLimit = 2 * 600 + 3 * 60 + 5 * 10 + 9;
    for (int i = 0; i < ASize; ++i)
    {
        for (int j = 0; j < ASize; ++j)
        {
            for (int m = 0; m < ASize; ++m)
            {
                for (int n = 0; n < ASize; ++n)
                {
                    if (i != j && i != m && i != n && j != m && j != n && m != n)
                    {
                        int iVal = A[i] * 600 + A[j] * 60 + A[m] * 10 + A[n];
                        if (iVal > iMax && iVal <= iLimit)
                        {
                            if ((A[i] == 2 && A[j] <= 3 && A[m] <= 5)||
                                (A[i] <= 1 && A[m] <= 5))
                            {
                                printf("%d, %d\n", iVal, iLimit);
                                iMax = iVal;
                                pStr[0] = A[i] + '0';
                                pStr[1] = A[j] + '0';
                                pStr[2] = ':';
                                pStr[3] = A[m] + '0';
                                pStr[4] = A[n] + '0';
                            }
                        }
                    }
                }
            }
        }
    }
    return pStr;
}

int main()
{
    int arr[] = {8,2,0,0};
    int ASize = 4;
    char *pStr = largestTimeFromDigits(arr, ASize);
    printf("%s\n", pStr);
    free(pStr);
    return 0;
}
