#include<stdio.h>
#include<windows.h>
#include<string.h>
void insert(char s[], char t, int i)
{
	char string[100];
	if (!strlen(s))
		string[0] = t;
	else
	{
		strncpy(string, s, i);
		string[i] = t;
		string[i + 1] = '\0';
		//strcat(string, t);
		strcat(string, (s + i));
		strcpy(s, string);

	}
}
int main()
{
	char str1[100],c;
	int position;
	printf("Please input str1:\n");
	gets_s(str1);
	printf("please input a char:\n");
	scanf("%c", &c);
	printf("please input position:\n");
	scanf("%d", &position);
	insert(str1, c, position);
	puts(str1);
	system("pause");
	return 0;
}