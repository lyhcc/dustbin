#include<stdio.h>
#include<string.h>
const int len = 32;
const int maxn = 1024+10;
char s[maxn];
int buf[len][len],cnt;
void draw(char*s, int &p, int r, int c,int w)
{
	char ch = s[p++];
	if (ch == 'p')
	{
		draw(s, p, r , c+ w / 2,w/2);
		draw(s, p, r, c, w / 2);
		draw(s, p, r + w/ 2, c, w / 2);
		draw(s, p, r + w / 2, c + w / 2, w / 2);
	}
	else if (ch == 'f')
	{
		for(int i=r;i<r+w;i++)
			for (int j = c; j < c + w; j++)
			{
				if (buf[i][j] == 0) { buf[i][j] = 1; cnt++; }
			}
	}
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int i;
		cnt = 0;
		memset(buf, 0, sizeof(buf));
		for (i = 1; i <= 2; i++)
		{
			scanf("%s", s);
			int p = 0;
			draw(s, p, 0, 0,len);
		}
		printf("There are %d black pixels.\n", cnt);
	}
	return 0;
}