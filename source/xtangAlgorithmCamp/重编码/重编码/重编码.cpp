#include <iostream>
#include<vector>
#include<queue>
#include<functional>
#include<cstdio>
using namespace std;
typedef long long ll;
priority_queue<ll, vector<ll>, greater<ll> >pq;
long long getAnswer(int n, vector<ll>w)
{

	for (int i = 0; i < n; i++)
		pq.push(w[i]);
	ll sum = 0;
	while (pq.size() > 1)
	{
		ll newEle = 0;
			ll a = pq.top(); pq.pop();
			ll b = pq.top(); pq.pop();
			newEle = a + b;
			sum += newEle;
			pq.push(newEle);
	}
	return sum;
}
int main() {
	int n;
	scanf("%d", &n);
	vector<long long> w;
	for (int i = 0; i < n; ++i) {
		long long x;
		scanf("%lld", &x);
		w.push_back(x);
	}
	printf("%lld\n", getAnswer(n, w));
	return 0;
}