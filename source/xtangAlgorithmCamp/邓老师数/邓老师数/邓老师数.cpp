#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
vector<bool>isPrime, isDeng;
vector<int>getAnswer(int n,int k)
{
	isPrime.resize(n + 1, 1);
	isDeng.resize(n + 1, 1);
	vector<int>ans;
	for (int i = 2; i <= n; i++)
	{
		if (isPrime[i])
			isDeng[i] = 0;
		if (k == 0 && isPrime[i])ans.push_back(i);
		if (k == 1&& isDeng[i])ans.push_back(i);
		for (int j = i * 2; j <= n; j+=i)
		{
			isPrime[j] = 0;
			if (!isPrime[i])isDeng[j] = 0;
		}
	}
	return ans;
}
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	vector<int> ans = getAnswer(n, k);
	for (vector<int>::iterator it = ans.begin(); it != ans.end(); ++it)
		printf("%d\n", *it);
	return 0;
}