#include<cstdio>
#include<vector>
#include<functional>
#include<queue>
#include<string.h>
#include<iostream>
using namespace std;
const int N = 100005;
typedef pair<int,int>pii;
vector<pii>graph[N];
priority_queue<pii, vector<pii>, greater<pii> >pq;
bool flag[N];
int mind[N];
int shortestPath(int n, int m, vector<int>U, vector<int>V, vector<int>W, int s, int t)
{
	while (!pq.empty())
		pq.pop();
	for (int i = 1; i <= n; i++)graph[i].clear();
	memset(mind, 127, sizeof(mind));
	memset(flag, 0, sizeof(flag));
	for (int i = 0; i < m; i++)
	{
		graph[U[i]].push_back(make_pair(V[i], W[i]));
		graph[V[i]].push_back(make_pair(U[i], W[i]));
	}
	mind[s] = 0;
	pq.push(make_pair(mind[s],s));

	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();
		if (!flag[u]) {
			flag[u] = 1;
			for (vector<pii>::iterator it = graph[u].begin(); it != graph[u].end(); it++)
			{
				int v = it->first, w = it->second;
				if (mind[v]<=mind[u]+w)continue;
				mind[v] = mind[u] + w;
		
				pq.push(make_pair(mind[v], v));
			}
		}
	}
	return mind[t];
}
int main() {
	int n, m, s, t;
	scanf("%d%d%d%d", &n, &m, &s, &t);
	vector<int> U, V, W;
	U.clear();
	V.clear();
	W.clear();
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		U.push_back(u);
		V.push_back(v);
		W.push_back(w);
	}

	printf("%d\n", shortestPath(n, m, U, V, W, s, t));
	return 0;
}