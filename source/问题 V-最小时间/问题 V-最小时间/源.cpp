#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<vector>
using namespace std;
const int maxInt = 0;
const int N = 105;
int G[N][N],D[N][N];
int main()
{
	int n;
	while (scanf("%d", &n) == 1)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				G[i][j] = maxInt;
		for (int i = 1; i <= n-1; i++)
		{
			for (int j = 1; j <= i; j++)
			{
				string s;
				int x;
				cin >> s;
				x = atoi(s.c_str());
				G[i][j] = G[j][i] = x;
			}
		}
		int ans = 0;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				printf("%-8d", G[i][j]);
			cout << endl;
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				D[i][j] = G[i][j];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				for (int k = 0; k < n; k++)
					if (D[i][k] + D[k][j] < D[i][j])
						D[i][j] = D[i][k] + D[k][j];
		for (int i = 0; i < n; i++)
			ans = ans > D[i][0] ? ans : D[i][0];
		cout << ans << endl;
	}
	return 0;
}