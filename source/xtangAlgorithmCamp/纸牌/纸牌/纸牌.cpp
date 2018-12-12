#include<iostream> 
#include<algorithm>
#include<cstdio>
#include<string.h>
using namespace std;
const int maxInt = 1e9 + 5;
const int N = 50005;
int a[N], b[N];
bool vis[N];
int binary_search(int n,int k) {
	int l = 1, r = n;
	int ans;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (a[mid] < k) l= mid+1;
		else r = mid-1;
	}
	return l;
}
int main()
{
	int n;
	ios::sync_with_stdio(false);
	cin >> n;
	memset(vis, true, sizeof(vis));
	for (int i = 1; i <= n; i++)cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (int i = 1, j = 1, k = 1; i <= 2 * n; i++)
	{
		if (a[k] == i) { k++; continue;}
		if (a[k] != i) {
			b[j++] = i;
		}
	}
	sort(b + 1, b + 1 + n);
	int ans = 0;
	int j;
	for (int i = 1; i <= n; i++)
	{
		j = binary_search(n, b[i])-1;
		while (!vis[j] && j > 0)j--;
		if (j == 0)continue;
		vis[j] = false;
		ans++;
	}
	cout <<ans << endl;
	return 0;
}/*
 2
 1 4
 2 3
 4
 1 3 2 6
 4 5 7 8
 */