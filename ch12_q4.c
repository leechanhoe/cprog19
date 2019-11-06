#include <stdio.h>

int main()
{
	char name[100];
	char address[100];
	printf("이름을 입력하시오:");
	gets(name, 100);
	printf("현재 거주하는 주소를 입력하시오:");
	gets(address, 100);
	puts(name);
	puts(address);
	return 0;
}
