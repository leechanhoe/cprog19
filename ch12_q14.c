#include <stdio.h>
#include <stdlib.h>

int main()
{
	char s1[] = "100";
	char s2[] = "12.93";
	char buffer[100];
	int i;
	double d, result;

	i = atoi(s1);
	d = atof(s2);
	result = i + d;

	sprintf(buffer, "%f", result);
	printf("연산 결과는 %s입니다.\n", buffer);
}
