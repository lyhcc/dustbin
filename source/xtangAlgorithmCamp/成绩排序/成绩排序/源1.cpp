#include<iostream>
using namespace std;
const int maxn= 5000 + 5;
struct Student {
	int pos;
	int algorithm_score;
	int structure_score;
	int sum;
}stu[maxn];
int main()
{
	int n,a,b;
	cin >> n;
	int i,j;
	for (i = 0; i < n; i++)
	{
		cin >> a >> b;
		stu[i] = { i + 1,a,b };
		stu[i].sum=a+b;
	}
	int cnt = 0;
	for(i=0;i<n;i++)
	for (i = 0; i < n; i++)
		cout << stu[i].pos <<ends<<stu[i].sum<< ends << stu[i].algorithm_score << ends << stu[i].structure_score << endl;
	cout << cnt;
	return 0;
}