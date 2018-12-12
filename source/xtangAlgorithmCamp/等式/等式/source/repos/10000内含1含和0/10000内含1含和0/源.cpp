#include<windows.h>
#include<stdio.h>
int main()
{
	int i,n;
	int a[6];
	int count1 = 0, count2 = 0;
	for (i = 0; i <10000; i++)
	{
		int t = i; 
		n = 0;
		while (t)
		{
			a[n++] = t % 10;
			t = t / 10;
		}
		for (int j = 0; j < n; j++)
		{
			if (a[j] == 0)
			{

				count1++;
				break;
			}
		}
		for (int j = 0; j < n; j++)
			if (a[j] == 1)
			{

				count2++;
				break;
			}
	}
	printf("%d,%d\n", count1, count2);
	system("pause");
	return 0;
}