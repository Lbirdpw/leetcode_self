#include <stdio.h>

void printArr(int *a, int iSize)
{
    for (int i = 0; i < iSize; ++i)
    {
        printf("%d, ", a[i]);
    }
    printf("\n");
}

void swap(int *a, int i, int j)
{
    int iTmp = a[i] ^ a[j];
    a[i] = iTmp ^ a[i];
    a[j] = iTmp ^ a[j];
}

void buildMinHeap(int *a, int iSize)
{
    int iFirstNoLeaf = (iSize) / 2 - 1;
    for (int i = iFirstNoLeaf; i >= 0; --i)
    {
       int iLeftLeaf = 2 * i + 1; 
       int iRightLeaf = 2* i + 2;
       int iMin = a[i];
       int iInd = i;
       if (iLeftLeaf < iSize && iMin > a[iLeftLeaf])
       {
           iMin = a[iLeftLeaf];
           iInd = iLeftLeaf;
       }
       if (iRightLeaf < iSize && iMin > a[iRightLeaf])
       {
           iMin = a[iRightLeaf];
           iInd = iRightLeaf;
       }
       swap(a, i, iInd);
    }
}

int findKthLargest(int* nums, int numsSize, int k) 
{
    buildMinHeap(nums, k);        
    printArr(nums, numsSize); 
    for (int i = k; i < numsSize; ++i)
    {
        if (nums[i] > nums[0])
        {
            swap(nums, i, 0);
            buildMinHeap(nums, k);
            printArr(nums, numsSize); 
        }
    }
    return nums[0];
}

int main()
{
    int nums[] = {3,4,1,2,5};
    int numsSize = 5;
    int iVal = findKthLargest(nums, numsSize, 3);
    printf("%d\n", iVal);
    return 0;
}
