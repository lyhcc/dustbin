#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<string.h>
#include<cmath>
using namespace std;

// ================= ����ʵ�ֿ�ʼ =================

typedef double lf;
typedef long long ll;

const int N = 300005;

// ���ڴ洢һ����άƽ���ϵĵ�
struct ip {
	int x, y;

	// ���캯��
	ip(int x = 0, int y = 0) : x(x), y(y) { }

	// �ȱȽ�x�ᣬ�ٱȽ�y��
	bool operator < (const ip &a) const {
		return x == a.x ? y < a.y : x < a.x;
	}
} a[N], b[N];

// ����x��ƽ��
ll sqr(const ll &x) {
	return x * x;
}

// �����a�͵�b�ľ���
lf dis(const ip &a, const ip &b) {
	return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

/* �������ﶨ������Ҫ��ȫ�ֱ��� */
lf ans;
void solve(int l, int r)
{
	if (r - l <= 0) {
		//ans = min(ans, dis(a[l], a[r]));
		return;
	}
	int mid = (l + r) >> 1;
	solve(l, mid);
	solve(mid + 1,r);
	int md = a[mid].x;
	int cnt = 0;
	for (int i = l, j = mid + 1; i <= mid || j <= r;) {
		for (; i <= mid && md - a[i].x > ans; ++i);
		for (; j <= r && a[j].x - md > ans; ++j);
		if (i <= mid && (j > r || a[i].y < a[j].y))b[cnt++] = a[i++];
		else b[cnt++] = a[j++];
	}
	for (int i = 0; i < cnt; ++i)
		for (int j = i + 1; j < cnt&&b[j].y - b[i].y <= ans; ++j)
			ans = min(ans, dis(b[i], b[j]));
	/*��y����й鲢����*/
	 cnt = 0;
	for (int i = l, j = mid + 1; i <= mid || j <= r;) {
		if (i <= mid && (j > r || a[i].y < a[j].y))b[cnt++] = a[i++];
		else b[cnt++] = a[j++];
	}
	//���ź���ĵ�Ż�a��
	memcpy(a + l, b, sizeof(ip)*cnt);
}
// ���������Եľ���
// n��n����
// X, Y���ֱ��ʾx�������y�����꣬�±��0��ʼ
// ����ֵ������ľ���
double getAnswer(int n, vector<int> X, vector<int> Y) {
	/* ���������������㷨 */
	for (int i = 0; i < n; i++)
		a[i + 1] = ip(X[i], Y[i]);
	ans = 1e100;
	sort(a + 1, a + 1 + n);
	solve(1, n);
	return ans;
}

// ================= ����ʵ�ֽ��� =================

int main() {
	int n;
	scanf("%d", &n);
	vector<int> X, Y;
	for (int i = 1; i <= n; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		X.push_back(x);
		Y.push_back(y);
	}
	printf("%.2f\n", getAnswer(n, X, Y));
	return 0;
}

