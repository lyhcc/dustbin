#include<stdio.h>
int main()
{
	int n;
	while (scanf("%d", &n) == 1 && n != -1)
	{
		while (n--)
		{
			int d, k;
			int ans = 1;
			scanf("%d %d", &d, &k);
			for (int i = 1; i < d; i++)
			{
				if (k % 2) { ans = ans * 2; k = (k + 1) / 2; }
				else { ans = ans * 2 + 1; k = k / 2; }
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}