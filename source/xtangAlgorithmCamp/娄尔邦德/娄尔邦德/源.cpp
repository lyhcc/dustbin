#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> getAnswer(int n, vector<int>a, int Q, vector<int>query)
{
	vector<int>ans;
	ans.clear();
	sort(a.begin(), a.end());
	for (int i = 0; i < Q; ++i)
	{
		int key = query[i];
		int l = 0, r = n-1,mid;
		//cout << n;
		int flag = 0;
		while (l <= r)
		{
			if (a[n - 1] < key) { break; }
			 mid = (l + r)>>1;
			 if (key == a[mid]) {
				 flag = 1; break;
			 }
			if (key > a[mid])
				l = mid+1;
			else
				r = mid-1;
		}
		 int pos =flag?mid:(r+1);
		if (pos >n-1||pos<0)
			ans.push_back(-1);
		else
			ans.push_back(a[pos]);
	}
	return ans;
}
int main() {
	int n, Q, tmp;
	vector<int> a, query;
	a.clear();
	query.clear();
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &tmp);
		a.push_back(tmp);
	}
	scanf("%d", &Q);
	for (int i = 0; i < Q; ++i) {
		scanf("%d", &tmp);
		query.push_back(tmp);
	}
	vector<int> ans = getAnswer(n, a, Q, query);
	for (int i = 0; i < Q; ++i)
		printf("%d\n", ans[i]);
	return 0;
}
