#include<stdio.h>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxINT = 1e8;
const int N = 1e4 + 10;
struct Tree {
	int data;
	int mark;
}T[N];
void CreateST(int root, int l, int r, vector<int>v)
{
	//T[root].mark=0;
	if (l == r) {
		T[root].data = v[l];
		return;
	}
	int mid = (l + r) >> 1;
	CreateST(root * 2 + 1, l, mid, v);
	CreateST(root * 2 + 2, mid + 1, r, v);
	T[root].data = min(T[root * 2 + 1].data, T[root * 2 + 2].data);
}
int RMQ(int root, int l, int r, int a, int b)
{
	if (a>r || b<l)
		return maxINT;
	if (a <= l && b >= r)return T[root].data;
	int mid = (l + r) >> 1;
	return min(RMQ(root * 2 + 1, l, mid, a, b), RMQ(root * 2 + 2, mid + 1, r, a, b));
}
int main()
{
	vector<int>v;
	int n, example;
	scanf("%d", &example);
	while (example--)
	{
		scanf("%d", &n);
		for (int i = 0; i<n; i++)
		{
			int x;
			scanf("%d", &x);
			v.push_back(x);
			//cout<<v[0]<<endl;
		}
		CreateST(0, 0, n - 1, v);
		int Q;
		scanf("%d", &Q);
		while (Q--)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			int ans = RMQ(0, 0, n - 1, a, b);
			cout << ans;
			if (Q != 0)cout << " ";
		}
		cout << endl;

	}

	return 0;
}