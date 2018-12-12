#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
int main()
{
	time_t Time;
	struct tm*t;
	Time = time(NULL);
	t = localtime(&Time);
	printf("%s\n", t);
	printf("%s\n", asctime(t));
	system("pause");
	return 0;
}