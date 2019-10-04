#include <stdio.h>

int get_sum(int a, int b)
{
	return (a + b);
}

int get_diff(int a, int b)
{
	int result;
	if (a > b)
		result = a - b;
	else
		result = b - a;
	return result;
}

double get_div(int a, int b)
{
	double result;
	result = (double)a / (double)b;
	return result;
}

int get_mul(int a, int b)
{
	return (a * b);
}

int main()
{
	int a, b;
	printf("Type two integers:");
	scanf("%d %d", &a, &b);

	printf("sum = %d\n", get_sum(a, b));
	printf("diff = %d\n", get_diff(a, b));
	printf("mul = %d\n", get_mul(a, b));
	printf("div = %f\n", get_div(a, b));

	return 0;
}
