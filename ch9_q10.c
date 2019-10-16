#include <stdio.h>


int num = 0;
unsigned int mask = 1;
void Check(unsigned int x)
{
	if (x == 0)
		printf("1의 개수는 %d개", num);
	else 
	{
		if ((mask & x) == mask)
			num++;
		return Check(x >> 1);
	}
}

int main()
{
	unsigned int argument;
	printf("1의 개수를 셀 수를 입력하세요:");
	scanf("%u", &argument);
	Check(argument);
}
