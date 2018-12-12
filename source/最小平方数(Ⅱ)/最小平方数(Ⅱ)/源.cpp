#include<stdio.h>
#include<math.h>
#include<windows.h>
int main()
{
	int n;
	int i;
	scanf("%d", &n);
	for (i = 1;; i++)
	{
		if (sqrt((long long)n*i) == (long long)sqrt((long long)n*i))
			break;
	}
	printf("%d\n", i);
	system("pause");
	return 0;
}