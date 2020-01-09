#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* toLowerCase(char* str) 
{
    if (NULL == str)
    {
        return NULL;
    }
    char * p = str;
    while (*p != '\0')        
    {
        *p = tolower(*p);
        ++p;
    }
    return str;
}

int main()
{
    char a[] = "Hello";
    char *p = toLowerCase(a);
    printf("%s\n", p);
    return 0;
}
