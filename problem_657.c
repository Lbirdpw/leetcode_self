#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool judgeCircle(char* moves) 
{
    int irow = 0;
    int icol = 0;
    while(*moves != '\0')
    {
        switch (*moves)
        {
            case 'D':
                icol -= 1;
                break;
            case 'U':
                icol += 1;
                break;
            case 'R':
                irow += 1;
                break;
            case 'L':
                irow -= 1;
                break;
        }
        ++moves;
    }
    if (irow == 0 && icol == 0)
    {
        return true;
    }
    return false;

}

int main()
{

}
