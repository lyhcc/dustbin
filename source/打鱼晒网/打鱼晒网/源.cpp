#include<stdio.h>
#include<windows.h>
int main()
{
	int year, month, day;
	int a1[] = { 31,28,31,30,31,30,31,31,30,31,30,31 }, a2[] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	while (scanf("%d-%d-%d", &year, &month, &day) == 3)
	{
		int i, j;
		int sum = 0;
		for (i = 2000; i < year; i++)
			if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
				sum += 366;
			else
				sum += 365;
		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
			for (j = 0; j < month-1; j++)
				sum += a2[j];
		else
			for (j = 0; j < month-1; j++)
				sum += a1[j];
		sum += day;
		if (sum % 5 == 1 || sum % 5 == 2 || sum % 5 == 3)
			printf("He is fishing.\n");
		else
			printf("He is drying nets.\n");
	}
	system("pause");
	return 0;
}