#include <stdio.h>
#include <stdbool.h>

bool IsEven(int i)
{
    if (i % 2 == 0)
    {
        return true;
    }
    return false;
}

void Swap(int *arr, int i, int j)
{
    arr[i] = arr[i] ^ arr[j];
    arr[j] = arr[i] ^ arr[j];
    arr[i] = arr[j] ^ arr[i];
}

int* sortArrayByParityII(int* A, int ASize, int* returnSize) 
{
    int iEven = 0;
    int iOdd = ASize - 1;
    while (iEven < ASize && iOdd > 0)
    {
       if (!IsEven(A[iEven])) 
       {
           while (iOdd > 0 && ( !IsEven(A[iOdd])))
           {
               iOdd -= 2;
           }
           if (iOdd > 0)
           {
               Swap(A, iEven, iOdd); 
           }
       }
       else
       {
           iEven += 2;
       }
    }
    *returnSize = ASize;
    return A;
}

int main()
{
    int A[] = {4,2,5,7};
    int iSize = sizeof(A) / sizeof(int);
    int iRetSize = 0;
    int *retArr = sortArrayByParityII(A, iSize, &iRetSize);
    int i = 0;
    for (i = 0; i < iRetSize; ++i)
    {
        printf("%d,", retArr[i]);
    }
    printf("\n");

    return 0;
}
