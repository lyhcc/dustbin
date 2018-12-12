#include<stdio.h>
#include<windows.h>
int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	long long int i,count=0;
	printf("%d %d\n", a, b);
	for (i = a; i <= b; i++)
	{
		if (i % 9 == 0 && i % 21 == 0)
			count++;
	}
	printf("%d\n", count);
	system("pause");
	return 0;
}