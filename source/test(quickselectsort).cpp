#include<iostream>
#include<vector>
#include<windows.h>
using namespace std;
void output(vector<int>A)
{
	for (int i = 0; i < A.size(); i++)cout << A[i] << ends;
	cout << endl;
}

void quickSelect(vector<int>A,int k)
{
	for (int lo = 0, hi = A.size() - 1; lo < hi;)
	{
		int i = lo, j = hi;
		int privot = A[lo];
		while (i < j)
		{
			while (i < j&&privot <= A[j])j--; A[i] = A[j]; 
			while (i < j&&A[i] <= privot)i++; A[j] = A[i];
		}
		A[i] = privot; 
		if (k <= i)hi = i - 1;
		if (i <= k)lo = i + 1;
	}
}// 10 10 1 3 5 9 7 6 8 2 4
int main()
{
	vector<int>A;
	for (int i = 0; i < 10; i++)
	{
		int a;
		cin >> a;
		A.push_back(a);
	} output(A); system("pause");
	quickSelect(A, 3);
	output(A); system("pause");
	return 0;

}