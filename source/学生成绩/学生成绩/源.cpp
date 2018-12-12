#include<windows.h>
#include<stdio.h>
#include<string.h>
struct student
{
	char num[11];
	int score[3];
	int total;
}stu1[41];
int main()
{
	int n;
	int a[40];
	char c[11];
	scanf("%d", &n);
	int i,j;
	for (i = 0; i < n; i++)
	{
		scanf("%s", stu1[i].num);
		stu1[i].total = 0;
		for (j = 0; j < 3; j++)
		{
			scanf("%d", &stu1[i].score[j]);
			stu1[i].total += stu1[i].score[j];
		}
	}
	int m = 0,t;
	for (i = 0; i < n-1; i++)
	{
		int max = i;
		for (j = i + 1; j < n; j++)
		{
			if (stu1[j].total > stu1[max].total)max = j;
			else if (stu1[j].total == stu1[max].total)
			{
				if (stu1[j].score[0] > stu1[max].score[0]) { max = j; printf("%d %d\n", max,j); }
				else if (stu1[j].score[1] > stu1[max].score[1] && stu1[j].score[0] == stu1[max].score[0])max = j;
				else if (stu1[j].score[2] > stu1[max].score[2] && stu1[j].score[1] == stu1[max].score[1] && stu1[j].score[0] == stu1[max].score[0])max = j;
				else if (strcmp(stu1[max].num, stu1[j].num) > 0&&stu1[j].score[2] == stu1[max].score[2] && stu1[j].score[1] == stu1[max].score[1] && stu1[j].score[0] == stu1[max].score[0]) { max = j; printf("%d %d\n", max,j); }
			}
			//printf("%d\n", max);
		}
		if(max!=i)
		{
			strcpy(c, stu1[max].num);
			strcpy(stu1[max].num, stu1[i].num);
			strcpy(stu1[i].num, c);
			t = stu1[i].score[0]; stu1[i].score[0] = stu1[max].score[0]; stu1[max].score[0] = t;
			t = stu1[i].score[1]; stu1[i].score[1] = stu1[max].score[1]; stu1[max].score[1] = t;
			t = stu1[i].score[2]; stu1[i].score[2] = stu1[max].score[2]; stu1[max].score[2] = t;
			t = stu1[i].total; stu1[i].total = stu1[max].total; stu1[max].total = t;

		}
	}
	for (i = 0; i < n; i++)
			printf("%s %d %d %d %d\n", stu1[i].num, stu1[i].total, stu1[i].score[0], stu1[i].score[1], stu1[i].score[2]);
	system("pause");
	return 0;
}