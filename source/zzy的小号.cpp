#include<stdio.h>
#include<string.h>
#include<ctype.h>
const int exp=1e9 + 7;
char s[100000];
int main()
{
	while (scanf("%s", s) == 1)
	{
		int i;
		long  long int ans = 1;
		for (i = 0; i < strlen(s); i++)
		{
			if (s[i] == 'I' || s[i] == 'l' || s[i] == 'i' || s[i] == 'L')
				ans = ans * 4 % exp;
			else if (s[i] == '0' || s[i] == 'O' || s[i] == 'o')
				ans = ans * 3 % exp;
			else if (isalpha(s[i]))ans = ans * 2 % exp;
			else ans *= 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}