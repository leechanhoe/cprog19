#include <stdio.h>

int main()
{
	int i, j = 1, result;
	
	printf("출력하고 싶은 단을 입력하시오:");
	scanf("%d", &i);
	
	while(j < 10)
	{
		printf("%d x %d = %d\n", i, j, i*j);
		j++;
	}
	return 0;
}
