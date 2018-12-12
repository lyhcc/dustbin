#include<stdio.h>
#include<windows.h>
#include<math.h>
int main()
{
	//printf("%lf", sqrt(999));
	int a[3], i;
	for (i = 10; i < sqrt(999); i++)
	{
		int j = 0,n=i*i;
		while (n)
		{
			a[j] = n % 10;
			n = n / 10;
			j++;
		}
		if (a[0] == a[1] && a[1] != a[2] || a[0] == a[2] && a[0] != a[1] || a[1] == a[2] && a[0] != a[1])
			printf("%d ",i*i);
	}
	system("pause");
	return 0;
}