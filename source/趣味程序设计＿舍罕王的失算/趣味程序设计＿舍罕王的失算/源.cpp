#include<stdio.h>
#include<windows.h>
int main()
{
	int n;
	while (scanf("%d", &n) == 1)
	{
		int i, a = 1;
		unsigned long long int sum ;
		for (sum = 1, i = 1; i <= n; i++)
			sum = sum * 2;
		printf("%llu\n", sum-1);
	}
	system("pause");
	return 0;
}