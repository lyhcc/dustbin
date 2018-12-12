#include<iostream>
#include<set>
#include<functional>
using namespace std;
int main()
{
	int T;
	cin >> T;
	multiset<int,greater<int> >S;
	int op,x;
	multiset<int, greater<int> >::iterator it;
	while (T--)
	{
		cin >> op;
		if (op != 4)cin >> x;
		switch (op)
		{
		case 1:S.insert(x); break;
		case 2:for (multiset<int, greater<int> >::iterator ite = S.begin(); ite != S.end(); ite++)
			{
			if (*ite == x) { it = ite; S.erase(ite); break; }
			}
			break;
		case 3:cout << S.count(x) << endl; break;
		case 4:it=--S.end(); cout<< *it << endl; break;
		case 5:
			if ((it = S.upper_bound(x)) == S.end())cout << "None" << endl;
			else cout << *it << endl;
			break;
		}
	}
	return 0;
}