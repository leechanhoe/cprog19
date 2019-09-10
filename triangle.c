#include <stdio.h>

int main()
{
	int height, width;
	double  area;

	printf("삼각형의 높이를 입력하시오:");
	scanf("%d", &height);

	printf("삼각형의 밑변길이를 입력하시오:");
	scanf("%d", &width);
	
	area =(double)height * (double)width / 2 ;

	printf("삼각형의 넓이는 %lf 입니다.", area);
	
	return 0;
}
