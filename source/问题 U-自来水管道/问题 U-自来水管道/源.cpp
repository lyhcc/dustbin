#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
const int N = 55;
struct loop {
	int v1;
	int v2;
	int cost;
	bool operator <(const loop&a)const {
		return a.cost > cost;
	}
};
int f[N];
vector<loop>r;
int find(int x)
{
	while (f[x] != x)x = f[x];
	return x;
}
int main()
{
	int P, R;
	while (scanf("%d %d", &P, &R) == 2 && P)
	{
		if (R == 0)
		{
			cout << R << endl;
			continue;
		}
		r.clear();
		for (int i = 1; i <= P; i++)f[i] = i;
		for (int i = 0; i < R; i++)
		{
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			if (a > b)swap(a, b);
			r.push_back({ a,b,c });
		}
		sort(r.begin(),r.end());
		int ans = 0;
		for (int i = 0; i < R; i++)
		{
			int setX = find(r[i].v1);
			int setY = find(r[i].v2);
			if (setX != setY)
			{
				ans += r[i].cost;
				f[setX] = setY;
			}
		}
		cout << ans << endl;
	}
	return 0;
}