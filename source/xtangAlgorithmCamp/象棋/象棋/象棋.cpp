#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
using namespace std;
const int N = 505 * 2, M = N * N; int a;
struct E {
	int next, to;
}e[M];
int cnt, ihead[N], mc[N];
bool vis[N];
void add(int x, int y)
{
	++cnt;
	e[cnt].next = ihead[x];
	e[cnt].to = y;
	ihead[x] = cnt;
}
bool dfs(int x)
{
	for (int i = ihead[x]; i; i = e[i].next)
	{
		int y = e[i].to;
		if (!vis[y]) {

			vis[y] = true;
			if (mc[y] == 0 || dfs(mc[y])) {
				mc[y] =x;
				return true;
			}
		}
	}
	return false;
}
int getAnswer(int n, vector<vector<int> >board)
{
	cnt = 0;
	for (int i = 1; i <= n*2; ++i)
	{
		ihead[i] = mc[i] = 0;
	}
	for(int i=1;i<=n;i++)
		for (int j = 1; j <= n; j++)
		{
			if (board[i - 1][j - 1] == 1) {
				add(i, j);
			}
		}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (1) {
			memset(vis, 0, sizeof(vis));
			if (dfs(i)) {
				ans++;
			}
		}
	}
	return ans;
}
int main() {
	int n;
	scanf("%d", &n);
	vector<vector<int>> e;
	for (int i = 0; i < n; ++i) {
		vector<int> t;
		for (int j = 0; j < n; ++j) {
			int x;
			scanf("%d", &x);
			t.push_back(x);
		}
		e.push_back(t);
	}
	printf("%d\n", getAnswer(n, e));
	return 0;
}
