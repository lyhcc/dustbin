#include<stdio.h>
#include<windows.h>
struct student {
	char num[10];
	char name[10];
	int score[3];
}s[100];
void input(int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		scanf("%s%s", s[i].num, s[i].name);
		for (j = 0; j < 3; j++)
			scanf("%d", &s[i].score[j]);
	}
}
void print(int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%s,%s,%d,%d,%d\n", s[i].num, s[i].name, s[i].score[0], s[i].score[1], s[i].score[2]);
}
int main()
{
	int n;
	scanf("%d", &n);
	input(n);
	print(n);
	system("pause");
	return 0;
}