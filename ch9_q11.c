#include <stdio.h>

int rabbit_num = 1;

int rabbit(int rabbit_num,int n)
{
	if (n = 1)
		return rabbit_num;
	else
		rabbit_num += rabbit(n-1);
}

int main()
{
	int a;
	a = rabbit(5);
	printf("%d", a);
	return 0;
}
