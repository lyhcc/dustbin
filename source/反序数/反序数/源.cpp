#include<stdio.h>
#include<windows.h>
int main()
{
	
	int a[6];
	int i, j,d;
	for (i = 1000; i <= 9999; i++)
	{
		int n=1;
		d = 0;
		int t = i;
		while (t)
		{
			a[n++] = t % 10;
			t /= 10;
		}
		for (j = 1; j <= 4; j++)
			d = d * 10 + a[j];
		if (i * 9 == d)
			printf("%d\n", i);
	}
	system("pause");
	return 0;
}