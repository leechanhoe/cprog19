#include <stdio.h>

int main(void)
{
	int i, germ = 10;
	
	for (i = 0;i < 7;i++)
		germ *= 4;
	
	printf("7시간 후 세균의 수:%d", germ);
	
	return 0;
}
