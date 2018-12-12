#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 10;

struct Tree {
	double l, r;
	Tree(int ll=0,int rr=0):l(ll),r(rr){}
};

int n;
bool vis[1<<MAXN];
double R, w[MAXN], sum[1<<MAXN];
vector<Tree>T[1<<MAXN];

void dfs(int s) {
	if (vis[s])return;
	vis[s] = true;//是否已经访问
	bool is_leaf = true;
	for (int left = (s - 1)&s; left; left = (left - 1)&s) {
		int right = s ^ left;
		is_leaf = false;
		dfs(left);
		dfs(right);
		double d1 = sum[right] / sum[s];//左力矩
		double d2 = sum[left] / sum[s];//右力矩
		for(int i=0;i<T[left].size();i++)
			for (int j = 0; j < T[right].size(); j++) {
				Tree t;
				t.l = max(d1 + T[left][i].l, T[right][j].l - d2);
				t.r = max(d2 + T[right][j].r, T[left][i].r - d1);
				if (t.l + t.r < R)T[s].push_back(t);
			}
		
	}
	if (is_leaf)T[s].push_back(Tree());
}
int main() {
	int kase;
	scanf("%d", &kase);
	while (kase--) {
		scanf("%lf%d" ,&R,&n);
		for (int i = 0; i < n; i++)scanf("%lf", &w[i]);
		if (n == 1) { printf("%.10lf\n", 0.0); continue; }
		for (int i = 0; i < (1 << MAXN); i++) {
			sum[i] = 0;
			T[i].clear();
			for (int j = 0; j < n; j++) {
				if (i&(1 << j))sum[i] += w[j];
			}
		}
		int root = (1 << n) - 1;
		memset(vis, false, sizeof(vis));
		dfs(root);

		double ans = -1;
		
		for (int i = 0; i <T[root].size(); i++) {
			ans = max(ans, T[root][i].l + T[root][i].r);
		}
		printf("%.10lf\n", ans);
		
	}
	return 0;
}