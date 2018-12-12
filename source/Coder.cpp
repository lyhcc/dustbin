#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;

const int N = 100000+5;
typedef long long ll;
struct SeqTree {
	int num;
	ll sum[5];
}seq[N*4];
int a[N],x[N];
char cmd[N][10];
void build(int l, int r, int root) {
	seq[root].num = 0;
	if (l == r) {
		memset(seq[root].sum, 0, sizeof(seq[root].sum));
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, root * 2);
	build(mid + 1, r, root * 2 + 1);
	memset(seq[root].sum, 0, sizeof(seq[root].sum));
}
void pushUp(int root) {
	for (int i = 0; i < 5; i++) {
		seq[root].sum[i] = seq[root * 2].sum[i] + seq[root * 2 + 1].sum[((i - seq[root * 2].num) % 5 + 5) % 5];
	}
	
}
void upDate(int l, int r, int root,int k,int val,int op) {
	op ? ++seq[root].num : --seq[root].num;
	if (l == r) {
		seq[root].sum[0] = op*val;
		return;
	}
	int mid = (l + r) >> 1;
	if (k <= mid)upDate(l, mid, root * 2, k,val,op);
	else upDate(mid + 1, r, root * 2 + 1, k,val,op);
	//seq[root].num = seq[root * 2].num + seq[root * 2 + 1].num;
	pushUp(root);
}

int main() {

	int n;
	
	while (scanf("%d", &n) !=EOF) {
		int len = 0;
		for (int i = 0; i < n; i++) {
			scanf("%s", cmd[i]);
			if (cmd[i][0] != 's') {
				scanf("%d", &a[i]);
				x[len++] = a[i];
			}
		}
		sort(x, x + len);
		len = unique(x, x + len) - x;
		build(1, len, 1);
		int k;
		for (int i = 0; i < n; i++)
		{
			if (cmd[i][0] == 's') {
				
				printf("%lld\n",seq[1].sum[2]);
			}
			else if (cmd[i][0] == 'a') {
				k = (int)(lower_bound(x, x + len, a[i])-x)+1;
				upDate(1, len, 1,k,a[i],1);
			}
			else if (cmd[i][0] == 'd') {
				k = (int)(lower_bound(x, x + len, a[i])-x)+1;
				upDate(1, len, 1, k,a[i],0);
			}
		}
		


	}
	return 0;
}
