/*
Description

Farmer John's cows have discovered that the clover growing along the ridge of the hill (which we can think of as a one-dimensional number line) in his field is particularly good.

Farmer John has N cows (we number the cows from 1 to N). Each of Farmer John's N cows has a range of clover that she particularly likes (these ranges might overlap). The ranges are defined by a closed interval [S,E].

But some cows are strong and some are weak. Given two cows: cowi and cowj, their favourite clover range is [Si, Ei] and [Sj, Ej]. If Si <= Sj and Ej <= Ei and Ei - Si > Ej - Sj, we say that cowi is stronger than cowj.

For each cow, how many cows are stronger than her? Farmer John needs your help!
Input

The input contains multiple test cases.
For each test case, the first line is an integer N (1 <= N <= 105), which is the number of cows. Then come N lines, the i-th of which contains two integers: S and E(0 <= S < E <= 105) specifying the start end location respectively of a range preferred by some cow. Locations are given as distance from the start of the ridge.

The end of the input contains a single 0.
Output

For each test case, output one line containing n space-separated integers, the i-th of which specifying the number of cows that are stronger than cowi.
Sample Input

3
1 2
0 3
3 4
0
Sample Output

1 0 0

*/
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

#define LL(x) (x<<1)
#define RR(x) (x<<1|1)
#define MID(a,b) (a+((b-a)>>1))

const int N = 1e5 + 10;
struct Cow {
	int s, e, id;
	Cow() {}
	Cow(int a, int b, int d) :s(a), e(b), id(d) {}
	bool operator<(const Cow&x)const{
		return s<x.s || (s == x.s&&e>x.e);
	}
}cow[N];
struct node {
	int left, right, sum;
	int mid() { return MID(left,right); }
};
int result[N], n;

struct Segtree {
	node tree[4 * N];
	void build(int l, int r, int index) {
		tree[index].left = l;
		tree[index].right = r;
		tree[index].sum = 0;
		if (l != r) {
			int mid = tree[index].mid();
			build(l, mid, LL(index));
			build(mid + 1, r, RR(index));

		}
	}
	void update(int pos, int index) {
		tree[index].sum++;
		if (tree[index].left == tree[index].right)return;
		else {
			int mid = tree[index].mid();
			if (pos <= mid)update(pos, LL(index));
			else update(pos, RR(index));
		}
	}
	int query(int start, int end, int index) {
		int lft = tree[index].left;
		int rht = tree[index].right;
		if (start <= lft && rht <= end)return tree[index].sum;
		int mid = tree[index].mid(), sm = 0;
		if (start <= mid)sm += query(start, end, LL(index));
		if (end > mid)sm += query(start, end, RR(index));
		return sm;
	}
}seq;
int main() {
	while (scanf("%d", &n) == 1 && n) {
		for (int i = 0; i < n; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			cow[i] = Cow(a, b, i);
		}
		sort(cow, cow + n);
		
		seq.build(0, N, 1);
		for (int i = 0; i < n; i++) {
			if (i != 0 && cow[i].s == cow[i - 1].s&&cow[i].e == cow[i - 1].e) {
				result[cow[i].id] = result[cow[i - 1].id];
			}
			else {
				result[cow[i].id] = seq.query(cow[i].e,N, 1);

			}
		
			seq.update(cow[i].e, 1);
		}
		for (int i = 0; i < n; i++)printf("%d%c", result[i], i == n - 1 ? '\n' : ' ');
	}
	return 0;
}