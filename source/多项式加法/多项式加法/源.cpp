#include<stdlib.h>
#include<stdio.h>
const int OK = 1;
typedef struct polynomial {
	int ecof;
	int exp;
	struct polynomial *next;
}LNode, *LinkList;
int Createlist(LinkList&L)
{
	L = new LNode; L->next = NULL;
	LNode *p, *p2, *q, *pre;
	int n;
	scanf("%d", &n);
	int i;
	for (i = 0; i<n; i++)
	{
		p = new LNode; p->next = NULL;
		scanf("%d %d", &p->ecof, &p->exp);
		//if(L->next=NULL)L->next=p;
		pre = L; q = L->next;
		while (q&&q->exp<p->exp)
		{
			pre = q; q = q->next;
		}
		pre->next = p; p->next = q;


	}
	return OK;
}
int traverselist(LinkList&L)
{
	LNode *p;
	if(L==NULL)printf("SDFGHJ\n");
	p = L->next;
	while (p != NULL)
	{
		printf("(%dx^%d)", p->ecof, p->exp);
		p = p->next;
	}
	printf("\n");
	return OK;
}
int AddPOLY(LinkList&p1, LinkList&p2)
{
	LNode*q, *p,*pa,*pb;
	//LinkList L = pa;
	//if (pa == NULL || pb == NULL)printf("SDFGH\n");
	p = p1; pa = p1->next; pb = p2->next;
	while (pa&&pb)
	{
		//traverselist(L);
		if (pa->exp == pb->exp)
		{
			pa->ecof = pa->ecof + pb->ecof;//printf("%d %d\n", pa->ecof, pb->ecof);
			if (pa->ecof != 0)
			{
				p->next = pa; p = pa; pa = pa->next;
				
				q = pb; pb = pb->next;
				delete q;
			}
			else {
				q = pa; pa = pa->next; delete q;
				q = pb; pb = pb->next; delete q;
			}
		}
		else if (pa->exp>pb->exp)
		{
			p->next = pb; p = pb; pb = pb->next;
		}
		else
		{
			p->next = pa; p = pa; pa = pa->next;
		}
	}
	p->next = pa ? pa : pb;
	delete pb;
	return OK;

}
int main()
{

	LinkList A, B;
	Createlist(A);
	traverselist(A);
	Createlist(B);
	traverselist(B);
	AddPOLY(A, B);
	traverselist(A);
	return 0;
}