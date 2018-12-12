#include<stdio.h>
#include<windows.h>
int main()
{
	int n;
	for (n = 6;; n++)
	{
		double p=n;
		for(int i = 1; i <= 5; i++)
			p = (p-1) / 5 * 4 ;
		if (p == (int)p)
		{
			printf("%d %d\n", n, (int)p);
			break;
		}
	}
	system("pause");
	return 0;
}