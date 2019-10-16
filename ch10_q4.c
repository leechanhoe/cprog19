#include <stdio.h>

float Min(float array[],int len)
{
	float min = array[len -1];
	for (int i = 0; i < len;i++)
	{
		if (array[i] < min)
			min = array[i];
	}
	return min;
}

int main()
{
	float arr[5] = { 14.5,18.7,15.2,16.78,19.2 };
	float arr2[5];
	for (int i = 0; i < 5; i++)
	{
		arr2[i] = Min(arr,5);

		for (int j = 0; j < 5; j++)
		{
			if (arr2[i] == arr[j])
				arr[j] = 100;
		}
	}

	for (int i = 0; i < 5; i++) {
		printf("%d등 %f\n",i+1, arr2[i]);
		
	}
	return 0;
}
