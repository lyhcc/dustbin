#include<stdio.h>
#include<windows.h>
int main()
{
	int a[2][105], n, s[105] = {0};
	int count;
	scanf("%d", &n);
	int i, j, sum[2] = {0};
	for(i=0;i<2;i++)
		for (j = 0; j < n; j++)
		{
			scanf("%d", &a[i][j]);
			sum[i] += a[i][j];
		}
	int tot=0;
	for (i = 0; i < n; i++)
	{
		tot += a[0][i];
		s[i] = tot + sum[1];
		sum[1] = sum[1] - a[1][i];
	}
	int max=s[0];
	for (i = 1; i < n; i++)
		max = max > s[i] ? max : s[i];
	printf("%d\n", max);
	system("pause");
	return 0;
}