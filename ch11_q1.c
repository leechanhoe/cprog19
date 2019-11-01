#include <stdio.h>

void Swap(int * a, int * b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int a = 1, b = 2;

	Swap(&a, &b);
	printf("%d %d", a, b);
}
