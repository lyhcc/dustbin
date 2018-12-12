/*
链接：https://www.nowcoder.com/acm/contest/201/C
来源：牛客网

题目描述
算术是为数不多的会让Kuon感到棘手的事情。通常她会找Haku帮忙，但是Haku已经被她派去买东西了。于是她向你寻求帮助。
给出一个关于变量x,y的不定方程ax+by=c，显然这个方程可能有多个整数解。Kuon想知道如果有解，
使得p2*x2+p1*x+q2*y2+q1*y最小的一组整数解是什么。为了方便，你只需要输出p2*x2+p1*x+q2*y2+q1*y的最小值。
输入描述:

第一行三个空格隔开的整数a,b,c(0 ≤ a,b,c≤ 105)。
第二行两个空格隔开的整数p1,p2(1 ≤ p1,p2 ≤ 105)。
第三行两个空格隔开的整数q1,q2(1 ≤ q1,q2 ≤ 105)。

输出描述:

如果方程无整数解，输出“Kuon”。
如果有整数解，输出p2*x2+p1*x+q2*y2+q1*y的最小值。

示例1
输入

2 2 1
1 1
1 1

输出


Kuon

示例2
输入


1 2 3
1 1
1 1

输出


4
*/
#include<cstdio>
#include<cstdlib>
#include<math.h>
#include<algorithm>
using namespace std;
typedef long long LL;
int main() {
	LL a, b, c, p1, p2, q1, q2;
	scanf("%lld %lld %lld %lld %lld %lld %lld", &a, &b, &c, &p1, &p2, &q1, &q2);
	LL ans, x, y;
	ans = 1e18 + 5;
	if (a && !(c%a) && !b) {
		x = c / a;
		ans = p2 * x*x + p1 * x;
	}
	else if (b && !a && !(c%b)){
		y = b / a;
		ans = q2 * y*y + q1 * y;
	}
	else if(a&&b){
		for (LL i = -100000; i <= 200000; i++) {
			y = (c - a * i);
			if (y%b == 0) {
				y = y / b;
				ans = min(ans, p2*i*i + p1 * i + q2 * y*y + q1 * y);

			}
		}
	}
	if (ans == 1e18 + 5) {
		printf("Kuon\n");
	}
	else printf("%lld", ans);
	return 0;
}