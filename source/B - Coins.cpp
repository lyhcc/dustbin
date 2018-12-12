#include<stdio.h>
#include<windows.h>
int main()
{
	int a, b, c, x, i, k, j,count=0;
	scanf("%d %d %d %d", &a, &b, &c, &x);
	for (i = 0; i <= a; i++)
		for (j = 0; j <= b; j++)
			for (k = 0; k <= c; k++)
				if (i * 500 + j * 100 + k * 50 == x)
					count++;
	printf("%d\n", count);
	system("pause");
	return 0;
}