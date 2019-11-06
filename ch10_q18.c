#include <stdio.h>

int main()
{
	int ground[7][7] = {0};
	
	int boom1,boom2;

	printf("어디가 터짐?");
	scanf("%d %d", &boom1, &boom2);

	for(int i = 0;i < 3;i++) {
		for(int j = 0;j < 3;j++) {
			ground[boom1+i][boom2+j] = 1;
		}
	}
	for(int i = 1;i < 6;i++) {
		for(int j = 1;j < 6;j++) {
			printf("%d", ground[i][j]);
		}
		printf("\n");	
	}
}
