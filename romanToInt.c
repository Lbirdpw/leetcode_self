#include <stdio.h>

int charToNum(char c)
{
	switch (c)
	{
		case 'I':
			return 1;
		case 'V':
			return 5;
		case 'X':
			return 10;
		case 'L':
			return 50;
		case 'C':
			return 100;
		case 'D':
			return 500;
		case 'M':
			return 1000;
		default:
			return 0;
	}
}

int romanToInt(char *s)
{
	int res = 0;
	if (*s == '\0')
	{
		return res;
	}
	char pre = *s;
	while (*s != '\0')	
	{
		char cur = *s;
		int iPre = charToNum(pre);
		int iCur = charToNum(cur);
		if (iCur > iPre)
		{
			res = res - 2 * iPre + iCur;
		}
		else
		{
			res += iCur;
		}
		pre = *s;
		++s;
	}
	return res;
}

int main()
{
	int i = romanToInt("III");
	printf("%d\n", i);
	i = romanToInt("IV");
	printf("%d\n", i);
	i = romanToInt("IX");
	printf("%d\n", i);
	i = romanToInt("LVIII");
	printf("%d\n", i);
	i = romanToInt("MCMXCIV");
	printf("%d\n", i);
	return 0;
}
