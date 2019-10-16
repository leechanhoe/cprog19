#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int arr[5];

	for (int i = 0; i < 5; i++)
	{
		srand((unsigned int)time(NULL));
		arr[i] = rand() % 101;
		for (int j = 0; j < i; j++) {
			if (arr[i] == arr[j])
			{
				i--;
				break;
			}
		}
	}

	for (int i = 0; i < 5; i++)
		printf("%d\n", arr[i]);
	return 0;
}
