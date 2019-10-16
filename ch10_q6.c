#include <stdio.h>

int main()
{
	int src[10000];
	int dest[10000];

	for (int i = 0; i < 10000; i++)
		src[i] = i;

	for (int i = 0; i < 10000; i++)
		dest[i] = src[9999-i];
	printf("%d", dest[1]);
}
