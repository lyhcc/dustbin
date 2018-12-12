#include<iostream>
#include<string>
#include<string.h>
#include<stdio.h>
#include<vector>
using namespace std;
const int N = 50000 + 5;
int a[N];
int seq[3 * N ];
void buildseqTree(int root, int l, int r)
{
	if (l == r) { 
		seq[root] = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	buildseqTree(root * 2+1, l, mid);
	buildseqTree(root * 2 +2, mid + 1, r);
	seq[root] = seq[root * 2+1] + seq[root * 2 + 2];
}
int query(int root, int l, int r, int a, int b)
{
	if (b<l || a>r)return 0;
	if (a <= l && b >= r)return seq[root];
	int mid = (l + r) >> 1;
	return (query(root * 2+1, l, mid, a, b) + query(root * 2 + 2, mid + 1, r, a, b));
}
void add1(int root, int l, int r, int i, int j)
{
	if (l == r)
	{
		if (l == i)
			seq[root] += j;
		return;
	}
	int mid = (l + r) >> 1;
	if (i <= mid)add1(root * 2 + 1, l, mid, i, j);
	else add1(root * 2 + 2, mid + 1, r, i, j);
	seq[root] = seq[root * 2 + 1] + seq[root * 2 + 2];
}
void sub(int root, int l, int r, int i, int j)
{
	if (l == r)
	{
		if (l == i)
			seq[root] -= j;
		return;
	}
	int mid = (l + r) >> 1;
	if (i <= mid)sub(root * 2 + 1, l, mid, i, j);
	else sub(root * 2 + 2, mid + 1, r, i, j);
	seq[root] = seq[root * 2 + 1] + seq[root * 2 + 2];
}
int main()
{
	int T;
	scanf("%d", &T);
	for(int kase=1;kase<=T;kase++)
	{
		cout << "Case " << kase << ":" << endl;
		int n;
		scanf("%d", &n);
		for (int i = 1; i <=n; i++)
		{
			 scanf("%d", &a[i]);
			//a.push_back(x);
		}
		buildseqTree(1, 1, n);
		while (1)
		{
			string s;
			int i, j;
			cin >> s;
			if (s == "End")break;
			cin>> i >> j;
			
			if (s == "Query") {
				int ans = query(1, 1, n, i, j);
				cout << ans << endl;
			}
			else if (s == "Add")add1(1, 1, n, i,j);
			else if (s == "Sub")sub(1, 1, n, i, j);
			
		}
	}
	return 0;
}