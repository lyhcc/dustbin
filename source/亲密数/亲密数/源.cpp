#include<stdio.h>
#include<windows.h>
int main()
{
	int n, i,j;
	for (i = 2; i <= 3000; i++)
	{
		int sum = 0;
		for (j = 1; j < i; j++)
		{
			if (i%j == 0)
				sum += j;
		}
		int sum2=0;
		for (j = 1; j < sum; j++)
		{
			if (sum%j == 0)
				sum2 += j;
		}
		if (i < sum&&i==sum2)
			printf("(%d,%d)", i, sum);
	}
	system("pause");
	return 0;
}