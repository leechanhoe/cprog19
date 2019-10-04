#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int num;

	srand((unsigned)time(NULL));
	num = 1 + rand() % 10;
	switch (num)
	{
		case 1:
		case 2:
		case 3:
			printf("주사위의 결과 : 1");
			break;
		case 4:
		case 5:
		case 6:
			printf("주사위의 결과 : 2");
			break;
		case 7:
			printf("주사위의 결과 : 3");
			break;
		case 8:
			printf("주사위의 결과 : 4");
			break;
		case 9:
			printf("주사위의 결과 : 5");
			break;
		case 10:
			printf("주사위의 결과 : 6");
			break;
			
		default:
			break;
	}

	return 0;
}
