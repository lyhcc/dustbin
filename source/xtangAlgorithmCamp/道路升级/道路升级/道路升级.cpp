#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int N = 500005;
struct UnionSet {
	int f[N];
	void init(int n) {
		for (int i = 1; i < n; i++)f[i] = i;
	}
	int find(int x) {
		int r = x;
		while (f[r] != r)r = f[r];
		return r;
	}
	bool merge(int x, int y)
	{
		int setX = find(x);
		int setY = find(y);
		if (setX == setY)return false;
		if (setX < setY)swap(setX, setY);
		f[setX] = f[setY];
		return true;
	}
}us;
vector<int> getAnswer(int n, int m, vector<int>U, vector<int>V)
{
	vector<int>ans;
	us.init(n);
	
	for (int i=m-1;i>=0;i--)
		if (us.merge(U[i], V[i]))ans.push_back(i+1);
	sort(ans.begin(), ans.end());
	return ans;
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	vector<int> U, V;
	for (int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		U.push_back(u);
		V.push_back(v);
	}
	vector<int> ans = getAnswer(n, m, U, V);
	printf("%d\n", int(ans.size()));
	for (int i = 0; i < int(ans.size()); ++i)
		printf("%d\n", ans[i]);
	return 0;
}
