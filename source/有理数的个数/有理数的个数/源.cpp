#include<cstdio>
#include<windows.h>
#include<algorithm>
#include<string.h>
using namespace std;
const int maxm = 100000;
int p[maxm + 20];
int count1[maxm + 20];
struct rational {
	int a, b;
	double c;
	bool operator <(const rational &q)const {
		return c < q.c;
	}
}s[maxm + 20];
int gcd(int m, int n)
{
	int r;
	while (n)
	{
		r = m%n;
		m = n;
		n = r;
	}
	return m;
}
int main()
{
	int m, i, j, n;

	scanf("%d", &n);
	while (n--)
	{
		memset(count1, 0, sizeof(count1));
		scanf("%d", &m);
		for (i = 0; i < m; i++)
		{
			scanf("%d/%d", &s[i].a, &s[i].b);
			s[i].c = (s[i].a * 1.0) / s[i].b;
		}
		sort(s, s + m);
		for (i = 0, j = 0; i < m; i++)
		{
			p[j++] = i;
			count1[p[j - 1]]++;
			while (s[i].c == s[i + 1].c&&i< m)i++, count1[p[j - 1]]++;
		}
		printf("%d\n", j);

		for (i = 0; i < j; i++) {
			int g = gcd(s[p[i]].a, s[p[i]].b);
			printf("%d/%d %d\n", s[p[i]].a / g, s[p[i]].b / g, count1[p[i]]);
		}
	}

	system("pause");
	return 0;
}