#include <stdio.h>
#include <stdbool.h>

bool validMountainArray(int* a, int ASize) 
{
    if (ASize < 3)        
    {
        return false;
    }
    int i = 0;
    int j = ASize - 1;
    while (i < ASize - 1 && a[i] < a[i + 1])
    {
        ++i;
    }
    while (j > 0 && a[j] < a[j - 1])
    {
        --j;
    }
    if (j == 0 || i == ASize - 1)
    {
        return false;
    }
    if (i == j)
    {
        return true;
    }
    return false;
}

int main()
{
    int arr[] = {0,1,2,4,2,1};
    //int arr[] = {1,3,2};
    int iSize = sizeof(arr) / sizeof(int);
    bool bRes = validMountainArray(arr, iSize);
    if (bRes)
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }
    
    return 0;
}
