#include <stdio.h>

int Sum(int * arr, int len)
{
	int sum = 0;
	for(int i = 0;i < len;i++)
		sum += *(arr + i);
	return sum;
}
int main()
{
	int arr[5] = {2, 4, 6, 8, 10};
	int * ptr = &arr;
	int sum;

	for(int i = 0;i < 5;i++)
		printf("%d\n", *(ptr + i)); 
	
	sum = Sum(arr, 5);
	printf("배열의 합:%d\n", sum);
}
