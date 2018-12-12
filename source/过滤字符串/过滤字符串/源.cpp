#include<stdio.h>
#include<string.h>
#include<windows.h>
char str[10000], s[10000],c[10000];
int main()
{
	int i,k;
	gets_s(str);
	gets_s(s);
	for(i=0,k=0;str[i];i++)
		if (strchr(s, str[i]) == NULL)
		{
			c[k++] = str[i];
		}
	printf("%s\n", c);
	system("pause");
	return 0;
}