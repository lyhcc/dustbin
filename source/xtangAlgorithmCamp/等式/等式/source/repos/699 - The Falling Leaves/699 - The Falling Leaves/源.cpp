#include<iostream>
#include<string.h>
const int maxn = 80;
using namespace std;
int sum[maxn];
void build(int p)
{
	int v;
	cin >> v;
	if (v == -1)return;
	sum[p] += v;
	build(p - 1); build(p + 1);
}
bool init()
{
	int v;
	memset(sum, 0, sizeof(sum));
	cin >> v;
	if (v == -1)return false;
	int pos = maxn / 2;
	sum[pos] = v;
	build(pos - 1);
	build(pos + 1);
}
int main()
{
	int kase = 0;
	while (init())
	{
		int p=0;
		
		while (sum[p] == 0)p++;
		cout << "Case " << ++kase << ":\n"<<sum[p++];
		while (sum[p] != 0)cout << " " << sum[p++];
		cout << "\n\n";
		
	}
	return 0;
}