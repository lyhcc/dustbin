#include<stdio.h>
#include<string.h>
const int maxn = 100 + 10;
int G[maxn][maxn];
int c[maxn], topo[maxn], t,n;
int u, v,m;
bool dfs(int u)
{

	c[u] = -1;
	for (int v = 1; v <= n; v++)
	if (G[u][v]) {
		if (c[v] < 0)return false;
		else if (!c[v] && !dfs(v))return false;
	}
	c[u] = 1; topo[--t] =u;
	return true;

}
bool toposort()
{
	t = n;
	int u;
	memset(c, 0, sizeof(c));
	for (u = 1; u <= n; u++)
		if (!c[u])
			if (!dfs(u))return false;
	return true;
}
int main()
{
	
	while (scanf("%d %d", &n, &m) == 2 && n&&m)
	{
		memset(G, 0, sizeof(G));
		printf("%d\n", G[n-1][n-1]);
		int i;
		for (i = 0; i < m; i++)
		{
			scanf("%d %d", &u, &v);
			G[u][v] = 1;
		}
		if (toposort())
		{
			printf("%d", topo[0]);
			for (i = 1; i < n; i++)
				printf(" %d", topo[i]);
		}
		printf("\n");
	}
	return 0;
}