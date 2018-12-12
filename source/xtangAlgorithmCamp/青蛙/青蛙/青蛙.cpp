#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<cmath>
using namespace std;
const int N = 1e6 + 10;
int dp[1000 + 5][1000 + 5];
struct A {
	int x;
	int s;
	bool operator <(const A&b)const {
		return x < b.x;
	}
}a[N], b[N];
bool cmp(const A&a, const A&b) {
	return a.s < b.s;
}
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i].x >> a[i].s;
	int ans = 0;
	
	for (int round = 1; round <= 2; round++)
	{
		sort(a + 1, a + n + 1);
		for (int i =1; i <= n; i++)
		{
			dp[i][i] = a[i].s;
			for (int j = 1; j < i; j++)
			{
				dp[i][j] = 0;
				for (int k = j; k&&(2 * a[j].x <= a[i].x + a[k].x); k--)
						dp[i][j] = max(dp[i][j], dp[j][k]);
				
				ans = max(ans, (dp[i][j] += a[i].s));
			}
				
		}
		for (int i = 1; i <= n; i++)
				a[i].x = -a[i].x;
	}

	cout << ans<<endl;
	return 0;
}