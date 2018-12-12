#include<iostream>
#include<vector>
using namespace std;
vector<int>seq, seqTemp;
void mergesort(int l, int r) {
	if (l >= r)return;
	int mid = (l + r) >> 1;
	mergesort(l, mid);
	mergesort(mid + 1, r);
	int p, q;
	p = l; q = mid + 1;
	int i=l;
	while (p <= mid && q <= r) {
		if (seq[p] < seq[q]) {
			seqTemp[i++] = seq[p++];
		}
		else {
			seqTemp[i++] = seq[q++];
		}
	}
	while(p<=mid)seqTemp[i++] = seq[p++];
	while(q<=r)seqTemp[i++] = seq[q++];
	for ( i =l; i <= r;  i++)
		seq[i] = seqTemp[i];
}
int main()
{
	int n;
	cin >> n;
	seq.clear();
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		seq.push_back(a);
	}
	seqTemp.resize(n);
	mergesort(0,n-1);
	for (int i = 0; i < n; i++)
		cout << seq[i] << endl;
	return 0;
}