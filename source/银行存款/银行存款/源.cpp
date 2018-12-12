#include<stdio.h>
#include<math.h>
#define eps 1e-8
int main()
{
	int n;
	int a[] = { 1,2,3,5 };
	double r[4];
	scanf("%d %lf %lf %lf %lf", &n, &r[0] , &r[1] ,&r[2] ,& r[3]);
	double ans = 1;
	int i,m=3;
	for (i = 3; i >=0; i--)
	{
		int t = n/a[m] ;
		n = n % a[m];
		//if (n == 0)break;
		ans = ans * pow((1 + r[i]), t*a[m]);
		m--;
	}
	//printf("%.5lf\n", ans);
	//ans = ans * (1 + r[0]);
	printf("%.5lf\n", ans+eps);
	return 0;
}
