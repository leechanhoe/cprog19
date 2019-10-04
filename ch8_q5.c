#include <stdio.h>
#include <math.h>

double get_height(double a, double d)
{
	double b, radian;
	radian = 3.141592 * d / 180;
	b = a * sin(radian);
	return b;
}

int main()
{	
	double a = 1, b, d = 57;
	b = get_height(a, d);
	printf("b : %f", b);
	return 0;
}
