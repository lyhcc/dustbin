#include<stdio.h>
#include<windows.h>
unsigned int len = 1e10;
unsigned long long int ans[100000001];
void multi(int n)
{
	int i,last=0;
	for (i = 1; i <= ans[0]; i++)
	{
		ans[i] = ans[i] * n + last;
		last = ans[i] / len;
		ans[i] = ans[i] % len;
	}
	if (last)ans[++ans[0]] = last;
}
int main()
{
	unsigned int n, i;
	scanf("%d", &n);
	ans[0] = 1,ans[1]=1;
	for (i = 1; i <= n; i++)multi(i);
	printf("%d", ans[ans[0]]);
	for (i = ans[0] - 1; i >= 1; i--)printf("%.10d", ans[i]);
	printf("\n");
	system("pause");
	return 0;
}