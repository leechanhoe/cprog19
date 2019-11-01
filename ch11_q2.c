#include <stdio.h>

void get_min_max(int * arr, int * min, int * max)
{
	*min = arr[0];
	*max = arr[0];
	for(int i = 0;i < 5;i++)
	{
		if(*min > arr[i])
			*min = arr[i];
		if(*max < arr[i])
			*max = arr[i];
	}
}

int main()
{
	int arr[5] = {10, 2, 6, 8, 4};
	int min, max;

	get_min_max(arr, &min, &max);

	printf("min = %d max = %d\n", min, max);
}
