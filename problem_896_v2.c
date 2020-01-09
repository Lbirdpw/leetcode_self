#include <stdio.h>
#include <stdbool.h>

bool isUpSeq(int *A, int ASize, int i, int j)
{
    if (j == i + 1)
    {
        if (A[i] <= A[j])
        {
            return true;
        }
        return false;
    }
    int mid = i + (j - i) / 2;
    return isUpSeq(A, ASize, i, mid) && isUpSeq(A, ASize, mid, j);
}

bool isDownSeq(int *A, int ASize, int i, int j)
{
    if (j == i + 1)
    {
        if (A[i] >= A[j])
        {
            return true;
        }
        return false;
    }
    int mid = i + (j - i) / 2;
    return isDownSeq(A, ASize, i, mid) && isDownSeq(A, ASize, mid, j);
}

bool isMonotonic(int* A, int ASize) 
{
    if (1 == ASize)
    {
        return true;
    }
    return isUpSeq(A, ASize, 0, ASize -1) || isDownSeq(A, ASize, 0, ASize - 1);
}

int main()
{
    int a[] = {1,2,2,3};
    int iSize = sizeof(a) / sizeof(int);
    bool bRet = isMonotonic(a, iSize);
    if (bRet)
    {
        printf("true\n");
    }
    else
    {
        printf("false");
    }
}
