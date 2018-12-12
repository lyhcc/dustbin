#include<stdio.h>
#include<windows.h>
#include<math.h>
int main()
{
	double a;
	scanf("%lf", &a);
	printf("%.2lf %.2lf\n", a*a, 0.5*0.5*sqrt(3)*a*a);
	system("pause");
	return 0;
}