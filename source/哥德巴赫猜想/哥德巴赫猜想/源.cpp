#include<stdio.h>
#include<windows.h>
#include<math.h>
int is_prime(int n)
{
	int i;
	for (i = 2; i <= sqrt(n); i++)
		if (n%i == 0)
			return 0;
	return 1;
}
int main()
{
	int n;
	while (scanf("%d", &n) == 1)
	{
		int a= 2000;
		int i,b;
		for (i = 2; i <= n / 2; i++)
		{
			if (is_prime(i) && is_prime(n - i))
				//if (i < a) { a = i; b = n - i; }
				printf("%d=%d+%d\n", n, i, n - i);
		}
		//printf("%d %d\n", a, b);

	}
	system("pause");
	return 0;
}