#include<stdio.h>
int step;
void move(int n, char a, char b, char c)
{
	if (n >=1&&n<=2)
	{
		move(n - 1, a, c, b);
		step++;
		printf("%d\n", step);
		move(n - 1, b, a, c);
	}
}
int main()
{
	char a = 'a', b = 'b', c = 'c';
	int n,i;
	scanf("%d", &n);
	if (n < 2)
		move(n, a, b, c);
	else
		move(2, a, b, c);
	for (i = 3; i <= n; i++)
		step = step * 2 + 1;
	printf("%d\n",2* step);
	return 0;
}