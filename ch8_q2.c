#include <stdio.h>
#include <math.h>



unsigned int clear_bit(unsigned int n, unsigned int i)
{
	unsigned int mask = 1;
	return n & ~mask;
}

void print_bit(unsigned int n)
{
	for (int i = sizeof(n) * 8 - 1; i >= 0; i--)
		printf("%u", n & (i >> 1));
	printf("\n");
}

void set_bit2(unsigned int n,unsigned int i,unsigned int v)
{	
	unsigned int mask = v << i;
	unsigned int cn = clear_bit(n, i);
}

unsigned int get_bit2(unsigned int n,unsigned int i)
{
	unsigned int mask = 1 << i;
	return n % mask;
}

void get_bit(unsigned int n,unsigned int i)
{
	unsigned int result;
	n >> (i - 1);
	result = n % 2;
	printf("%u번째 비트는 %u", i, result);
}

unsigned int set_bit(unsigned int n, unsigned int i, unsigned int v)
{	
	unsigned int bi;
	n >> (i - 1);
	if((n % 2 == 0) && (v == 1));
	n += 1;
	n << (i - 1);
	return n;
}

int main()
{
	unsigned int n = 8;
	unsigned int i, v, rv;

	print_bit(n);
	printf("세팅할 비트의 위치와 값을 입력하시오 : \n");
	scanf(" % u % u", &i, &v);
	
	set_bit2(n, i, v);
	rv = get_bit2(n, i);

	if(rv != v) {
		printf("비트 세팅이 잘못되었습니다\n");
		return -1;
	}
	print_bit(n);
	return 0;
}
