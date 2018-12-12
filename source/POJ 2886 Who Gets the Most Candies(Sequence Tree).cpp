#include<iostream>
#include<math.h>
#include<cstdio>
using namespace std;
const int N = 5000000+10;

int s[40] = { 1,2,4,6,12,24,36,48,60,120,180,240,360,720,840,1260,1680,2520,5040,7560,10080,15120,20160,25200,27720,45360,50400,55440,83160,110880,166320,221760,277200,332640,498960,500001
};
//因子数打表
int b[40] = { 1,2,3,4,6,8,9,10,12,16,18,20,24,30,32,36,40,48,60,64,72,80,84,90,96,100,108,120,128,144,160,168,180,192,200,1314521 };
int next_pos[N];
char name[N][11];
struct SeqTree {
	int val;
	int left,right;
}seq[N*4];
void build(int l,int r,int root) {
	seq[root].left = l;
	seq[root].right = r;
	seq[root].val = r - l + 1;
	if (l == r)return;
	int mid = (l + r) / 2;
	build(l, mid, root * 2);
	build(mid + 1, r, root * 2 + 1);
}
int query(int value, int root) {

	seq[root].val--;
	if (seq[root].left == seq[root].right)return seq[root].right;
	if (seq[root * 2].val >= value)return query(value, root * 2);
	else query(value - seq[root * 2].val, root * 2 + 1);
}
int main() {
	int n, k;
	while (scanf("%d %d", &n, &k) == 2)
	{
		for (int i = 0; i < n; i++)
			scanf("%s %d", name[i], &next_pos[i]);
		build(0, n - 1, 1);
		int ind, imax = 0;
		int &num = seq[1].val;
		int i = 1;
		while (s[i] <= n)i++;
		imax =b[i - 1];
		int p = s[i - 1],pos;
		for (i = 1; i <= p&&num; i++) {
			pos = query(k, 1);
			if (num == 0)break;
			if (next_pos[pos] > 0)
				k = ((k - 2 + num) % num + next_pos[pos]) % num + 1;
			else
				k = ((k - 1 +next_pos[pos]) % num   + num) % num + 1;
			
		}
	
		printf("%s %d\n", name[pos], imax);
	}

	return 0;
}