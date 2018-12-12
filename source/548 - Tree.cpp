#include<stdio.h>
#include<string>
#include<iostream>
#include<sstream>
#include<string.h>
using namespace std;
const int maxv = 10000 + 10;
int n;
int in_order[maxv], post_order[maxv], lch[maxv], rch[maxv];
bool read_line(int *a)
{
	string line;
	//cout << line << endl;
	if (!getline(cin, line))return false;
	stringstream ss(line);
	n = 0;
	int x;
	while (ss >> x) { a[n++] = x;}
	return n > 0;
}

int build(int L1, int R1, int L2, int R2)
{
	if (L1 > R1)return 0;
	int root = post_order[R2];
	//cout << root << endl;
	int p = L1;
	while (in_order[p] != root)p++;
	int cnt = p - L1;
	lch[root] = build(L1, p - 1, L2, L2 + cnt - 1);
	rch[root] = build(p + 1, R1, L2 + cnt, R2 - 1);
	return root;
}
int best, best_sum;
void dfs(int u, int sum)
{
	sum += u;
	if (!lch[u] && !rch[u])
	{
		if (sum < best_sum || (best_sum == sum && u < best)) { best = u; best_sum = sum; }
	}
	if (lch[u])dfs(lch[u], sum);
	if (rch[u])dfs(rch[u], sum);
}
int main()
{
	while (read_line(in_order))
	{
		read_line(post_order);
		build(0, n - 1, 0, n - 1);
		best_sum = 1000000000;
		dfs(post_order[n - 1], 0);
		cout << best << endl;
	}
	return 0;
}