#include<stdio.h>
#include<algorithm>
#include<windows.h>
using namespace std;
const int maxp = 10000 + 5;
int a[maxp],t;
int s(int n)
{
	if (n == 1)
		t = a[0];
	else if (n == 2)
		t = a[1];
	else if (n == 3)
		t = a[2] + a[0] + a[1];
	else if (n > 3)
	{
		if (2 * a[1] >= a[0] + a[n - 2])
			t = a[n - 2] + 2 * a[0] + a[n - 1]+s(n-2);
		else if (2 * a[1] < a[0] + a[n - 2])
			t = 2 * a[1] + a[0] + a[n - 1]+s(n - 2);
		
	}
	return t;
}
int main()
{
	int n;
	while (scanf("%d", &n) == 1)
	{
		int i;
		t = 0;
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);
		sort(a, a + n);
		s(n);
		printf("%d\n", t);
	}
	system("pause");
	return 0;
}