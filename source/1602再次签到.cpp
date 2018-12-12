#include<windows.h>
#include<stdio.h>
#include<math.h>
int main()
{
	int n;
	int ans, k, x;
	while (scanf("%d", &n) == 1)
	{
		ans = k = 0;
		x = (int)sqrt(2.0*n) + 1;
		do {
			while (x*(x + 1) > 2 * n)x--;
			ans += x;
			n = n - x * (x + 1) / 2;
			if (n > 0)k++;
		}while(n>0);
		if (n == 1)ans++;
		printf("%d %d\n", ans, k);
	}
	system("pause");
	return 0;
}