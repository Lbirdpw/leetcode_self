#include <stdio.h>

int numJewelsInStones(char* J, char* S)
{
    int a[255] = {0};
    char *pJ = J;
    while (*pJ != '\0')
    {
        a[*pJ] = a[*pJ] + 1;
        ++pJ;
    }
    int res = 0;
    char *pS = S;
    while (*pS != '\0')
    {
        if (a[*pS] > 0)
        {
            ++res;
        }
        ++pS;
    }
    return res;
}

int main()
{
    char *J = "aA";
    char *S = "aAAbbbb";
    int res = numJewelsInStones(J, S);
    printf("%d\n", res);
    return 0;
}
