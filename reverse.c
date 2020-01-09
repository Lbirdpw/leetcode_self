#include <stdio.h>
#include <stdlib.h>

int reverse(int x)
{
	int res;
	int bNeg = 0;
	if (x < 0)
	{
		x = abs(x);
		bNeg = 1;	
	}
	res = x % 10;
	while (( x = x / 10) != 0)
	{
		int tmp = x % 10;	
		res = res * 10 + tmp;
		int tmpRes = res;
		if ((res - tmp) / 10 != tmpRes)
		{
			return 0;
		}
	}
	if (bNeg == 1)
	{
		res = 0 - res;
	}
	return res;
}

int main()
{
	int iReverse = reverse(-123);
	printf("%d\n", iReverse);
	return 0;
}
