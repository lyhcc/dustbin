/*
链接：https://www.nowcoder.com/acm/contest/201/B
来源：牛客网

题目描述
Mikasa正在使用Vertical Maneuvering Equipment穿过一个建筑群。Vertical Maneuvering Equipment的动力源是气体（gas)。平面上有这(n+1) x (m+1)个建筑，她现在位于(0,0)，且储气罐（gas canister）中没有气体。

在位置(x,y)上的建筑，每单位气体需要用px,y单位时间补充，Mikasa可以补充任意非负实数单位的气体。每单位气体正好可以让Mikasa移动1单位距离。两点之间的距离为欧几里得距离。另外，Mikasa只能沿与坐标轴平行或与坐标轴夹角的方向走。

由于Mikasa的技术非常精湛，可以认为她使用Vertical Maneuvering Equipment移动时不需要消耗时间。如果储气罐容量为C，Mikasa想到达(n,m)最少需要花费多少时间？
输入描述:

第一行三个整数n,m,C(0 ≤ n,m ≤ 20,1 ≤ C ≤1000)。
接下来(n+1)行，每行(m+1)个整数，其中第i行第j个数表示pi,j(0≤ p ≤1000000)。

输出描述:

一行一个实数表示最短时间，绝对误差或相对误差与正确答案不超过10-6即被认为正确。

输入
2 2 6
876322 702453 233424
215282 486678 123806
417986 759560 973610

输出
1396058.7241348
*/
#include<cstdio>
#include<iostream>
using namespace std;

const int maxn = 20 + 5;
const int maxm = 20 + 5;

int p[maxn][maxm];
int main() {
	int n, m, C;
	for(int i=0;i<n+1;i++)
		for (int j = 0; j < m + 1; j++) {
			scanf("%d", &p[i][j]);
		}

	return 0;
}