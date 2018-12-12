#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;
int main()
{
	int n,op;
	string ss;
	cin >> n;
	vector<string>a;
	stack<string>s;
	while (n--)
	{
		cin >> op;
		if (op == 1) {
			cin >> ss;
			s.push(ss);
			a.push_back(ss);
		}
		else if (op == 2 && !s.empty())
		{
			cout << s.top()<<endl;
			s.pop();
			a.pop_back();
		}
		else if (op == 3)
		{
			int y;
			cin >> y;
			cout << a[y-1] << endl;
		}
		
	}
	return 0;
}