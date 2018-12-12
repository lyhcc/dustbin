#include<stdio.h>
#include<windows.h>
int main()
{
	int n;
	
	while (scanf("%d", &n) == 1)
	{
		long long int s = 1;
		int t = n;
		for (; t > n - 3; t--)
			s *= t;
		printf("%d\n", s);
	}
	system("pause");
	return 0;
}