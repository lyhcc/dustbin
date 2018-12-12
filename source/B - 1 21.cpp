#include<stdio.h>
//#include<windows.h>

int main()
{
	
	int a, b,c;
	char s[10];
	scanf("%d%d", &a, &b);
			sprintf(s, "%d%d", a, b);
			sscanf(s, "%d", &c);
			int i;
			for (i = 1; i <= 101; i++)
				if (c == i*i)
				{
					printf("Yes\n");
					break;
				}
			if (i > 101)
				printf("No\n");
//	system("pause");
	return 0;
}
/*#include<stdio.h>
#include<windows.h>
#include<math.h>
#include<string.h>
int main()
{
	int a, b,c;
	char s[10];
	scanf("%d%d", &a, &b);
	sprintf(s, "%d", b);
	int i;
	c = a;
	for (i = 1; i <= strlen(s); i++)
		c = c * 10;
	c = c + b;
	for(i=1;i<=200;i++)
		if (c == i*i)
		{
			printf("Yes\n");
			break;
		}
	if (i > 200)
		printf("No\n");
	system("pause");
	return 0;
}*/