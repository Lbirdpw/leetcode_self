#include <stdio.h>
#include <stdlib.h>

bool checkPerfectNumber(int num) 
{
    if (num <= 1)
    {
        return false;
    }

    int iSum = 0;
    for (int i = 1; i <= num / 2; ++i)        
    {
        if (num % i == 0)
        {
            iSum += i;
        }
    }
    if (iSum == num)
    {
        return true;
    }
    return false;
}
