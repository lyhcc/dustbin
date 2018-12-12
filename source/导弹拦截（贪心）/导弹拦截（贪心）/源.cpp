#include<cstdio>  
#include<cstring>  
#include<cctype>  
#include<algorithm>  
using namespace std;

const int maxn = 1e5;
struct tnode {
	int d1, d2;
}p[maxn + 20];

int getin()
{
	int ans = 0; char tmp; bool sign = 0;
	while (!isdigit(tmp = getchar()) && tmp != '-');
	if (tmp == '-')sign = 1, tmp = getchar();
	do ans = (ans << 3) + (ans << 1) + tmp - '0';
	while (isdigit(tmp = getchar()));
	return sign ? -ans : ans;
}

bool cmp(tnode a, tnode b)
{
	return a.d1>b.d1;
}

int main()
{
	int x1, y1, x2, y2;
	int n, i, j, k, r2, ans;
	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
	n = getin();
	for (k = 0; k<n; k++)
	{
		scanf("%d%d", &i, &j);
		p[k].d1 = (i - x1)*(i - x1) + (j - y1)*(j - y1);
		p[k].d2 = (i - x2)*(i - x2) + (j - y2)*(j - y2);
	}
	sort(p, p + n, cmp);
	ans = p[0].d1, r2 = p[0].d2;
	for (i = 1; i <= n; i++)
	{
		ans = min(ans, p[i].d1 + r2);
		r2 = max(p[i].d2, r2);
	}
	printf("%d\n", ans);
	return 0;
}