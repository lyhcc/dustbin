#include<stdio.h>
#include<windows.h>
int C(int m, int n)
{
	int p;
	if (n > m / 2)n = m - n;
	if (m == n || n == 0)
		p = 1;
	else
		p = C(m - 1, n - 1) + C(m - 1, n);
	return p;
}
int P( int n)
{
	int p=1;
	int i;
	for (i = 1; i <= n; i++)
		p *= i;
	return p;
}
int main()
{
	int t,n;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		int i, j, count = 0;
		for (i = 0; i <= n; i++)
			for (j = 0; j <= n/2; j++)
				if (i + j * 2 == n)
				{
					count++;
					//if (i > j)count=count+ C(i + j, j) / P(j);
				}
		//printf("%d\n", count);
		printf("%d\n", P(20));
	}
	system("pause");
	return 0;
}