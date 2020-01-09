#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPalindrome(int x)
{
	int res;
	int bNeg = 0;
	if (x < 0 || (x % 10 == 0))
	{
		return false;
	}
	res = x % 10;
	while (( x = x / 10) != 0)
	{
		int tmpRes = res;
		int tmp = x % 10;	
		res = res * 10 + tmp;
		if ((res - tmp) / 10 != tmpRes)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int iReverse = isPalindrome(10);
	printf("%d\n", iReverse);
	return 0;
}
