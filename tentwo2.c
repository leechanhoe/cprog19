#include <stdio.h>

int main()
{
	unsigned int num,num2;
	int one = 0,zero = 0,i = 0;
	printf("십진수:");
	scanf("%u", &num);
	num2 = num;
	
	unsigned int mask = 1 << 7;
	unsigned int mask2 = 1 << 7;
	printf("이진수:");
	
	((num & mask) == 0) ? printf("0") : printf("1");
	mask = mask >> 1;
	((num & mask) == 0) ? printf("0") : printf("1");
	mask = mask >> 1;
	((num & mask) == 0) ? printf("0") : printf("1");
	mask = mask >> 1;
	((num & mask) == 0) ? printf("0") : printf("1");
	mask = mask >> 1;
	((num & mask) == 0) ? printf("0") : printf("1");
	mask = mask >> 1;
	((num & mask) == 0) ? printf("0") : printf("1");
	mask = mask >> 1;
	((num & mask) == 0) ? printf("0") : printf("1");
	mask = mask >> 1;
	((num & mask) == 0) ? printf("0") : printf("1");
	printf("\n");
	
	while (i < 8)
	{
		if(num & mask2)
			one += 1;
 		mask2 = mask2 >> 1;
		i++;
	}
	printf("1의 개수 :%d \n", one);
	
	return 0;
}
