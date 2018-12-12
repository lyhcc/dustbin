/*
���ӣ�https://www.nowcoder.com/acm/contest/201/L
��Դ��ţ����

��Ŀ����
Eagle Jump��˾���ڿ���һ���µ���Ϸ��Hifumi Takimoto��Ϊ���е�Ա�����������ǰ����Ļ��ᡣ������������ͼͨ��һ���Թ���
����Թ���һЩ�ص㡣Ϊ�˷������������Ƕ�����Թ�����ƽ��ֱ������ϵ���Թ���������ƽ��ֱ�� L1:Ax+By+C1=0, L2:Ax+By+C2=0������ n ��Բ ����ɫ��ֱ���ϡ�Բ�ϡ�԰�����߲�����������������λ������S���ߵ�T�����ĵ�����ΪS��T��ŷ����þ��롣
Hifumi Takimoto��� L1 �������ߵ� L2 �������������Ҫ����������
��������:

��һ����������� n,A,B,C1,C2 (1�� n �� 1000, -10000 �� A,B,C1,C2 �� 10000)������ A,B ��ͬʱΪ 0��
������ n ��ÿ���������� x,y,r(-10000 �� x,y �� 10000, 1�� r �� 10000) ��ʾһ��Բ��Ϊ (x,y)���뾶Ϊ r ��Բ��

�������:

��һ��һ��ʵ����ʾ�𰸡�����ȷ����ľ������������������ 10-4 ������ȷ��

ʾ��1
����

2 0 1 0 -4
0 1 1
1 3 1

���

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