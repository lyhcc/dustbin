/*
���ӣ�https://www.nowcoder.com/acm/contest/201/B
��Դ��ţ����

��Ŀ����
Mikasa����ʹ��Vertical Maneuvering Equipment����һ������Ⱥ��Vertical Maneuvering Equipment�Ķ���Դ�����壨gas)��ƽ��������(n+1) x (m+1)��������������λ��(0,0)���Ҵ����ޣ�gas canister����û�����塣

��λ��(x,y)�ϵĽ�����ÿ��λ������Ҫ��px,y��λʱ�䲹�䣬Mikasa���Բ�������Ǹ�ʵ����λ�����塣ÿ��λ�������ÿ�����Mikasa�ƶ�1��λ���롣����֮��ľ���Ϊŷ����þ��롣���⣬Mikasaֻ������������ƽ�л���������нǵķ����ߡ�

����Mikasa�ļ����ǳ���տ��������Ϊ��ʹ��Vertical Maneuvering Equipment�ƶ�ʱ����Ҫ����ʱ�䡣�������������ΪC��Mikasa�뵽��(n,m)������Ҫ���Ѷ���ʱ�䣿
��������:

��һ����������n,m,C(0 �� n,m �� 20,1 �� C ��1000)��
������(n+1)�У�ÿ��(m+1)�����������е�i�е�j������ʾpi,j(0�� p ��1000000)��

�������:

һ��һ��ʵ����ʾ���ʱ�䣬������������������ȷ�𰸲�����10-6������Ϊ��ȷ��

����
2 2 6
876322 702453 233424
215282 486678 123806
417986 759560 973610

���
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