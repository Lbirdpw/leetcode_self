#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *twoSum(int *nums, int numsSize, int target)
{
	int *p = (int *)malloc(2 * sizeof(int));
	memset(p, 0, 2 * sizeof(int));

	for (int i = 0; i < numsSize - 1; ++i)
	{
		p[0] = i;
		for (int j = i + 1; j < numsSize; ++j)
		{
			if (nums[i] + nums[j] == target)	
			{
				p[1] = j;
				return p;
			}
		}
	}
	return p;

}

int main()
{
	int a[4] = {2, 7, 11, 15};
	int * p = twoSum(a, sizeof(a) / sizeof(int), 9);
	printf("[%d, %d]\n", p[0], p[1]);
	free(p);
	return 0;
}
