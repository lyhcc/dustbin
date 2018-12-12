#include<iostream>
#include<string.h>
using namespace std;
int ans[1000+5][1000+5];
int main()
{
	int n;
	cin >> n;
	int i, j;
	int t = 1;

		for (i = 0; i < n; i++)
			for (j = 0; j < n - 1; j++)
				ans[i][j] = t++;
		for (i = 0; i < n; i++)
			ans[i][n - 1] = t++;
	
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << ans[i][j];
			if (j < n - 1)cout << ends;
		
		}
		cout << endl;
	}
	return 0;
}