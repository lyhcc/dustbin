#include<windows.h>
#include<stdio.h>
#include<string.h>
char s1[6], s2[6],c[6];
int inquire()
{
	for (int i = 0; i < strlen(s1); i++)
		if (s1[i] != s2[i])return 0;
	return 1;
}
void revolve(int n)
{
	char t;
	memcpy(c, s1, sizeof(s1));
	if (n ==1)
	{
		s1[0] = c[2];s1[2] = c[5];s1[3] = c[0];s1[5] = c[3];
	}
	else if(n==2)
	{
		s1[0] = c[1]; s1[1] = c[5]; s1[5] = c[4]; s1[4] = s1[0];
	}
	else
	{
		s1[3] = c[1]; s1[1] = c[2]; s1[2] = c[4]; s1[4] = c[3];
	}
}
int main()
{
	scanf("%s %s", s1, s2);
	int i, j, k;
	char q[6];
	memcpy(q, s1, sizeof(s1));
	for (i = 0; i <= 3; i++)
	{
		if (i > 0)revolve(1);
		for (j = 0; j <= 3; j++)
		{
			if (j > 0)revolve(2);
			for (k = 0; k <= 3; k++)
			{
				if (k > 0)revolve(3);
				if (inquire()) { printf("Yes\n"); return 0; }
			}
		}
	}
	memcpy(s1, c, sizeof(c));
	for (i = 0; i <= 3; i++)
	{
		if (i > 0)revolve(1);
		for (j = 0; j <= 3; j++)
		{
			if (j > 0)revolve(3);
			for (k = 0; k <= 3; k++)
			{
				if (k > 0)revolve(2);
				if (inquire()) { printf("Yes\n"); return 0; }
			}
		}
	}
	memcpy(s1, c, sizeof(c));
	for (i = 0; i <= 3; i++)
	{
		if (i > 0)revolve(2);
		for (j = 0; j <= 3; j++)
		{
			if (j > 0)revolve(1);
			for (k = 0; k <= 3; k++)
			{
				if (k > 0)revolve(3);
				if (inquire()) { printf("Yes\n"); return 0; }
			}
		}

	}
	memcpy(s1, c, sizeof(c));
	for (i = 0; i <= 3; i++)
	{
		if (i > 0)revolve(2);
		for (j = 0; j <= 3; j++)
		{
			if (j > 0)revolve(3);
			for (k = 0; k <= 3; k++)
			{
				if (k > 0)revolve(1);
				if (inquire()) { printf("Yes\n"); return 0; }
			}
		}
	}
	memcpy(s1, c, sizeof(c));
	for (i = 0; i <= 3; i++)
	{
		if (i > 0)revolve(3);
		for (j = 0; j <= 3; j++)
		{
			if (j > 0)revolve(1);
			for (k = 0; k <= 3; k++)
			{
				if (k > 0)revolve(2);
				if (inquire()) { printf("Yes\n"); return 0; }
			}
		}
	}
	memcpy(s1, c, sizeof(c));
	for (i = 0; i <= 3; i++)
	{
		if (i > 0)revolve(3);
		for (j = 0; j <= 3; j++)
		{
			if (j > 0)revolve(2);
			for (k = 0; k <= 3; k++)
			{
				if (k > 0)revolve(1);
				if (inquire()) { printf("Yes\n"); return 0; }
			}
		}
	}
	printf("No\n");
	system("pause");
	return 0;
}