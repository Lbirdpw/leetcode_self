#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>


char * longestCommonPrefix(char **strs, int strsSize)
{
	if (strsSize <= 0)
	{
		return "";
	}
	char *str0 = strs[0];
	if (*str0 == '\0')
	{
		return "";
	}
	int n = 0;
	bool bBreak = false;
	while (*str0 != '\0')
	{
		for (int i = 1; i < strsSize; ++i)
		{
			if (strs[i][n] != '\0' && strs[i][n] == *str0)
			{
				continue;
			}
			else
			{
				bBreak = true;	
				break;
			}
		}
		if (bBreak)
		{
			break;
		}
		++str0;
		++n;
	}
	int len = strlen(strs[0]) + 1;
	char *p = (char *)malloc(len);
	memset(p, 0, strlen(strs[0]));
	for (int i = 0; i < n; ++i)
	{
		p[i] = strs[0][i];
	}
	p[n] == '\0';
	return p;

}

int main()
{
	char *strs[] = {"a"};
	char *p = longestCommonPrefix(strs, 1);
	printf("%s\n", p);
	free(p);
	return 0;
}
