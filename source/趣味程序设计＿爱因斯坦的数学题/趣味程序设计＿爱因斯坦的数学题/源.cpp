#include<stdio.h>
#include<windows.h>
int main()
{
	int n;
	int i;
	while (scanf("%d", &n) == 1)
	{
		int count = 0;
		for (i = 118; i <= n; i++)
			if (i % 2 == 1 && i % 3 == 2 && i % 5 == 4 && i % 6 == 5 && i % 7 == 0)
			{
				count++;
				printf("%d\n", i);
			}
		printf("%d\n", count);
	}
	system("pause");
	return 0;
}