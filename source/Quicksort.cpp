#include<iostream>
#include<vector>
using namespace std;
vector<int>seq, seqTemp;
void quicksort(int l, int r) {
	if (l >= r)return;
	int i = l, j = r;
	int privot = seq[(l+r)/2];
	while (i <= j) {
		//10 10 1 3 5 9 7 6 8 2 4
		while (seq[i] < privot)i++;
		while (seq[j] >privot)j--; 
		//while (i < j&&privot <= seq[j])j--;
		//while (i < j&&seq[i] <= privot)i++; 
		if (i<=j)swap(seq[i++], seq[j--]);
		//cout << i << ends << j << endl;
	}
	quicksort(l, j);
	quicksort(i, r);

}
int main() {

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int  a; cin >> a;
		seq.push_back(a);
	}
	quicksort(0, n - 1);
	for (int i = 0; i < n; i++)
		cout << seq[i] << endl;
	return 0;
}