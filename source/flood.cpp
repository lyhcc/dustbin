
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int m, n, i, j;
	int h[35][35];
	int a[1600], mm = 0;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
		{
			scanf("%d", &h[i][j]);
			a[mm++] = h[i][j];
		}
	sort(a, a + n*m);
	double area = 0, v, maxh = 0;
	scanf("%lf", &v);
	int count1 = 0;
	for (i = 1; i<n*m; i++) {
		area += 100;
		count1++;
		v = v - area*(a[i] - a[i - 1]);
		if (v < 0) {
			v = v + area*(a[i] - a[i - 1]);
			maxh += v / area; break;
		}
		maxh += a[i] - a[i - 1];
		if (v == 0)break;
	}
	printf("%lf,%lf\n", maxh + a[0], 1.0*count1 / n / m);
	return 0;
}
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int m, n, i, j;
	int h[35][35];
	int a[1600], mm = 0;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
		{
			scanf("%d", &h[i][j]);
			a[mm++] = h[i][j];
		}
	sort(a, a + n*m);
	double area = 0, v, maxh = 0;
	scanf("%lf", &v);
	int count1 = 0;
	for (i = 1; i<n*m; i++) {
		area += 100;
		count1++;
		v = v - area*(a[i] - a[i - 1]);
		if (v < 0) {
			v = v + area*(a[i] - a[i - 1]);
			maxh += v / area; break;
		}
		maxh += a[i] - a[i - 1];
		if (v == 0)break;
	}
	printf("%lf,%lf\n", maxh + a[0], 1.0*count1 / n / m);
	return 0;
}