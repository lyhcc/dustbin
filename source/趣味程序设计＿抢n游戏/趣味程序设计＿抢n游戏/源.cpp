#include<stdio.h>
#include<windows.h>
int main()
{
	int n;
	while (scanf("%d", &n) == 1)
		printf("%s\n", n % 3 == 0 ? "no" : "yes");
	system("pause");
	return 0;
}