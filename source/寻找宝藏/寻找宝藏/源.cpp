#include<stdio.h>
#include<windows.h>
#include<math.h>
#define eps 1e-6
int n;
int x, y;
void findxy(int a)
{
	int r = n, c = n;
	int p = 0;
	while (p <= n * n)
	{
		if (p + c >= a) { x = x + a - p; return; }
		else { x = x + c; p = p + c; r--; }
		if (p + r >= a) { y = y + a - p; return; }
		else { y = y + r; p = p + r; c--; }
		if (p + c >= a) { x = x - a + p; return; }
		else { x -= c; p += c; r--; }
		if (p + r >= a) { y = y - a + p;  return; }
		else { y = y - r; p += r; c--; }
	}
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		int ax, ay, bx, by, a, b;
		scanf("%d %d", &a, &b);
		x = 0; y = 1;
		findxy(a);
		ax = x; ay = y;
		x = 0; y = 1;
		findxy(b);
		bx = x; by = y;
		//printf("ax=%d ay=%d bx=%d by=%d\n", ax, ay, bx, by);
		double ans = sqrt((ax - bx)*(ax - bx) + (ay - by)*(ay - by));
		printf("%.3lf\n", ans);
	}
	system("pause");
	return 0;

}