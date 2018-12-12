#include<cstdio>
#include<iostream>
using namespace std;
int getNum(int num1, int num2) {

	int sum = 0;
	for (int i = num1; i <= num2; i++) {
		int n=i, m;
		while (n > 0) {
			m = n % 10;
			n = n / 10;
			if (i == num2 && n == 0)
				cout << "=";
			else 
				cout << m << "+";
			sum += m;
		}
	}
	return sum;
}
int main() {

	int num1, num2;
	scanf("%d %d", &num1, &num2);
	printf("%d\n", getNum(num1, num2));
	return 0;
}