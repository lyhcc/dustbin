#include<cstdio>
#include<vector>
#include<iostream>
using namespace std;
bool check(long long d, int n, int m, vector<int>&a)
{
	long long sum = 0;
	int cnt = 1;
	for (int i = 0; i < n; ++i)
	{
		if (a[i] > d)return false;
		sum += a[i];
		if (sum > d) { cnt++; sum = a[i]; }
	}
	if(cnt<=m)
		return true;
	return false;
}
long long int getAnswer(int n, int m, vector<int>a)
{
	long long int l = 1, r = 0;
	for (int i = 0; i < n; ++i)
		r += a[i];
	while (l <= r)
	{
		long long int mid = (l + r) >> 1;
		if (check(mid, n, m, a))r = mid - 1;
		else l = mid + 1;
		
	}
	return r + 1;
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	vector<int> a;
	a.resize(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	printf("%lld\n", getAnswer(n, m, a));
	return 0;
}

