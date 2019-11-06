#include <stdio.h>

void get_sum(int arr[], int len)
{
	int arr2[10];
	arr2[0] = 0;
	for (int i = 1;i < len;i++)
		arr2[i] = arr[i] + arr[i-1];	
	for (int i = 0;i < len;i++)
		arr[i] = arr2[i];
}

int main()
{
	int arr[10];

	for(int i = 0;i < 10;i++)
		arr[i] = i;
	get_sum(arr,10);

	for (int i = 0;i < 10;i++)
		printf("%d\n", arr[i]);
}
