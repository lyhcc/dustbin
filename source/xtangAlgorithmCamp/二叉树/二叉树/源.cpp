#include<iostream>
using namespace std;
typedef struct Tree {
	int data;
	Tree*lchild;
	Tree*rchild;
}TNode,*TList;
int cnt;
int n;int r[100005];
void InsertBST(TList &DT, TNode *p)
{
	if (DT == NULL)
		DT = p;
	else if ((DT->data) > (p->data))
		InsertBST(DT->lchild, p);
	else
		InsertBST(DT->rchild, p);
}
void CreateBST(TList &DT)
{
	
	cin >> n;
	int i, j;
	
	TNode *s;
	DT = NULL;
	for (j = 0; j<n; j++)
		cin >> r[j];
	for (i = 0; i<n; i++)
	{
		s = new TNode;
		s->data = r[i];
		s->lchild = NULL;
		s->rchild = NULL;
		InsertBST(DT, s);
	}
}
void preOrder(TList DT)
{
	if (DT) {
		cout<< DT->data <<" "; 
		preOrder(DT->lchild);
		preOrder(DT->rchild);
	}
}
void postOrder(TList DT)
{
	if (DT) {
	
		postOrder(DT->lchild);
		postOrder(DT->rchild);
		cout << DT->data << " ";
	}
}

int main()
{
	TList L;
	CreateBST(L);
	preOrder(L);
	cout << endl;
	postOrder(L);
	return 0;
}