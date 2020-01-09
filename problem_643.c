#include <stdio.h>
#include <limits.h>

int getSum(int *arr, int iSize)
{
    int iSum = 0;
    for (int i = 0; i < iSize; ++i)
    {
        iSum += arr[i];
    }
    return iSum;
}

double findMaxAverageV1(int* nums, int numsSize, int k) 
{
    int iMax = -INT_MAX - 1.0;
    int *p = nums;
    for (int i = k - 1; i < numsSize; ++i)        
    {
        int iSum = getSum(p, k);
        ++p;
        if (iSum > iMax)
        {
            iMax = iSum;
        }
    }
    return (double)iMax / k;
}

double findMaxAverage(int* nums, int numsSize, int k) 
{
    if (numsSize < k)
    {
        return -INT_MAX - 1.0;
    }

    int *p = nums;
    int iSum = getSum(p, k);
    int iOldSum = iSum;
    for (int i = k; i < numsSize; ++i)        
    { 
        iSum = iSum - p[i - k] + p[i];
        if (iSum > iOldSum)
        {
            //printf("%d, %d\n", i, iSum);
            iOldSum = iSum;
        }
    }
    return (double)iOldSum / k;
}

int main()
{
    int nums[] = {1,12,-5,-6,50,3};
    int iSize = sizeof(nums) / sizeof(int);
    int k = 4;
    double dVal = findMaxAverage(nums, iSize, k);
    printf("%f\n", dVal);
    return 0;
}
