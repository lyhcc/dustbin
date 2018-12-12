#include<iostream>
#include<vector>
using namespace std;
int ans, allone;
void dfs(int pos, int left, int right)
{
	if (pos==allone) {
		ans++;
		return;
	}
	for (int t = allone & (~(pos | left | right)); t;)
	{
		int p = t & -t;
		dfs(pos | p, (left | p) << 1, (right|p)>>1);
		
		t ^= p;
	}
}
int getAnswer(int n) {
	ans = 0; 
	allone = (1 << n) - 1;
	dfs(0, 0, 0);
	return ans;
}
int main() {
	int n;
	cin >> n;
	cout << getAnswer(n) << endl;
	return 0;
}
