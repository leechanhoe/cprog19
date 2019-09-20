#include <stdio.h>

int main(void)
{
	int a,b;
	double result;
	
	printf("두 정수를 입력하세요:");
	scanf("%d %d", &a, &b); 
	
	result = (double)a / (double)b;
	
	printf("나눗셈 결과는 %lf 입니다.", result);
	
	return 0;
}
