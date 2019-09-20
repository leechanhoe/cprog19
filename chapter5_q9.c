#include <stdio.h>

int main()
{
	double mid, final, assign, result;
	
	printf("중간 기말 과제 점수를 입력하시오.");
	scanf("%lf %lf %lf", &mid, &final, &assign);
	
	result = ((mid / 60 * 0.3) + (final / 70 * 0.3) + (assign / 50 *0.4)) * 100;

	printf("변환점수는 %lf 입니다.", result);
		
	return 0;	
}
