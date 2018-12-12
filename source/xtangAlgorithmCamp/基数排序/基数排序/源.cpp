#include<iostream>
#include<cstdio>
#include<vector>
#include<string.h>
using namespace std;

typedef unsigned int u32;
const int N = 100000000;

u32 nextInt(u32 x) {
	x ^= x << 13;
	x ^= x >> 17;
	x ^= x << 5;
	return x;
}

void initData(u32* a, int n, int k, u32 seed) {
	for (int i = 0; i < n; ++i) {
		seed = nextInt(seed);
		a[i] = seed >> (32 - k);
	}
}

u32 hashArr(u32* a, int n) {
	u32 x = 998244353, ret = 0;
	for (int i = 0; i < n; ++i) {
		ret ^= (a[i] + x);
		x = nextInt(x);
	}
	return ret;
}


u32 a[N + 1];
u32 _a[N + 1];
const int m = 16;
const int B = 1 << m;
const int b = B - 1;
int sum[B + 1];
void sorting(int n, int k) {
	memset(sum, 0, sizeof(sum));
	for (int i = 0; i < n; i++)
		++sum[a[i] & b];
	for (int i = 1; i < B; i++)
		sum[i] += sum[i - 1];
	for (int i = n - 1; i >= 0; --i)
	{
		_a[--sum[a[i] & b]] = a[i];
		//sum[a[i]& b]--;
	}
	memset(sum, 0, sizeof(sum));
	for (int i = 0; i < n; i++)
		++sum[(_a[i]>>m)&b];
	for (int i = 1; i < B; i++)
		sum[i] += sum[i - 1];
	for (int i = n - 1; i >= 0; --i)
		a[--sum[(_a[i] >> m)&b]] = _a[i];
	/*		cout << "SDFHJ"<<endl;
			for (int i = 0; i < n; i++)cout << a[i] << endl;
			cout << "Íê±Ï"<<endl;
	*/
}

int main() {
	int n, k;
	u32 seed;
	scanf("%d%d%u", &n, &k, &seed);
	initData(a, n, k, seed);

	sorting(n, k);

	u32 ans = hashArr(a, n);
	printf("%u\n", ans);
	return 0;
}
