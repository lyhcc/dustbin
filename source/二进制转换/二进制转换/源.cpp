#include<stdio.h>
#include<windows.h>
int main()
{
	int n;
	while (scanf("%d", &n) == 1)
	{
		int a[35],i=0;
		while (n)
		{
			a[i++] = n % 2;
			n = n / 2;
		}
		for (int j = i-1; j >=0; j--)
			printf("%d", a[j]);
		printf("\n");

	}
	system("pause");
	return 0;
}