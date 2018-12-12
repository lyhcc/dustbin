#include<windows.h>
#include<stdio.h>
int main()
{
	int n=0, i, j;
	int a[40];
	for (i = 0; i < 40; i++)
		a[i] = 1;
	for(i=2;i<40;i++)
		for (j = 2; j <=i; j++)
			if (i%j==0&&40%j==0)
				a[i-1] = 0;
		for (j = 0; j < 39; j++)
		{
			if (a[j] == 1)
			{
				printf("%d/%d,", j + 1, 40);
			}

		}
		printf("\n");
	system("pause");
	return 0;
}