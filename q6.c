#include <stdio.h>

int main()
{
	int num;

	printf("정수를 입력하세요:");
	scanf("%d", &num);

	((num % 2 == 0) ? printf("짝수입니다."):printf("홀수입니다."));
	return 0;
}
