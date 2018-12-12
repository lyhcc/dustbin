#include<stdio.h>
#include<windows.h>
int main()
{
	int E=0, V=0, F, n;
	scanf("%d", &n);
	for (int i = 0; i <= n - 2; i++)
	{
		E = E + i*(n - 2 - i)+1;
		V = V + i*(n - 2 - i);
	}
	E = E*n / 2 + n;
	V = V*n / 4 + n;
	printf("%d\n", E - V + 1);
	system("pause");
	return 0;
}