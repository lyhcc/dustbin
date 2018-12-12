#include<stdio.h>
#include<windows.h>
int main()
{
	long long int n,i;
	while (scanf("%lld", &n) == 1)
	{
		int s = 1;
		n = n % 100;
		for (i = 1; i <= n; i++)
			s = s * 13 % 1000;            	
		printf("%.3d\n", s);
	}
	system("pause");
	return 0;
}