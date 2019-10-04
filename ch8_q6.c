#include <stdio.h>
#include <math.h>

double get_distance(double a, double b)
{
	double c;
	c = sqrt(pow(a, 2) - pow(b, 2));
	return b;
}

int main()
{	
	double a = 5, b = 3, c;
	c = get_distance(a, b);
	printf("나머지 변의 길이 : %f", c);
	return 0;
}
