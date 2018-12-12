#include<stdio.h>
#include<windows.h>
int sub(int n)
{
	int t;
	if (n == 1)
	{
		static int i = 0;
		do {
			i++;
		} while (i % 5 != 0);
		printf("i=%d\n", i);
			return i + 1;
	}
	else
	{
		do {
			t=sub(n - 1);
		} while (t % 4 != 0);
		printf("t=%d\n", t);
		return (t / 4 * 5 + 1);
	}
}
int main()
{
	int total;
	total = sub(5);
	printf("the number is %d\n", total);
	system("pause");
	return 0;
}