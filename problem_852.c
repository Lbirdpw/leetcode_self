#include <stdio.h>
#include<stdlib.h>

int peakIndexInMountainArray(int* A, int ASize) 
{
    for (int i = 0; i < ASize - 1; ++i)    
    {
        if (A[i] < A[i + 1])
        {
             continue;
        }
        return i;
    }
}

int peakIndexInMountainArray1(int* A, int ASize) 
{
    int iStart = 0;
    int iEnd = ASize;
    int mid = (iStart + iEnd) / 2;
    while (iStart <= iEnd)
    {
        if (A[mid] < A[mid + 1])
        {
            iStart = mid;
        }
        else if (A[mid] < A[mid -1])
        {
            iEnd = mid;
        }
        else
        {
            break;
        }
        mid = (iStart + iEnd) / 2;
    }
    return mid;
}

int main()
{
    int a[] = {0, 2, 1, 0};
    int iInd = peakIndexInMountainArray1(a, 4);
    printf("%d\n", iInd);
}
