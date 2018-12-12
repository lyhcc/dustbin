#include<stdio.h>
#include<windows.h>
double area2(double x0, double y0, double x1, double y1, double x2, double y2)
{
	return x0*y1 + y0*x2 + x1*y2 - x2*y1 - x0*y2 - x1*y0;
}
int main()
{
	int x, y;
	double x0, y0, x1, y1, x2, y2;
	while (scanf("%lf%lf%lf%lf%lf%lf", &x0, &y0, &x1, &y1, &x2, &y2) == 6)
	{
		int count = 0;
		double area = area2(x0, y0, x1, y1, x2, y2),s;
		for(x=2;x<=99;x++)
			for (y = 1; y <= 99; y++)
			{
				s = area2(x, y, x1, y1, x2, y2) + area2(x, y, x0, y0, x1, y1) + area2(x, y, x2, y2, x0, y0);
				if (s == area)
				{
					count++;
					if(count<=10)
					printf("x=%d,y=%d\n", x, y);
				}
			}
		printf("%d\n", count);
	}
	system("pause");
	return 0;
}