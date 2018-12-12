#include<iostream>
#include<cstdio>
using namespace std;
const int N = 200000+10;
struct node {
	int l, r, value;
}seq[N*3];
int updatepos[N], v[N],ans[N];
void build(int root, int left, int right)
{
	seq[root].l = left;
	seq[root].r = right;
	seq[root].value = right - left + 1;
	if (left == right)return;
	int mid = (left + right)/2;
	build(root * 2, left, mid);
	build(root * 2 + 1, mid + 1, right);
}
void query(int pos, int root,int num)
{
	if (seq[root].l == seq[root].r)
	{
		seq[root].value = 0;
		ans[seq[root].l] = num;
		//cout << seq[root].l << endl;
		return;
	}
	//cout << pos << endl;
	if (seq[root * 2].value >= pos)query(pos, root * 2, num);
	else query(pos - seq[root * 2].value, root * 2 + 1, num);
	seq[root].value = seq[root * 2].value + seq[root * 2 + 1].value;
}
int main()
{
	int n;
	while (scanf("%d", &n) == 1)
	{
		build(1, 1, n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d %d", &updatepos[i], &v[i]);
		}
		for (int i = n; i >= 1; i--)
		{
			query(updatepos[i] + 1, 1, v[i]);
		}
		for (int i = 1; i <= n; i++)
		{
			printf("%d%c", ans[i], ' ');

		}
		printf("\n");
	}
	return 0;
}