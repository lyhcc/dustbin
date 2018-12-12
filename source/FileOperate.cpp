#include<io.h>
#include<vector>
#include<string>
#include<string.h>
#include<cstdlib>
#include<iostream>
#include<cstdio>
using namespace std;

void getfiles(char filename[]) {

}
int main() {
	char filename[10000];
	cin >> filename;
	char *p;
	p = strtok(filename, "/");
	while (p)
	{
		cout << p << endl;
		p = strtok(NULL, "/");
	}
	getfiles(filename);
	
	return 0;
}