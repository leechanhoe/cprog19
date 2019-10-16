#include <stdio.h>

int main()
{
	int arr[10] = { 3,8,1,1,2,5,2,4,3,6 };
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] + arr[j] >= 10)
				printf("arr[%d] = %d, arr[%d] = %d \n", i, arr[i], j, arr[j]);
		}
	}
	return 0;
}
