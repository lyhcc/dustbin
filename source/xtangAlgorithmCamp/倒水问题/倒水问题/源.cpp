#include<iostream>
#include<cstdio>
#include<algorithm>
#include<math.h>
#include<string.h>
using namespace std;
typedef pair<int, int>pii;

const int N = 2003;
int mind[N][N];
pii q[N*N];
int qh, qt;
pii to(pii p, int k, int n, int m)
{ 
	pii qq;
	switch (k) {
	case 0:return pii(0, p.second);
	case 1:return pii(p.first, 0);
	case 2:return pii(n, p.second);
	case 3:return pii(p.first, m);
	case 4:
		qq =(p.second + p.first > n) ? pii(n, (p.second + p.first - n)) : pii(p.first + p.second, 0);
		return qq;
	case 5: qq = (p.second + p.first > m) ? pii((p.second + p.first - m), m) : pii(0, p.first + p.second);
		return qq;
	default:return p;
	}
}
int getAnswer(int n, int m, int t, int d)
{
	memset(mind, -1, sizeof(mind));
	qh = qt = 0;
	q[++qt] = pii(0, 0);
	mind[0][0] = 0;

	while (qh < qt)
	{
		pii u = q[++qh];
		if (mind[u.first][u.second] == t)
			break;
		for (int k = 0; k < 6; ++k)
		{
			pii v = to(u, k, n, m);
			if (mind[v.first][v.second] !=-1)continue;
			q[++qt] = v;
			mind[v.first][v.second] = mind[u.first][u.second]+1;
		}
	}
	int ans = d;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; ++j)
			if (mind[i][j]!=-1)ans = min(ans,abs(d-(i+j)));
	return ans;
}
int main() {
	int n, m, t, d;
	scanf("%d%d%d%d", &n, &m, &t, &d);
	int ans = getAnswer(n, m, t, d);
	printf("%d\n", ans);
	return 0;
}