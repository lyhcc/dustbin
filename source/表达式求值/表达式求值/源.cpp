#include<stdio.h>
#include<iostream>
using namespace std;
typedef struct numstack {
	int num;
	struct numstack *next;
}*LNumstack,Numstack;
typedef struct charstack {
	int op;
	struct charstack *next;
}*Lcharstack, charstack;
char op[8][8] = { ">><<<>>",
">><<<>>",
">>>><>>",
">>>><>>",
"<<<<<=E",
">>>>E>>",
"<<<<<E=",
};
char gettop(Lcharstack A)
{
	return A->op;
}
int gettop(LNumstack A)
{
	return A->num;
}
void Push(Lcharstack &S,char cc)
{
	charstack *p;
	p = new charstack;
	p->op = cc;
	p->next = S;
	S = p;
}
void Push(LNumstack &L, char cc)
{
	numstack *p;
	p = new numstack;
	p->num = cc-'0';
	p->next = L;
	L = p;
}
char Precede(char c1, char c2)
{
	int i, j;
	switch (c1)
	{
		case '+':i = 0; break;
		case '-':i = 1; break;
		case '*':i = 2; break;
		case '/':i = 3; break;
		case '(':i = 4; break;
		case ')':i = 5; break;
		case '#':i = 6; break;
	}
	switch (c2)
	{
	case '+':j = 0; break;
	case '-':j = 1; break;
	case '*':j = 2; break;
	case '/':j = 3; break;
	case '(':j = 4; break;
	case ')':j = 5; break;
	case '#':j = 6; break;
	}
	return op[i][j];
	
}
int Calculate(int a, char c, int b)
{
	switch (c)
	{
	case '+':return a + b;
	case '-':return a - b;
	case '*':return a * b;
	case '/':return a / b;
	}
}
void Pop(Lcharstack &S, char &c)
{
	Lcharstack q;
	q = S;
	c = S->op;
	S = S->next;
	delete q;
}
void Pop(LNumstack &L, int &c)
{
	LNumstack q;
	q = L;
	c = L->num;
	L = L->next;
	delete q;
}
int main()
{
	LNumstack NUM=NULL;
	Lcharstack operate=NULL;
	char ch;
	Push(operate, '#');
	cin >> ch;
	char theta;
	int a, b;
	while (gettop(operate) != '#' || ch != '#')
	{
		if (ch >= '0'&&ch <= '9') { Push(NUM, ch); cin >> ch; }
		else {
			switch (Precede(gettop(operate),ch))
			{
			case '<':Push(operate, ch); break;
			case '>':Pop(NUM, a); Pop(NUM, b); Pop(operate, theta);
				Push(NUM, Calculate(a, theta, b)); break;
			case '=':char ss = gettop(operate); Pop(operate,ss); cin >> ch; break;

			}
			
		}
	}
	cout << gettop(NUM) << endl;
	return 0;
}