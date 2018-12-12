#include<stdio.h>
#include<windows.h>
#include<math.h>
int is_prime(int n)
{
	int i;
	for (i = 2; i <=sqrt(n); i++)
		if (n%i == 0)
			return 0;
	return 1;
}
int main()
{
	int i,d,a[5],b[250];
	int count = 0;
	for (i = 1000; i <= 9999; i++)
	{
		int j = 1,t=i;
		d = 0;
		while (t)
		{
			
			a[j++] = t % 10;
			t = t / 10;
		}
		for (j = 1; j <=4; j++)
			d = d * 10 + a[j];
		
		if (is_prime(i) && is_prime(d))
		{
			
			printf("%d:%d\n",++count, i);
		}
	}
	system("pause");
	return 0;
}