#include <stdio.h>
#define TAX_RATE 0.2

int main(void)
{
	const int MONTHS = 12;
	int m_salary, y_salary;

	printf("월급을 입력하시오:");
	scanf("%d", &m_salary);
	y_salary = MONTHS * m_salary;
	printf("연봉은 %d입니다.", y_salary);
	printf("세금은 %d입니다.", y_salary*TAX_RATE);
	
	return 0;
}
