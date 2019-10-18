#include <stdio.h>

static int count = 100;

void dec_item(int n)
{
	count -= n;
}

void inc_item(int n)
{
	count += n;
}

void print_item(void)
{
	printf("%d\n", count);
}

int main()
{
	int opt, n;
	int end = -1;

	while(1)
	{
		printf("판매: 1, 입고 : 2, 재고확인 : 3, 종료 4\n");
		scanf("%d", &opt);
		if (opt < 3 && opt > 0) 
		{
			printf("수량을 입력하시오\n");
			scanf("%d", &n);
		}

		switch (opt) 
		{
		case 1:
			dec_item(n);
			break;
		case 2:
			inc_item(n);
			break;
		case 3:
			print_item();
			break;
		case 4:
			end = 1;
			break;
		default:
			printf("잘못 선택함\n");
		}
		if (end == 1)
			break;
	}
	return 0;
}
