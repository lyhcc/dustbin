#include<stdio.h>
#include<windows.h>
int main()
{
	int n;
	scanf("%d", &n);
	int i, j, k,count=0;
	for (i = 0; i <= n; i++)
		for (j = 0; j <= n; j++)
			for (k = 0; k <= n; k++)
				if (i * 2 + j == n&&i + k + j == n)
					count++;
	printf("%d\n", count);
	system("pause");
	return 0;
}