/*
链接：https://www.nowcoder.com/acm/contest/201/L
来源：牛客网

题目描述
Eagle Jump公司正在开发一款新的游戏。Hifumi Takimoto作为其中的员工，获得了提前试玩的机会。现在她正在试图通过一个迷宫。
这个迷宫有一些特点。为了方便描述，我们对这个迷宫建立平面直角坐标系。迷宫中有两条平行直线 L1:Ax+By+C1=0, L2:Ax+By+C2=0，还有 n 个圆 。角色在直线上、圆上、园内行走不消耗体力。在其他位置上由S点走到T点消耗的体力为S和T的欧几里得距离。
Hifumi Takimoto想从 L1 出发，走到 L2 。请计算最少需要多少体力。
输入描述:

第一行五个正整数 n,A,B,C1,C2 (1≤ n ≤ 1000, -10000 ≤ A,B,C1,C2 ≤ 10000)，其中 A,B 不同时为 0。
接下来 n 行每行三个整数 x,y,r(-10000 ≤ x,y ≤ 10000, 1≤ r ≤ 10000) 表示一个圆心为 (x,y)，半径为 r 的圆。

输出描述:

仅一行一个实数表示答案。与正确结果的绝对误差或者相对误差不超过 10-4 即算正确。

示例1
输入

2 0 1 0 -4
0 1 1
1 3 1

输出

0.236068
*/
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
const int maxn = 1000 + 5;
const int eps = 1e-6;
const double MAX = 1e9;
struct circle {
	double x, y, dis1, dis2, r;
}a[maxn];
int n; double A, B, C1, C2, dp[maxn];
bool cmp(circle a, circle b) {
	return a.dis1 < b.dis1;
}
int main() {
	while (scanf("%d%lf%lf%lf%lf", &n, &A, &B, &C1, &C2) == 5) {
		for (int i = 0; i < n; i++) {
			cin >> a[i].x >> a[i].y >> a[i].r;
			a[i].dis1 = fabs(A*a[i].x + B * a[i].y + C1) / sqrt(A*A + B * B);
			a[i].dis2 = fabs(A*a[i].x + B * a[i].y + C2) / sqrt(A*A + B * B);
		}
		sort(a, a + n, cmp);
		double ans =fabs(C1-C2)/sqrt(A*A+B*B);
		for (int i = 0; i < n; i++) {
			dp[i] = max(0.0, a[i].dis1 - a[i].r);
			for (int j = 0; j < i; j++) {
				dp[i] = min(dp[i], dp[j] + max(0.0, sqrt((a[i].x - a[j].x)*(a[i].x - a[j].x) 
					+ (a[i].y - a[j].y)*(a[i].y - a[j].y))- a[i].r - a[j].r));

			}
			ans = min(ans, dp[i] + max(0.0, a[i].dis2 - a[i].r));
		}
		printf("%.6lf\n", ans);
	}
	return 0;
}