#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<iostream>
#include<functional>
using namespace std;
int main()
{
	int n, a;
	scanf("%d", &n);
	priority_queue<int, vector<int>, greater<int> >q;
	vector<int>A;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a); 
		//cin >> a;
		A.push_back(a);
		q.push(A[i]);
		
	}
	//sort(A.begin(), A.end());
	
	printf("%d", q.top()); q.pop();
	for (int i = 1; i < n; i++)
	{
		printf(" %d", q.top()); q.pop();
	}
	printf("\n");
	return 0;
}