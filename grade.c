#include <stdio.h>

int main()
{
	double student, a, b, c;

	printf("Number of students:");
	scanf("%lf", &student);
	
	a = student * 0.2;
	b = student * 0.6;
	c = student * 0.2;

	printf("A: %lf", a);
	printf("B: %lf", b);
	printf("C: %lf", c);

	return 0;
}
