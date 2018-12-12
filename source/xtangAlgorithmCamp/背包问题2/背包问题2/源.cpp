#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int N = 5005;
int d[N][N], f[N][N];
vector<int> getAnswer(int n, vector<int>w, vector<int>v, int q, vector<int>qV, vector<int>qx)
{
	for (int i = 1; i <= n; ++i)
	{
		for (int V = 0; V < v[i]; ++V)
			d[i][V] = d[i - 1][V];
		for (int V = v[i]; V <= 5000; ++V)
			d[i][V] = max(d[i - 1][V], d[i - 1][V - v[i]] + w[i]);
	}
	for (int i = n; i >= 1; --i)
	{
		for (int V = 0; V<v[i] ; ++V)
			f[i][V] = f[i +1][V];
		for (int V = v[i]; V <=5000; ++V)
			f[i][V] = max(f[i+1][V], f[i +1][V - v[i]] + w[i]);
	}
	vector<int>ans;
	for (int k = 1; k <= q; k++)
	{
		int x = qx[k], V = qV[k];
		int mx = 0;
		for (int i = 0; i <= V; ++i)
			mx = max(mx,d[x-1][i]+f[x+1][V-i]);
		ans.push_back(mx);
	}
	return ans;
}
int main() {
	int n, q;
	vector<int> v, w, qv, qx;
	v.push_back(-1);
	w.push_back(-1);
	qv.push_back(-1);
	qx.push_back(-1);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		v.push_back(a);
		w.push_back(b);
	}
	scanf("%d", &q);
	for (int i = 0; i < q; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		qv.push_back(a);
		qx.push_back(b);
	}
	vector<int> ans = getAnswer(n, w, v, q, qv, qx);
	for (int i = 0; i < q; ++i)
		printf("%d\n", ans[i]);
	return 0;
}

