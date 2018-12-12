#include<iostream>
#include<stack>
#include<vector>
using namespace std;
vector<int>answer;
void outputstack(stack<int>S)
{
	while (!S.empty()) {
		cout << S.top()<<endl;
		S.pop();
	}
}
stack<int> insertionsort(stack<int>R) {
	stack<int>S;
	int t;
	t = R.top();
	R.pop();
	if (R.empty()) { S.push(t); return S; }
	while (!R.empty()) {
		if (S.empty() || S.top() >= t)
		{
			S.push(t);  t = R.top();R.pop();
		}
		else {
			R.push(S.top()); S.pop();
		}
	}
	
	return S;
}

int main()
{
	stack<int>R; 
	stack<int>S;
	int n, e;
	cin >> n;
	R.push(0);
	while (n--)
	{
		cin >> e;
		R.push(e);
	}
	S=insertionsort(R);
	outputstack(S);
	return 0;
}