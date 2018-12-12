#include<iostream>
#include<vector>
using namespace std;
const int N = 500005;
int father[N],Rank[N];
int find(int x) {
	int r=x;
	while (father[r] != r)r = father[r];
	return r;
}
string getAnswer(int n, int m, vector<int>A, vector<int>B, vector<int>E)
{
	for (int i = 1; i <= n; i++) { 
		father[i] = i;
		Rank[i] = 0;
	}
	for (int i = 0; i < m; ++i)
	{
		if (A[i] > B[i]) {
			swap(A[i], B[i]);
		}
	}
	int l=0, r=m-1;
	while (l < r)
	{
		while (E[l] == 1)l++;
		while (E[r] == 0)r--;
		if (r > l) {
			swap(A[l], A[r]);
			swap(B[l], B[r]);
			swap(E[l], E[r]);
		}
	}
	for (int i = 0; i < m; i++) {
		int setA = find(A[i]);
		int setB = find(B[i]);
		if (E[i] == 0)
		{
			if (setA==setB)
				return "No";
		}
		else {
			if (setA!=setB) {
				father[setB] =father[setA];
			}
		}
	}
	return "Yes";
}
int main() {
	int T;
	for (scanf("%d", &T); T--; ) {
		int n, m;
		scanf("%d%d", &n, &m);
		vector<int> A, B, E;
		for (int i = 0; i < m; ++i) {
			int a, b, e;
			scanf("%d%d%d", &a, &b, &e);
			A.push_back(a);
			B.push_back(b);
			E.push_back(e);
		}
		printf("%s\n", getAnswer(n, m, A, B, E).c_str());
	}
	return 0;
}