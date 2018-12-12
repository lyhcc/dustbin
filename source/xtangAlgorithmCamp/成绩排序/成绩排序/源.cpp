#include<iostream>
using namespace std;
const int maxn= 5000 + 5;
struct Student {
	int pos;
	int algorithm_score;
	int structure_score;
}stu[maxn];
int main()
{
	int n,a,b;
	cin >> n;
	int i;
	for (i = 0; i < n; i++)
	{
		cin >> a >> b;
		stu[i] = { i + 1,a,b };
	}
	int j;
	for (i = 0; i < n-1; i++) {
		int max = i;
		for (j = i+1; j < n; j++) {
			if (stu[i].algorithm_score + stu[i].structure_score < stu[j].algorithm_score + stu[i].structure_score)max = j;
			else if (stu[i].algorithm_score < stu[j].algorithm_score)max = j;
			else if (stu[i].structure_score < stu[j].structure_score)max = j;
		}
		if (max != i)
		{
			int t;
			t = stu[max].pos; stu[max].pos = stu[i].pos; stu[i].pos = t;
			t = stu[max].algorithm_score; stu[max].algorithm_score = stu[i].algorithm_score; stu[i].algorithm_score = t;
			t = stu[max].structure_score; stu[max].structure_score = stu[i].structure_score; stu[i].structure_score = t;
		}
	}
	int cnt = 0;
	for(i=0;i<n-1;i++)
		for (j = i + 1; j < n; j++)
		{
			if (stu[i].pos > stu[j].pos)cnt++;
		}
	for (i = 0; i < n; i++)
		cout << stu[i].pos << ends << stu[i].algorithm_score << ends << stu[i].structure_score << endl;
	cout << cnt << endl;
	return 0;
}