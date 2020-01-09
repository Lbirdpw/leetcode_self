#include <stdio.h>
#include <stdbool.h>

bool isMonotonic(int* A, int ASize) 
{
    if (1 == ASize)
    {
        return true;
    }
    int iType = 0;
    if (A[0] < A[ASize - 1])
    {
        iType = -1;
    }
    else if (A[0] > A[ASize - 1])
    {
        iType = 1;
    }
    else
    {
        iType = 0;
    }
    for (int i = 0; i < ASize - 1; ++i)
    {
        for (int j = i; j < ASize; ++j)
        {
            if (iType == -1)
            {
                if (A[i] > A[j])
                {
                    return false;
                }
            }
            else if(iType == 0)
            {
                if (A[i] != A[j])
                {
                    return false;
                }
            }
            else
            {
                if (A[i] < A[j])
                {
                    return false;
                }
            }
        }
    }

    return true;
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
