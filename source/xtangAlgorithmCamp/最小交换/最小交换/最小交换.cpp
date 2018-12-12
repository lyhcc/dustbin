#include<iostream>
#include<vector>
using namespace std;
vector<int>seq, seqTemp;
long long cnt;
void mergesort(int l, int r)
{
	if (l == r)
		return;
	int mid = (l + r) >> 1;
	mergesort(l, mid);
	mergesort(mid + 1, r);
	int p = l, q = mid+1;
	int i = l;
	while(p<=mid&&q<=r)
	{
		if (seq[p] <seq[q]) {
			seqTemp[i++] = seq[p++];
		}
		else {
			seqTemp[i++] = seq[q++];
			cnt += mid+1-p;
		
		}
	}
	while (p <= mid)seqTemp[i++] = seq[p++];
	while (q <= r)seqTemp[i++] = seq[q++];
	for (int i = l; i <= r; i++) {
		seq[i] = seqTemp[i];
	}
}
long long getAnswer(int n, vector<int>a)
{
	seq = a;
	seqTemp.resize(n);
	cnt = 0;
	mergesort(0, (n - 1));
	return cnt;
}
int main() {
	int n, tmp;
	vector<int> a;
	a.clear();
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &tmp);
		a.push_back(tmp);
	}
	long long ans = getAnswer(n, a);
	cout << ans << '\n';
	return 0;
}
