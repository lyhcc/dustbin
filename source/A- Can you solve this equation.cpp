#include<stdio.h>
#include<math.h>
#include<windows.h>
#define eps 1e-7
double y;
int ok;
double f(double x)
{
	return 8 * x*x*x*x + 7 * x*x*x + 2 * x*x + 3 * x + 6 - y;
}
double binary_search(double low, double high)
{

	while (high - low >eps)
	{
		double mid = (low + high) / 2;
		if (f(high) == 0) { ok = 1; return high; }
		if (f(low) == 0) {
			ok = 1; return low;
		}
		if (f(high)*f(mid) < 0) { low = mid; ok = 1; }
		else high = mid;
	}
	return low;
}
int  main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		double  x;
		ok = 0;
		scanf("%lf", &y);
		double low = 0, high = 100;
		x = binary_search(low, high);
		if (ok)printf("%.4lf\n", x + eps);
		else printf("No solution!\n");
	}
	system("pause");
	return 0;
}