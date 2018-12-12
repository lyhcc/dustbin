#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;
const int maxn = 260;
struct node {
	bool have_value;
	int v;
	struct node *left,*right;
	node():have_value(false),left(NULL),right(NULL){}
};
char s[maxn];
bool failed;
node*root;
node* newnode() { return new node(); }
void addnode(int v,char *s)
{
	int n = strlen(s);
	node*u=root;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'L') {
			if (u->left == NULL)  u->left = newnode();
			u = u->left;
		}
		else if (s[i] == 'R') {
			if (u->right == NULL)u->right = newnode();
			u = u->right;
		}
	}
	if (u->have_value)failed = true;
	u->v = v;
	u->have_value = true;

}
bool read_input()
{
	failed = false;
	root = newnode();
	for (;;)
	{
		if (scanf("%s", s) != 1)return false;
		if (strcmp(s, "()") == 0)break;
		int v;
		sscanf(&s[1], "%d", &v);
		addnode(v, strchr(s, ',') + 1);
	}
	return true;
}
bool bfs(vector<int>&ans)
{
	queue<node*>q;
	ans.clear();
	q.push(root);
	while (!q.empty())
	{
		node*u = q.front(); q.pop();
		if (!u->have_value)return false;
		ans.push_back(u->v);
		//printf("%d\n", u->v);
		if (u->left!=NULL)q.push(u->left);
		if (u->right!=NULL)q.push(u->right);
	}
	return true;
}
int main()
{
	vector<int>ans;
	while (read_input())
	{
		if (failed==true||bfs(ans)==false) { printf("not complete\n"); continue; }
		else
		{
			printf("%d", ans[0]);
			for (int i = 1; i < ans.size(); i++)
				printf(" %d", ans[i]);
			printf("\n");
		}
	}
	return 0;
}