#include<iostream>
#include<stack>
using namespace std;
char op[7][7] = {
	'>','>','<','<','<','>','>',
	'>','>','<','<','<','>','>',
	'>','>','>','>','<','>','>',
	'>','>','>','>','<','>','>',
	'<','<','<','<','<','=','E',
	'>','>','>','>','E','>','>',
	'<','<','<','<','<','E','=',
};
stack<char>OPER;
stack<int>EXPT;
char Precede(char a, char b)
{
	int i, j;
	switch (a)
	{
	case '+':i = 0; break;
	case '-':i = 1; break;
	case '*':i = 2; break;
	case '/':i = 3; break;
	case '(':i = 4; break;
	case ')':i = 5; break;
	case '#': i= 6; break;
	}
	switch (b)
	{
	case '+':j = 0; break;
	case '-':j = 1; break;
	case '*':j = 2; break;
	case '/':j = 3; break;
	case '(':j= 4; break;
	case ')':j = 5; break;
	case '#': j = 6; break;
	}
	return op[i][j];
}
void InitEXPTree()
{
	OPER.push('#');
	char ch;
	cin >> ch;
	while (ch != '#' || OPER.top() != '#')
	{
		if (ch >= '0'&&ch <= '9') { EXPT.push(ch); cin >> ch; }
		else {
			char op1 = OPER.top();
			switch (Precede(op1, ch))
			{
			case '<':
				OPER.push(ch); cin >> ch;
				break;
			case '>':
				char theta = OPER.top(); OPER.pop();
				int a = EXPT.top(); EXPT.pop();
				int b = EXPT.top(); EXPT.pop();
				break;
			case '=':
				OPER.pop(); cin >> ch; break;
			}
		}
	}
}
int main()
{
	InitEXPTree();
	return 0;
}