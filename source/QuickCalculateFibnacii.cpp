#include<iostream>
using namespace std;
int main() {

	long long int A[2][2] = { 1,2,2,3}, A2[2][2] = {1,2,2,3}, A3[][2] = {0,1,1,1};
	int cnt = 0;
	int n;
	cout << "请输入符合2+3k的数，k为大于0的整数" << endl;
	cout << "n=" ;
	cin >> n;
	if(n>=1)
		cout << "fib[" << cnt++ << "]" << "=" << A3[0][0] << endl;
	if(n>=2)
		cout << "fib[" << cnt++ << "]" << "=" << A3[0][1] << endl;
	if(n>=3)
		cout << "fib[" << cnt++ << "]" << "=" << A3[1][1] << endl;
	n -= 2;
	while (n>=3) {
		long long int t1, t2, t3, t4;
		t1 = A2[0][0]; t2 = A2[0][1]; t3 = A2[1][0]; t4 = A2[1][1];
		A2[0][0] = t1 * A[0][0] + t2 * A[1][0];
		A2[0][1] = t1 * A[0][1] + t2 * A[1][1];
		A2[1][0] = t3 * A[0][0] + t4 * A[1][0];
		A2[1][1] = t3 * A[0][1] + t4 * A[1][1];
		cout << "fib[" << cnt++ << "]" << "=" << A2[0][0] << endl;
		cout << "fib[" << cnt++ << "]" << "=" << A2[0][1] << endl;
		cout << "fib[" << cnt++ << "]" << "=" << A2[1][1] << endl;
		n -= 3;
	}
	return 0;
}