#include<stdio.h>
#include<windows.h>
int a[11],q=1;
int m[] = { 0,1,5,10,20,50,100 };
void f(int w)
{
	for (int i = 6; i >= 1; i--) {
		a[q] += w / m[i];
		w = w%m[i];
	}
}
int main()
{
	int i, j, n, k, p;
	int ans[11] = { 0 };
	scanf("%d %d %d", &n, &k, &p);
	for (i = 1; i <= k; i++)
	{
		f(i*p);
		ans[i] += a[i] * (n / i);
		int t = a[i];
		f((n%i)*p);
		ans[i] += a[i] - t;
		q++;
	}
	int min = ans[1];
	for (i = 2; i <= k; i++)
		min = min < ans[i] ? min : ans[i];
	printf("%d\n", min);
	system("pause");
	return 0;
}