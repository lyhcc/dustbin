#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
vector<int>q;
int T[2 * 100000 + 5];
vector<int>arr;
int n;
void build(int root, int l, int r)
{
	if (l == r)
	{
		T[root] = arr[l]%n;
		return;
	}
	//cout << l << " " << r << endl;
	int mid = (l + r) >> 1;
	build(root * 2 + 1, l, mid);
	build(root * 2 + 2, mid + 1, r);
	T[root] =(T[root * 2 + 1] + T[root * 2 + 2])%n+1;
	cout << T[root] << ends;
}
int query(int root, int l, int r, int a, int b)
{
	if (a > r || b < l)return 0;
	if (a <= l && b >= r)return T[root];
	int mid = (l + r) >> 1;
	return (query(root * 2 + 1, l, mid, a, b) + query(root * 2 + 2, mid + 1,r, a, b));
}
int main()
{
	
	int  m, x, A, B, M;
	while (scanf("%d %d %d %d %d %d", &n, &m, &x, &A, &B, &M) == 6)
	{
		q.clear();
		//T.clear();
		arr.clear();
		int max = 0;
		for (int i = 0; i < m; i++)
		{
			int y; scanf("%d", &y);
			max = max > y ? max : y;
			q.push_back(y);
		}
		for (int i = 1; i <= max; i++)
		{
			arr.push_back(x+1);
			x = (x*A + B) % M;
			
		}
		build(0, 0, max - 1);
		for (int i = 0; i < m; i++)
		{
			cout << query(0, 0, max - 1,0, q[i]-1);
			if (i < m - 1)cout << " ";
		}
		cout << endl;
	}	
	return 0;
}