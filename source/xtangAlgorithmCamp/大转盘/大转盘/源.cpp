#include<iostream>
#include<vector>
#include<string>
#include<cstdio>
#include<string.h>
using namespace std;
int allone;
vector<bool>vis[2];
string ans;
int towpow(int x) {
	return 1 << x;
}
void dfs(int u)
{
	int v;
	for (int i = 0; i<2;i++)
	{
		if (!vis[i][u]) {//
			v = ((u << 1) | i)&allone;
			vis[i][u] = 1;
			dfs(v);
			string sh = (i==0? "0" : "1");
			ans = ans +sh ;
		}
		
		//cout << "HJK" << endl;
	}

}
string getAnswer(int n)
{
	allone = towpow(n - 1) - 1;
	ans = "";
	for (int i = 0; i < 2; i++)
	{
		vis[i].resize(towpow(n - 1), 0);
	}
	dfs(0);
	return ans;
}
int main() {
	int n;
	scanf("%d", &n);
	cout << getAnswer(n) << endl;
	return 0;
}
