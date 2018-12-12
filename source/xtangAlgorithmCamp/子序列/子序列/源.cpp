#include<iostream>
#include<cstdio>
#include<vector>
#include<string.h>
using namespace std;
const int N = 500005, mo = 23333;
int f[N], p[N], last[N];
char s[N];
int getAnswer(int n)
{
	for (int i = 1; i <= n; ++i)
	{
		int a = s[i] - 'a';
		p[i] = last[a];
		last[a] = i;
	}
	for (int i = 1; i <= n; i++) {
		if (p[i] == 0)f[i] = (f[i - 1] % mo +f[i-1] % mo + 1)%mo;
		else f[i] = (f[i - 1] % mo +f[i-1] % mo - f[p[i] - 1])%mo;
	}
	return f[n]%mo;
}
int main() {
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	printf("%d\n", getAnswer(n));
	return 0;
}