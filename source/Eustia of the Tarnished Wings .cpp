/*
链接：https://www.nowcoder.com/acm/contest/201/E
来源：牛客网

题目描述
Novus Aither是一个潜藏着多个势力的城市。每个势力都有一个唯一的领导人，每个领导人有一个属性值。如果两个势力的领导人的属性值分别为a,b，且|a-b| ≤ m，说明这两个领导人的思想有一定的相似之处，这两个势力可以合并，新的领导人可以指定为原来的两个领导人中的任意一个。新产生的势力可以依照相同的规则，继续与其他势力合并。问在所有可能的情况中，最少会剩下几个势力。
输入描述:

第一行两个空格隔开的整数n(1 ≤ n ≤ 106),m(0 ≤ m ≤ 109)。n代表当前势力的个数。m的含义如题目描述。
第二行n个空格隔开的整数di(0 ≤ di ≤ 109)，代表第i个势力的领导人的属性值。

输出描述:

输出一个数表示势力的最少数量。

示例1
输入

4 1
2 1 3 10

输出

2
*/
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 1e6 + 10;
vector<int>d;
int main() {
	d.clear();
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		d.push_back(x);
	}
	sort(d.begin(), d.end());
	int cnt = 1;
	for (int i = 0; i < n-1; i++) {
		if (d[i + 1] - d[i] > m)cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}