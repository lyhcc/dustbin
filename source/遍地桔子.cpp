#include<stdio.h>
#include<windows.h>
#include<string.h>
int a[20][20];
int p, n, m, k;
void judge(int i, int j)
{
	if (i - 1 >= 0)p++;
	if (j - 1 >= 0)p++;
	if (i + 1 <= n - 1)p++;
	if (j + 1 <= m - 1)p++;
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d %d %d", &n, &m, &k);
		memset(a, 0, sizeof(a));
		//printf("%d\n", a[0][0]);
		p = m*n;
		//printf("%d\n", p);
		int i, j;
		for (i = 1; i<n - 1; i++)
			for (j = 1; j<m - 1; j++)
				if (a[i][j] == 0 && k > 0) { p += 5; k--; a[i][j] = 1; }
		int c = 0, b = n - 1;
		for (j = 1; j < m - 1; j++)
		{
			if (a[c][j] == 0 && k > 0) { p++; k--; a[c][j] = 1; judge(c, j); }
			if (a[b][j] == 0 && k > 0) { p++; k--; a[b][j] = 1; judge(b, j); }
		}
		b = m - 1;
		for (i = 1; i < n - 1; i++)
		{
			if (a[i][c] == 0 && k > 0) { p++; k--; a[i][c] = 1; judge(i, c); }
			if (a[i][b] == 0 && k > 0) { p++; k--; a[i][b] = 1;  judge(i, b); }
		}
		b = n - 1; j = 0;
		if (a[c][j] == 0 && k > 0) { p++; k--; a[c][j] = 1; judge(c, j); }
		if (a[b][j] == 0 && k > 0) { p++; k--; a[b][j] = 1; judge(b, j); }
		j = m - 1;
		if (a[c][j] == 0 && k > 0) { p++; k--; a[c][j] = 1; judge(c, j); }
		if (a[b][j] == 0 && k > 0) { p++; k--; a[b][j] = 1; judge(b, j); }
		printf("%d\n", p);
	}
	system("pause");
	return 0;
}