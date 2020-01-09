#include <stdio.h>
#include <string.h>

void GetHashTable(char *str, int *pHash)
{
    int iLen = strlen(str);
    for (int i = 0; i < iLen; ++i)
    {
        char ch = str[i] - 'a';
        pHash[ch] += 1;
    }
}

char findTheDifference(char* s, char* t) 
{
    int HashTableS[26] = {0};        
    GetHashTable(s, HashTableS);

    int HashTableT[26] = {0};        
    GetHashTable(t, HashTableT);
    
    for (int i = 0; i < 26; ++i)
    {
        if (HashTableS[i] != HashTableT[i])
        {
            return i + 'a';
        }
    }
    return '\0';
}

int main()
{
    char *s = "abcd";
    char *t = "abcde";
    char ch = findTheDifference(s, t);
    printf("%c\n", ch);
}
