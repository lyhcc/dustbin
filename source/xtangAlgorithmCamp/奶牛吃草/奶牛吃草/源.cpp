#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
const int N = 2000;
int dp[N + 2][N + 2][2];
int getAnswer(int n, int k,vector<int>x)
{
	sort(x.begin() + 1, x.end());
	for (int i = 1; i <= n; i++)
		dp[i][i][0] = dp[i][i][1] = abs((x[i]-k)*n);
	for(int len=1;len<n;++len)
		for (int l = 1, r; (r = l + len) <= n; l++)
		{
			dp[l][r][0] = min(dp[l + 1][r][0] + (n - r + l)*abs(x[l]-x[l+1]),
				dp[l + 1][r][1] + (n - r + l)*abs(x[l]-x[r]));
			dp[l][r][1] = min(dp[l][r-1][0] + (n - r + l)*abs(x[r]-x[l]),
				dp[l][r-1][1] + (n - r + l)*abs(x[r]-x[r-1]));
		}
	return  min(dp[1][n][0], dp[1][n][1]);
}
int main() {
	int n, k, tmp;
	vector<int> x;
	scanf("%d%d", &n, &k);
	x.clear();
	x.push_back(-1);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &tmp);
		x.push_back(tmp);
	}
	int ans = getAnswer(n, k, x);
	printf("%d\n", ans);
	return 0;
}
