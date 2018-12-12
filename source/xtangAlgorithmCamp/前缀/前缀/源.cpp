#include<iostream>
#include<cstdio>
using namespace std;
const int M=505, L = 1000005;
int c[L][26], sz[L], cnt;
void add(char*s)
{
	int x = 0;
	for (; *s; ++s)
	{
		int y = *s - 'a';
		if (!c[x][y])c[x][y] = ++cnt;
		x = c[x][y];
	}
	++sz[x];
}
void dfs(int x)
{
	for (int y = 0; y < 26; ++y)
	{
		int z = c[x][y];
		if (z) {
			dfs(z);
			sz[x] = sz[x] + sz[z];
		}
	}
}
int walk(char*s)
{
	int x = 0;
	for (; *s; ++s)
	{
		int y = *s - 'a';
		if (!c[x][y])return 0;
		x = c[x][y];
	}
	return x;
}
char s[M];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (; n--;) {
		scanf("%s", s);
		add(s);
	}
	dfs(0);
	sz[0] = 0;
	for (; m--;) {
		scanf("%s", s);
		printf("%d\n", sz[walk(s)]);
	}
	return 0;
}