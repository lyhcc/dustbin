#include<stdio.h>
#include<windows.h>
#include<vector>
#include<string>
#include<map>
#include<iostream>
using namespace std;
vector<string>s[10000];
map<string, int>cnt;
int main()
{
	int n, m;
	
	while (scanf("%d %d", &n, &m) == 2 && n&&m)
	{
		string c;
		int i, j;
		getchar();
		for (i = 0; i<n; i++)
			for (j = 0; j < m; j++)
			{
				getline(cin, c);
				//cout << c << endl;
				s[i].push_back(c);
				cnt[c] = i ;
			}
		int r1, r2, c1, c2, ok = 1;
		for (i = 0; i < m - 1; i++) {
			for (j = 0; j < n; j++)
			{
				if (cnt[s[j][i]] != j) {
					r1 = j; r2 = cnt[s[j][i]]; c1 = i;
					for (int k = i + 1; k < m; k++)
						if (s[r1][k] == s[r2][k])
						{
							c2 = k;
							printf("r1=%d r2=%d c1=%d c2=%d\n", r1 + 1, r2 + 1, c1 + 1, c2 + 1);
							ok = 0; break;
						}
				}
				if (ok == 0)break;
			}
			if (ok == 0)break;
		}
	}
	return 0;
}