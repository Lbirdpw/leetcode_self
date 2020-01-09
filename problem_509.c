#include <stdio.h>

int fib(int N) 
{
    if (0 == N)        
    {
        return 0;
    }
    if (1 == N)
    {
        return 1;
    }
    int f0 = 0;
    int f1 = 1;
    int f = 0;
    for (int i = 2; i <= N; ++i)
    {
        f = f0 + f1;
        f0 = f1;
        f1 = f;
    }
    return f;
}
