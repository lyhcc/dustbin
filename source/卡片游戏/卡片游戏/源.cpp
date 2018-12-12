#include<stdio.h>
#include<windows.h>
#include<queue>
using namespace std;

queue<int>q;
int main()
{
	int n,count=1;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)q.push(i + 1);
	while (count<=n)
	{
		printf("%d ", q.front());
		count++;
		q.pop();
		q.push(q.front());
		q.pop();
	}
	system("pause");
	return 0;
}