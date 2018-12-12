#include<stdio.h>
#include<windows.h>
int main()
{
	int a, b, c, n;
	while (scanf("%d%d%d%d", &a, &b, &c, &n) == 4)
	{
		int i, j, k,count=0;
		for (i = 0; i <= a; i++)
			for (j = 0; j <= b; j++)
				for (k = 0; k <= c; k++)
					if (i + k + j == n)
						count++;
		printf("%d\n", count);
	}
	system("pause");
	return 0;
}