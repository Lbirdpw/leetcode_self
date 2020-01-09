#include <stdio.h>

bool isOneBitCharacter(int* bits, int bitsSize) 
{
    int i = 0;
    for (i = 0; i < bitsSize - 1;)        
    {
        if (bits[i] == 1)
        {
            i += 2;
        }
        else
        {
            i += 1;
        }
    }
    if (i == bitsSize - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
