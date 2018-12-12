#include<iostream>  
#include<algorithm>  
#include<cstdio>
#include <climits>
using namespace std;
long long ans;
long long ansnum;//Լ������  
long long n;
long long prime[15] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47 };
//ȡ20������  
//2^a1 * 3^a2 * 5^a3 * 7^a4  
void dfs(long long m, long long pi, long long m_num, long long pre)//mΪ��ǰ����,piΪ��ǰö�ٵ�����,m_numΪm��Լ���ĸ���,preΪ֮ǰ�������ĸ���  
{
	if (m_num>ansnum)//�������ս��  
	{
		ans = m;
		ansnum = m_num;
	}
	if (m_num == ansnum && ans>m)	{
		ans = m;
	}
	for (long long l = 1; l <= pre;)
	{
		m *= prime[pi];
		if (m>n)
		{
			break;
		}
		l++; 
		dfs(m, pi + 1, m_num*l, l - 1); 
	}
}
int main()
{
	long long total;
	cin >> total;
	while (total--)
	{
		ans = 1;
		ansnum = 1;  
		scanf("%lld", &n);
		dfs(1, 0, 1, LONG_MAX);  
		printf("%lld\n",ansnum);
	}
	return 0;
}