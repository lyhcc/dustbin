#include<stdio.h>
#include<windows.h>
#include<math.h>
int gcd(int m, int n)
{
	int r;
	m = abs(m);
	n = abs(n);
	while (n)
	{
		r = m%n;
		m = n; n = r;
	}
	return m;
}
int main()
{
	int n, a, b, c, d,p,q;
	char ch;
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d %d %d %d %c", &a,&b,&c,&d,&ch);
		switch (ch)
		{
		case '+':p = a*(b*d / gcd(b, d) / b) + c*(b*d / gcd(b, d) / d);
				q = b*d / gcd(b, d);
				break;
		case '-':p = a*(b*d / gcd(b, d) / b) - c*(b*d / gcd(b, d) / d);
				q = b*d / gcd(b, d);
				break;
		case '*':p = a*c;
			q = b*d;
			break;
		case '/':p = a*d;
			q = c*b;
		}
		if(p%q==0)
			printf("%d/%d%c%d/%d=%d\n", a, b, ch, c, d, p/q);
		else
			printf("%d/%d%c%d/%d=%d/%d\n", a, b, ch, c, d, p/gcd(p,q), q/gcd(p,q));
	}
	system("pause");
	return 0;
}