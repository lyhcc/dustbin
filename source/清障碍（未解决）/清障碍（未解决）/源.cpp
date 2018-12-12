#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<windows.h>
int main()
{
	int kase = 0;
	int a[7][6];
	char s[10];
	int cnt;
	while (gets_s(s) != NULL)
	{
		//sscanf(s, "Case%d", &kase);
		//int len = strlen(s);
		//getchar();
		int cnt2 = 0;
		memset(a, 0, sizeof(a));
		int i, j, k;
		for (i = 1; i <= 5; i++)
		{
			gets_s(s);
			for (j = 1; j <= 4; j++)
			{
				a[i][j] = s[j - 1] - '0';
				if (a[i][j] == 1)cnt2++;
			}
		}
		int ans = 0;
	loop:for (k = 4; k >= 1; k--)
	{
		int cnt3 = cnt2;
		for (i = 1; i <= 5; i++)
			for (j = 1; j <= 4; j++)
			{
				cnt = 0;
				if (a[i][j] == 0)
				{
					if (a[i - 1][j] == 1)cnt++;
					if (a[i + 1][j] == 1)cnt++;
					if (a[i][j - 1] == 1)cnt++;
					if (a[i][j + 1] == 1)cnt++;
				}


				if (cnt == k)
				{
					ans++;
					cnt2 -= cnt;
					//printf("i=%d j=%d k=%d\n", i, j, k);
					a[i - 1][j] = 0;
					a[i + 1][j] = 0;
					a[i][j - 1] = 0;
					a[i][j + 1] = 0;
					goto loop;
				}
			}
	}
		 kase++;
		 printf("The result of case %d is %d\n", kase, ans);
	}
	system("pause");
	return 0;
}