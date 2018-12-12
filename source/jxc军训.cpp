#include<stdio.h>
#include<math.h>
const int p = 998244353;
int gcd(int m, int n)
{
	int r=1;
	while (r)
	{
		r = m % n; m = m / n; n = r;
	}
	//printf("%d\n", m);
	return m;
}
int main()
{
	int n,m;
	scanf("%d %d", &n, &m);
	int p, q;
	p = n * n - m; q = n * n;
	int g = gcd(q, p);
	p = p / g; q = q / g;
	long long int ans = (p)*pow(q,p-2);
	printf("%lld\n", ans%p);
	return 0;
}