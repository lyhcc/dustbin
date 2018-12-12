#include<iostream>
#include<queue>
#include<string>
#include<vector>
using  namespace std;
int main()
{
	vector<string>a;
	queue<string>q;
	int n;
	cin >> n;
	while (n--)
	{
		int op;
		cin >> op;
		if (op == 1) {
			string s;
			cin >> s;
			q.push(s);
			a.push_back(s);
		}
		else if (op == 2 && !q.empty())
		{
			cout << q.front() << endl;
			q.pop();
			a.erase(a.begin());
		}
		else if (op == 3)
		{
			int y;
			cin >> y;
			cout << a[y - 1]<<endl;
		}
	}
	return 0;
}