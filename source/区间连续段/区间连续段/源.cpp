#include<stdio.h>
#include<algorithm>
using namespace std;
int n, m, k,a[1000000];
int main()
{
	
	scanf("%d %d %d", &n, &m, &k);
	int i;
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	for (i = 0; i < m; i++)
	{
		int l, r;
		scanf("%d %d", &l, &r);
		int j;
		if (l > a[n - 1] || r < a[0]) { printf("Chtholly\n"); continue;}
		int ans = 0,sum=0;
		int left=0, right=n-1, mid;
		while (left < right)
		{

		}
	}
	return 0;
}