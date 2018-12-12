#include<stdio.h>
#include<windows.h>
#include<string.h>
const int maxn = 100;
int b[maxn][maxn];
int step,ans;
void permutation(char*a, int k, int m)
{
	
	int i, j;
	if (k == m)
	{
		step++;
		printf("%4d:", step);
		for (i = 0; i <=m; i++)
			printf("%c", a[i]);
		int cnt = 0;
		for (i = 0; i <=m; i++)
			for (j = i + 1; j <=m; j++)
				if (a[i] > a[j])cnt++;
		int s = 1;
		for (i = 0; i <= m; i++)
			s *= b[i][a[i] - '1'];
		
		if (cnt % 2 == 0)ans =ans+ s;
		else ans =ans- s;
	}
	else
		for (j = k; j <= m; j++)
		{
			char t;
			t = a[j]; a[j] = a[k]; a[k] = t;
			permutation(a, k + 1, m);
			t = a[j]; a[j] = a[k]; a[k] = t;

		}
}
int main()
{
	char a[100];
	while (scanf("%s", a) == 1)
	{//fp = fopen("lll.txt", "w");
		step = 0;
		int i, j;
		int n=strlen(a);
		ans = 0;
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				scanf("%d", &b[i][j]);
		printf("所有全排列\n");
		permutation(a, 0, strlen(a) - 1);
		printf("%d\n",ans);
	}
	system("pause");
	return 0;
}