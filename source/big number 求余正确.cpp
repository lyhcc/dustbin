#include<stdio.h>
#include<windows.h>
#include<string.h>
int main()
{
	char s[1000];
	int n, i;
	while (scanf("%s", s) == 1 && scanf("%d", &n) == 1)
	{
		int len = strlen(s);
		//printf("%d\n", len);
		int t = 0;
		//printf("%d\n", s[0] - '0');
		for (i = 0; i < len; i++)
		{
			t = t * 10 + s[i] - '0';
			//printf("%d\n", t);
			t = t%n;
		}
		printf("%d\n", t);
	}
	system("pause");
	return 0;
}