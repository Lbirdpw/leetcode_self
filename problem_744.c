#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int BinSearch(char *arr, int iStart, int iEnd, char key)
{
    int iMid = (iStart + iEnd) / 2;
    while (iStart <= iEnd)
    {
        if (arr[iMid] < key)
        {
            return BinSearch(arr, iMid + 1, iEnd, key);
        }
        else if (arr[iMid] > key)
        {
            return BinSearch(arr, iStart, iMid - 1, key);
        }
        else
        {
            return iMid;
        }
    }
    return iStart;
}

char nextGreatestLetter(char* letters, int lettersSize, char target) 
{
    if (letters[0] > target || letters[lettersSize - 1] < target)
    {
        return letters[0];
    }
    int iRet = BinSearch(letters, 0, lettersSize - 1, target); 
    if (letters[iRet] != target)
    {
        return letters[iRet];
    }
    int i = iRet;
    for (; i < lettersSize; ++i)
    {
        if (letters[i] != target)
        {
            break;
        }
    }
    if (i != lettersSize)
    {
        return letters[i];
    }
    return letters[0];
}


int main()
{
    char *str = "cfg";
    int iLen = strlen(str);
    char target = 'c';
    char ch = nextGreatestLetter(str, iLen, target);
    printf("%c\n", ch);
}
