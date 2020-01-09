#include <math.h>
#include <stdio.h>

int arrangeCoins(int n) 
{
        return (int)(sqrt(2 * n + 0.25) - 0.5);
}

int main()
{
    int num = 10;
    int iRet = arrangeCoins(num);
    printf("%d\n", iRet);
    return 0;
}
