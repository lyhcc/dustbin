#include<stdio.h>
#include<windows.h>
int main()
{
	char a, b, c;
	for(a='X';a<='Z';a++)
		for(b='X';b<='Z';b++)
			for (c = 'X'; c <= 'Z'; c++)
			{
				if (a != 'X'&&c != 'X'&&c != 'Z'&&a!=b&&b!=c&&a!=c)
					printf("A-%c B-%c C-%c\n", a, b, c);

			}
	system("pause");
	return 0;
}