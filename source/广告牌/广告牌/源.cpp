#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int N = 200000;
int h, w, n;
struct node {
	int l, r, m;
}seq[3*N];
void build(int ll, int rr, int root)
{
	seq[root].l = ll;
	seq[root].r = rr;
	seq[root].m = w;
	if (ll == rr)return;
	int mid = (ll + rr) >> 1;
	build(ll, mid, root * 2);
	build(mid + 1, rr, root * 2 + 1);
}
void update(int root, int tmp)
{
	if (seq[root].l == seq[root].r)
	{
		seq[root].m -= tmp;
		printf("%d\n", seq[root].l);
		return;
	}
	if (tmp <= seq[root * 2].m)update(root * 2, tmp);
	else update(root * 2 + 1, tmp);
	seq[root].m = max(seq[root * 2].m, seq[root * 2 + 1].m);
}
int main()
{

	while (scanf("%d %d %d", &h, &w, &n)==3)
	{
		
		build(1, min(h,n),1);
		//cout << seq[1].m << "HJ" << endl;
		for(int i=1;i<=n;i++)
		{
			int tmp;
			scanf("%d", &tmp);
			if (seq[1].m <tmp)printf("-1\n");
			else
			{
				update(1, tmp);
			}
		}
	}
	return 0;
}