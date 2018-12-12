/*
���ӣ�https://www.nowcoder.com/acm/contest/201/C
��Դ��ţ����

��Ŀ����
������Ϊ������Ļ���Kuon�е����ֵ����顣ͨ��������Haku��æ������Haku�Ѿ�������ȥ�����ˡ�����������Ѱ�������
����һ�����ڱ���x,y�Ĳ�������ax+by=c����Ȼ������̿����ж�������⡣Kuon��֪������н⣬
ʹ��p2*x2+p1*x+q2*y2+q1*y��С��һ����������ʲô��Ϊ�˷��㣬��ֻ��Ҫ���p2*x2+p1*x+q2*y2+q1*y����Сֵ��
��������:

��һ�������ո����������a,b,c(0 �� a,b,c�� 105)��
�ڶ��������ո����������p1,p2(1 �� p1,p2 �� 105)��
�����������ո����������q1,q2(1 �� q1,q2 �� 105)��

�������:

��������������⣬�����Kuon����
����������⣬���p2*x2+p1*x+q2*y2+q1*y����Сֵ��

ʾ��1
����

2 2 1
1 1
1 1

���


Kuon

ʾ��2
����


1 2 3
1 1
1 1

���


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