#include<stdio.h>
#include<windows.h>
int main()
{
	int n;
	scanf("%d", &n);
	printf("%s\n", n % 5 == 0 ? "no" : "yes");
	system("pause");
	return 0;
}