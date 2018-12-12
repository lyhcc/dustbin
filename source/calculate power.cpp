#include<iostream>
using namespace std;
int main()
{

	long long int n, a;
	cin >> a>> n;
	long long int p = a,power=1;
	while (n > 0)
	{
		if (n & 1)power *= p;
		n >>= 1;
		p *= p;
	}
	cout << power << endl;
	return 0;
}