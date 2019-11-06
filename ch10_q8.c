#include <stdio.h>

float get_min(float array[], int len)
{
	float min = array[len - 1];
	for (int i = 0; i < len; i++)
	{
		if (array[i] < min)
			min = array[i];
	}
	return min;
}

float get_max(float array[], int len)
{
	float max = array[0];

	for (int i = 0; i < len; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return max;
}
			


int main()
{
	float max, min;
	float arr [] = { 1,2,3,4,5 };
	max = get_max(arr, 5);
	min = get_min(arr, 5);
	printf("최댓값:%f ,최솟값:%f", max, min);
}
