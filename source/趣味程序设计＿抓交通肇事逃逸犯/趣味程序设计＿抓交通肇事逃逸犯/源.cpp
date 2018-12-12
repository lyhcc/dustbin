#include<stdio.h>
#include<windows.h>
#include<math.h>
int main()
{
	int i, j, m;
	for(i=1;i<=9;i++)
		for (j = 0; j <= 9; j++)
		{
			m = (i * 10 + i) * 100 + j * 10 + j;
			if (sqrt(m) == (int)sqrt(m))
			{
				printf("%d\n", m);	
				return 0;
			}
		}
	system("pause");
	return 0;
}