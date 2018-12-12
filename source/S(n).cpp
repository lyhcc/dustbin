#include<windows.h>
#include<stdio.h>
typedef long long LL;
int main()
{
	LL n;
	while (scanf("%lld", &n) == 1)
	{
		LL sum;
		sum = (n*(n + 1)%10000)*(n*(n + 1)%10000) / 4;
		printf("%.4lld\n", sum%10000);
	}
	system("pause");
	return 0;
}