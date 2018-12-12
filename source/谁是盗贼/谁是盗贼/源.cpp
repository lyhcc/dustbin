#include<stdio.h>
#include<windows.h>
int main()
{
	int a, b, c, d;
	for (a = 0; a <= 1; a++)
		for (b = 0; b <= 1; b++)
			for (c = 0; c <= 1; c++)
				for (d = 0; d <= 1; d++)
					if (b+d==1&&b+c==1&&a+b==1&&(a+b+c+d==1)||b+d!=1&&b+c!=1&&a+b!=1&&a+b+c+d==1)
						printf("%d %d %d %d\n", a, b, c, d);
	system("pause");
	return 0;
}